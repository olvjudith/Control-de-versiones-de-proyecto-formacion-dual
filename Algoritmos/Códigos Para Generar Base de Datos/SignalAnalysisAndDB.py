# -*- coding: utf-8 -*-
"""
Created on Sun Dec  1 12:58:55 2019

@author: DULCE
"""
#import matplotlib.pyplot as plt
from scipy.io import wavfile as wav
import scipy.io.wavfile as waves
from scipy.fftpack import fft
import numpy as np
#import pickle
import glob
import csv
import pandas as pd

class SignalAnalysisDBSteps():
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        
    def nextpow2(L):
        N = 2
        while N < L: N = N * 2
        return N
    '''Esta funcion obtiene la potencia multiplo de 2 siguiente a L'''
    def audiolist(audioName):
        audioName = audioName
        audios=glob.glob(audioName)
        return audios
    '''Esta funcion lee todos los audios de un archivo'''
    def FFT(audios):
        fs,data = wav.read(audios) #lectura del audio  
        L =len(data)
        NFFT = 2^SignalAnalysisDBSteps.nextpow2(L)
        Y =fft(data,NFFT)/L
        YF=2*(abs(Y[1:NFFT]/2+1))
        YFlist = YF
        return YFlist
    '''Esta funcion saca la FFT de una lista de audios'''
    def Average(YFlist):
        Addition=0
        for element in YFlist:
            Addition += element
        averagef = Addition/len(YFlist)
        return averagef
    '''Esta funcion obtiene el promedio de una lista'''
    def Norma(averafef):
        Nom = np.linalg.norm(averafef)
        return Nom
    '''Esta funcion obtiene la norma'''
    def Correlacion(audioBase,AudioaComparar):
        audioBase = audioBase
        AudioaComparar = AudioaComparar
        # Un canal en caso de estereo
        def extraeuncanal(sonido):
            canales=sonido.shape
            cuantos=len(canales)
            canal = 0
            if (cuantos==1): # Monofónico
                uncanal=sonido[:]
            if (cuantos>=2): # Estéreo
                uncanal=sonido[:,canal]
            return(uncanal)
        def correlacion (audio1,audio2):        
            muestreo, sonido = waves.read(audio1)
            senal01 = extraeuncanal(sonido)      
            muestreo, sonido = waves.read(audio2)
            senal02 = extraeuncanal(sonido)        
            # PROCEDIMIENTO
            # Normaliza las señales
            amplitud = np.max(senal01)
            senal01 = senal01/amplitud
            senal02 = senal02/amplitud
            # Correlación para comparar
            correlacion = np.correlate(senal01,senal02, mode='same')
            n= np.linalg.norm(correlacion)
            return (n)       
        correlacionf=correlacion(audioBase,AudioaComparar)
        return correlacionf
    '''Esta funcion obtiene la correlación entre dos audios'''
    def createfilecsv(nameoutfile,data1,data2,data3,data4):
        name =nameoutfile  
        with open(name + '.csv', mode='w') as csv_file:
            fieldnames = ['Record_name', 'Norma', 'Correlacion','Comando']
            writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
            writer.writeheader()
        print("Archivo",name, "creado.")
        return
    '''Esta funcion genera un archivo .csv con los encabezados aquí descritos'''
    def addtocsv(nameoutfile,data1,data2,data3,data4):
        tamano = len(data1)
        with open(nameoutfile + '.csv', mode='a') as csv_file:
            fieldnames = ['Record_name', 'Norma', 'Correlacion','Comando']
            fd = csv.DictWriter(csv_file, fieldnames=fieldnames)
            for element in range(0,tamano):
                fd.writerow({'Record_name': data1[element], 'Norma': data2[element], 'Correlacion': data3[element], 'Comando': data4[element]}) 
        df = pd.read_csv(nameoutfile + '.csv')
        df.to_csv(nameoutfile +"2.csv",index=False)
        return
    '''Esta funcion abre un archivo .csv existente con los encabezados aquí descritos y añane una nueva fila de datos '''