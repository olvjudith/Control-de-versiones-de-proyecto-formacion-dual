# -*- coding: utf-8 -*-
"""
Created on Sun Dec  8 14:53:54 2019

@author: DULCE
"""
#from Principal_DB_voice_ENFUNCIONES import CreateDB22
from MakeDataBase import DataBaseSteps
'''Nombre del archivo sin extención.'''
nameoutfile = 'Voice_Commands_DataBase'
Personas =18
TGPC =5*Personas #Total de grabaciones por comando
'''Genera una lista de audios que servirán como base para la correlación, 
el formato 'C'+ '*_P16_*.wav' debe ser deacuerdo al nombre.'''
AudiosBase = DataBaseSteps.ListaDeAudiosBase('C'+ '*_P16_G1.wav')

'''Genera la lista de audios a caracterizar,
el formato 'C'+ '*_P16_*.wav' debe ser deacuerdo al nombre.'''
Audios_a_Caracterizar = DataBaseSteps.ListaDeAudios('C'+ '*.wav')

'''Genera un nuevo archivo .csv con el nombe del archivo sin extención'''
DataBaseSteps.NewDB(nameoutfile)

'''Obtiene las caracteríasticas (FFT y Correlación) de la lista de audios
a caracterizar '''
DataBaseSteps.ObtainCharacteristis(Audios_a_Caracterizar,AudiosBase,TGPC,nameoutfile)