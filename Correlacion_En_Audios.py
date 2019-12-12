# -*- coding: utf-8 -*-
"""
Created on Fri Dec  6 00:32:36 2019

@author: LORE
"""

# analiza correlacion entre dos muestras
# supone que señal01 es más corta que señal02
# propuesta:edelros@espol.edu.ec

import numpy as np
import scipy.io.wavfile as waves

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

# PROGRAMA
# INGRESO
# archivo01 = input('archivo de sonido 01:' )
# archivo02 = input('archivo de sonido 02:' )
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

archivo01 = 'C1_P1_G1.wav'
archivo02 = 'C1_P7_G5.wav'

print(correlacion(archivo01,archivo02))

# SALIDA
# unifica dimensiones de señal01 y señal02



