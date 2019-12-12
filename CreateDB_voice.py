# -*- coding: utf-8 -*-
"""
Created on Sun Dec  1 12:58:55 2019

@author: DULCE
"""
import matplotlib.pyplot as plt
from scipy.io import wavfile as wav
from scipy.fftpack import fft
import numpy as np
import pickle
import glob
import csv
import pandas as pd

class CreateDB():
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        
    def nextpow2(L):
        N = 2
        while N < L: N = N * 2
        return N
    
    def audiolist(audioName):
        audioName = audioName
        audios=glob.glob(audioName)
        return audios
    
    def FFT(audios):
        YFlist = []
        audioslist = audios
        for element in audioslist:
            fs,data = wav.read(element) #lectura del audio 
            L =len(data)
            NFFT = 2^CreateDB.nextpow2(L)
            Y =fft(data,NFFT)/L
            YF=2*(abs(Y[1:NFFT]/2+1))
            YFlist.append(YF)
        return YFlist
    
    def Average(YFlist):
        Addition=0
        for element in YFlist:
            Addition += element
        averagef = Addition/len(YFlist)
        return averagef
    
    def Norma(averafef):
        Nom = np.linalg.norm(averafef)
        return Nom
    
    def filecsv(nameoutfile,data1,data2,data3):
        name =nameoutfile
        data1 = data1      
        with open(name, mode='w') as csv_file:
            fieldnames = ['record_name', 'Norma', 'Cob']
            writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
            writer.writeheader()
            for element,elNorm,elCob in range(data1,data2,data3):
                writer.writerow({'record_name': element, 'Norma': elNorm, 'Cob': elCob}) 
        df = pd.read_csv(name)
        df.to_csv("VoiceBD2.csv",index=False)  