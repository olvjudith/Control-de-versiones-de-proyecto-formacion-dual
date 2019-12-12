# -*- coding: utf-8 -*-
"""
Created on Fri Dec  6 17:42:27 2019

@author: DULCE
"""
from pydub import AudioSegment
import glob

def audiolist(audioName):
        audioName = audioName
        audios=glob.glob(audioName)
        return audios

audios =audiolist('C*.wav')
for elemento in audios:
    print (elemento)
    sound = AudioSegment.from_wav(elemento)
    sound = sound.set_channels(1)
    sound.export(elemento, format="wav")
print("termino")