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
    '''
    Esta función obtiene la potencia multiplo de 2 siguiente a L.
    Argumentos:
        L(int)
    Retornos:
        N(int): Potencia multiplo de 2.
    '''
    def audiolist(audioName):
        audioName = audioName
        audios=glob.glob(audioName)
        return audios
    '''
    Esta función lee todos los audios de un archivo.
    Argumentos: 
        audioName(String): Nombre de la carpeta que almacena los archivos .wav. *********
    Retornos: 
        audios(List): Retorna la lista de archivos que contiene la carpeta seleccionada.
    '''
    def FFT(audios):
        fs,data = wav.read(audios) #lectura del audio  
        L =len(data)
        NFFT = 2^SignalAnalysisDBSteps.nextpow2(L)
        Y =fft(data,NFFT)/L
        YF=2*(abs(Y[1:NFFT]/2+1))
        YFlist = YF
        return YFlist
    '''
    Esta función calcula la Transformada Rápida de Fourier(Fast Fourier Transform, FFT) de una lista de audios.
    Argumentos:
        audios(List): Lista señales a las que se le aplicará la FFT.
    Retornos:
        YFlist(List): Lista de valores para cada señal después de haberse aplicado la FFT.
    '''
    def Average(YFlist):
        Addition=0
        for element in YFlist:
            Addition += element
        averagef = Addition/len(YFlist)
        return averagef
    '''
    Esta función obtiene el promedio de una lista.
    Argumentos: 
        YFlist(List): Lista de valores para cada señal después de haberse aplicado la FFT.
    Retornos:
        averagef(List): Promedio de cada valor de  la lista de señales.
    '''
    def Norma(averafef):
        Nom = np.linalg.norm(averafef)
        return Nom
    '''
    Esta funcion obtiene la norma.
    Argumentos
        averafef(vector)
    Retornos:
        Nom(float): Norma del vector.
    '''
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
        '''
        Esta función extrae un canal.
        Argumentos: 
            sonido(List): archivo .wav
        Retornos:
            uncanal(List): archivo .wav de un canal.
        '''
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
        '''
        Esta función calcula la correlación entre dos señales.
        Argumentos:
            audio1(String): Señal base para la correlación.
            audio2(String): Señal a comparar con la señal base.
        Retornos:
            n(Float): Valor de la correlación entre las dos señales.
        '''
        correlacionf=correlacion(audioBase,AudioaComparar)
        return correlacionf
    '''
    Esta funcion obtiene la correlación entre dos audios.
    Argumentos:
        audioBase(String): Señal base para la correlación.                        *********checar en el blog
        AudioaComparar(String): Señal a comparar con la señal base.
    Retornos:
        correlacionf(Float): Valor de la correlación entre las dos señales.
    '''
    def createfilecsv(nameoutfile,data1,data2,data3,data4):
        name =nameoutfile  
        with open(name + '.csv', mode='w') as csv_file:
            fieldnames = ['Record_name', 'Norma', 'Correlacion','Comando']
            writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
            writer.writeheader()
        print("Archivo",name, "creado.")
        return
    '''
    Esta funcion genera un archivo .csv en la misma dirección que tiene el código.
    Argumentos:
        nameoutfile(String): Nombre que tendrá el archivo (sin extensión).
        data1(List): Datos de la columna 1 para el archivo.
        data2(List): Datos de la columna 2 para el archivo.
        data3(List): Datos de la columna 3 para el archivo.
        data4(List): Datos de la columna 4 para el archivo.
    Return:
        Sin valores de retorno.
    '''
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
    '''
    Esta funcion abre un archivo .csv existente con los encabezados aquí descritos y añane una nueva fila de datos.
    nameoutfile(String): Nombre que tendrá el archivo (sin extensión).
        data1(List): Datos de la columna 1 para el archivo.
        data2(List): Datos de la columna 2 para el archivo.
        data3(List): Datos de la columna 3 para el archivo.
        data4(List): Datos de la columna 4 para el archivo.
    Return:
        Sin valores de retorno.
    '''
