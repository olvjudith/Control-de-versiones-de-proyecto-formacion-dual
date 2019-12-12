# -*- coding: utf-8 -*-
"""
Created on Sun Dec  1 15:16:13 2019

@author: DULCE
"""
#from CreateDB_voice_2 import CreateDB
from SignalAnalysisAndDB import SignalAnalysisDBSteps
Caract1 = []
Caract2A = []
Caract2B = []
Caract3 = []
Caract4 = []

#***nameoutfile= 'PruebaChida' #sin extencion
#audioBase= ['C1_P16_G1.wav','C2_P16_G1.wav']
#***audioBase= CreateDB.audiolist('C'+ '*_P16_G1.wav') #selecciona el audio base para la correlación
#print(audioBase2)
#***Audios = CreateDB.audiolist('C'+ '*_P1_*.wav')
#print("AUDIOS",Audios)
#print("AUDIO BASE ",audioBase)

#class CreateDB22():
class DataBaseSteps():
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
    
    def ListaDeAudiosBase(NameAudioBase):
        audioBase= SignalAnalysisDBSteps.audiolist(NameAudioBase) #selecciona el audio base para la correlación
        return audioBase
    
    def ListaDeAudios(NameAudios):
        Audios = SignalAnalysisDBSteps.audiolist(NameAudios)
        return Audios
    
    def CambioBase(audioBase,CambioAudioBase):
        audioBase2 = audioBase[CambioAudioBase]                  
        return audioBase2
    "Esta funcion solo trabaja en este archivo"
    def NewDB(nameoutfile):
        SignalAnalysisDBSteps.createfilecsv(nameoutfile,Caract1,Caract2B,Caract3,Caract4)
        return
    def ObtainCharacteristis(Audios,audioBase,Ngrabporcomando,nameoutfile,):
        CambioAudioBase = 0
        grabporcomando = Ngrabporcomando
        for elemento in Audios:
            #print (elemento)    
            audioBase2 = DataBaseSteps.CambioBase(audioBase,CambioAudioBase)    
            totalbases = (len(audioBase))-1
            grabporcomando = grabporcomando-1
            if grabporcomando==0 and CambioAudioBase<totalbases:
                CambioAudioBase = CambioAudioBase+1 
                grabporcomando = Ngrabporcomando
            
            Caract1.append(elemento)
            Caract2A.append(SignalAnalysisDBSteps.FFT(elemento))
            Caract3.append(SignalAnalysisDBSteps.Correlacion(audioBase2,elemento))
            print("Audio Base",audioBase2,"ELEMENTO:",elemento)
            if not '_' in elemento[2]:
                Caract4.append(elemento[1]+elemento[2])
            else:
                Caract4.append(elemento[1])
        for elemento in Caract2A:
            print (elemento)
            Caract2B.append(SignalAnalysisDBSteps.Norma(elemento))
        SignalAnalysisDBSteps.addtocsv(nameoutfile,Caract1,Caract2B,Caract3,Caract4)
        return 
