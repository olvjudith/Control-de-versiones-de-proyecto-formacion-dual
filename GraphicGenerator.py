# -*- coding: cp1252 -*-
import pandas as pd
import numpy as np
#import scipy.interpolate import interpld
import matplotlib.pyplot as plt


datos=pd.read_csv('Basemodificada.csv')
'''
Se lee un archivo .csv.
'''
#z=datos.ix[:,3]
numComando=datos.values[:,3] #Comandos
'''
Vector con los valores de la columna 3 del archivo .csv.
'''
correlacion=datos.values[:,2] #Correlacion
'''
Vector con los valores de la columna 2 del archivo .csv.
'''
norma=datos.values[:,1] #Norma
'''
Vector con los valores de la columna 1 del archivo .csv.
'''

colores=[]
etiqueta=[]
'''
Se inicializan variables como vector.
'''

x=datos.ix[:,2]
y=datos.ix[:,1]

coeficientes=np.polyfit(x,y,1)
polinomio=np.poly1d(coeficientes)
print (polinomio)
ys=polinomio(x)
'''
Se calcula el polinomio de la recta de regresión lineal.
'''

for i, numComando in enumerate(numComando):
    if numComando==1:
        colores.append('#ff0000')
        etiqueta.append('Comando 1')
        
    if numComando==2:
        colores.append('#00ff00')
        etiqueta.append('Comando 2')
        
    if numComando==3:
        colores.append('#0000ff')
        etiqueta.append('Comando 3')
    if numComando==4:
        colores.append('#ff00ff')
        etiqueta.append('Comando 4')
    if numComando==5:
        colores.append('#ffff00')
        etiqueta.append('Comando 5')
    if numComando==6:
        colores.append('#00ffff')
        etiqueta.append('Comando 6')
    if numComando==7:
        colores.append('#ff00AA')
        etiqueta.append('Comando 7')
    if numComando==8:
        colores.append('#00AAf0')
        etiqueta.append('Comando 8')
    if numComando==9:
        colores.append('#0f0ff0')
        etiqueta.append('Comando 9')
    if numComando==10:
        colores.append('#7BC8DD')
        etiqueta.append('Comando 10')
    if numComando==11:
        colores.append('#9B7FD4')
        etiqueta.append('Comando 11')

'''
En cada iteración del for se va llenando un vector con los colores seleccionados
de acuerdo a cada comando.
'''

for i in range(0,814):
    plt.plot(correlacion[i],norma[i],color=colores[i],marker='o',label='etiquetados')
    plt.plot(x,ys)
'''
En cada iteración del for se selecciona cada dato de los vectores obtenidos
anteriormente para ser graficados.
Se grafica la dispersión de los datos y la recta
'''
#plt.legend('Comando811')
plt.ylabel('Norma')
plt.xlabel('Correlacion')
plt.show()
'''
Se asignas nombres a los ejes y se muestra la gráfica.
'''





