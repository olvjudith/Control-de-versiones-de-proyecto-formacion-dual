# -*- coding: cp1252 -*-

from SignalAnalysisAndDB import SignalAnalysisDBSteps
Caract1 = []
Caract2A = []
Caract2B = []
Caract3 = []
Caract4 = []
'''

'''

class DataBaseSteps():
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
    
    def ListaDeAudiosBase(NameAudioBase):
        audioBase= SignalAnalysisDBSteps.audiolist(NameAudioBase) #selecciona el audio base para la correlación
        return audioBase
    '''
    Esta función hace una lista de audios que servirán como base para hacer comparaciones con los audios de la base de datos.
    Argumentos:
        NameAudioBase(String): Nombre del audio base.
    Retornos:
        audioBase(List):  Retorna la lista de los audios base.
    '''
    
    def ListaDeAudios(NameAudios):
        Audios = SignalAnalysisDBSteps.audiolist(NameAudios)
        return Audios
    '''
    Esta función hace una lista de audios.
    Argumentos:
        NameAudios(String): Nombres para los audios.
    Retornos:
        Audios(List): Lista con los audios.
    '''
    
    def CambioBase(audioBase,CambioAudioBase):
        audioBase2 = audioBase[CambioAudioBase]                  
        return audioBase2
    '''
    Esta función permite seleccionar ciertos elementos de una lista general de audios.
    Argumentos:
        audioBase(Lits): Lista de audios.
        CambioAudioBase(int): Elemento de la lista que se quiere seleccionar.
    Retornos:
        audioBase2(List): Elemento de la lista que se tomará como audio base.
    '''
    def NewDB(nameoutfile):
        SignalAnalysisDBSteps.createfilecsv(nameoutfile,Caract1,Caract2B,Caract3,Caract4)
        return
    '''
    Esta función genera un archivo con extensión .csv en la misma dirección en la que se encuentre éste código.
    Argumentos:
        nameoutfile(String): Nombre del archivo .csv (no se escribe la extensión) que se quiere generar.
    Retornos:
        Sin valores de retorno.
    '''
    def ObtainCharacteristis(Audios,audioBase,Ngrabporcomando,nameoutfile):
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
    '''
    Esta función obtiene las características FFT y Correlación de cada señal de audio.
    
    Argumentos:
        Audios(List): Lista de audios que se van a caracterizar.
        audioBase(List): Lista de audios base para obtener la correlación.
        Ngrabporcomando(List): Etiqueta para elemento de la base de datos.
        nameoutfile(String): Nombre del archivo .csv en donde se guardarán las características. (Se escribe el nombre sin extensión).
    Retorno:
        Sin valores de retorno.
    '''
