# -*- coding: utf-8 -*-
"""
Created on Tue Nov 12 22:46:46 2019

@author: alabe
"""

from sklearn.neural_network import MLPClassifier
import pandas as pd 
datos = pd.read_csv("voice.csv")#no contiene la clasificacion, solo muestras de las categorías
X0 = datos.ix[0]    #male
X1 = datos.ix[1]    #male
X2 = datos.ix[2]    #male
X3 = datos.ix[1300] #female
X4 = datos.ix[1301] #female
X5 = datos.ix[1302] #female


X_v = datos[["meanfreq","sd"]]
y_v =datos["label"]
clf = MLPClassifier(solver='lbfgs', alpha=1e-10,hidden_layer_sizes=(3,8, 6), random_state=1)
clf.fit(X_v, y_v) 

#X = [[0., 0.], [1., 1.],[2.,2.]]
#y = [0, 1, 2]
#clf = MLPClassifier(solver='lbfgs', alpha=1e-5,hidden_layer_sizes=(5, 2), random_state=1)
#clf.fit(X, y)      

                   
#MLPClassifier(activation='relu', alpha=1e-05, batch_size='auto',
#              beta_1=0.9, beta_2=0.999, early_stopping=False,
#              epsilon=1e-08, hidden_layer_sizes=(8, 6),
#              learning_rate='constant', learning_rate_init=0.001,
#              max_iter=200, momentum=0.9, n_iter_no_change=10,
#              nesterovs_momentum=True, power_t=0.5, random_state=1,
#              shuffle=True, solver='lbfgs', tol=0.0001,
#              validation_fraction=0.1, verbose=False, warm_start=False)