# -*- coding: utf-8 -*-
import pyaudio
import wave
import time
import pyaudio
import wave

'''
ESTE PROGRMA GRABA UN AUDIO DE 10s Y LO GUARDA.
'''

FORMAT=pyaudio.paInt16
CHANNELS=1
RATE=44100
CHUNK=1024
duracion=3
C=11
G=5
Total_g = G*C
'''
Se definen los parámetros.
'''
P=input("Ingresa el # de persona: ")
'''
Ingreso del número de persona a grabar.
'''
  
for comando in range(1,C+1):
    for grabacion1 in range (1,G+1):
        name="C" + str(comando) + "_" + "P" + str(P) + "_" + "G" + str(grabacion1)
        archivo= name + ".wav"
        print(name)
        
        audio=pyaudio.PyAudio()
        '''
        Se inicia "pyaudio"
        '''
    
        
        stream=audio.open(format=FORMAT,channels=CHANNELS,
                          rate=RATE, input=True,
                          frames_per_buffer=CHUNK)
        time.sleep(3)
        print("Comienza a hablar cuando veas la leyenda _grabando_ ")
        time.sleep(2)
        print("grabando...")
        frames=[]       
        for i in range(0, int(RATE/CHUNK*duracion)):
            data=stream.read(CHUNK)
            frames.append(data)
        print("grabación terminada")
        print('\n')
        '''
        Se inicia grabación.
        '''
        stream.stop_stream()
        stream.close()
        audio.terminate()
        
        '''
        Se detiene grabación.
        '''
        
        waveFile = wave.open(archivo, 'wb')
        waveFile.setnchannels(CHANNELS)
        waveFile.setsampwidth(audio.get_sample_size(FORMAT))
        waveFile.setframerate(RATE)
        waveFile.writeframes(b''.join(frames))
        waveFile.close()
        '''
        Se crea y se guarda el archivo de audio.
'''
ciclo for grabacion in range (1,Total_g)
'''
