# -*- coding: utf-8 -*-
"""
Created on Tue Mar 30 19:29:38 2021

@author: Lenovo
"""

import matplotlib.pyplot as plt
import math
  

def ut(L,M):
	ans=0
	n=len(L[0])
	for i in range(0,n):
		ans+=(L[0][i]-M[0][i])**2
	return ans/n

def fl(s,n):
	f=open(s)
	A=f.readlines()
	B=[0.0]*n
	for i in range(1,len(A)-1):
		st=A[i].split()
		x=int(st[0])
		y=float(st[1])
		B[x-1]=y
	x2=A[len(A)-1].split()
	t=int(x2[4])

	return (B,t)


def basedensity():
    f=open("base.txt")
    S=f.readlines()
    sum=0
    for i in range(1,len(S)-1):
        st=S[i].split()
        y=float(st[1])
        sum+=y
    return sum

def utilitypercent(L):
    x=ut(L,fl("base.txt",5737))
    return (1-x)*100


X=fl("base.txt",5737)


vec1=[fl("Using resolution of 60 x 33 .txt",5737),fl("Using resolution of 120 x 67 .txt",5737),fl("Using resolution of 240 x 135 .txt",5737),
fl("Using resolution of 480 x 270 .txt",5737),fl("Using resolution of 960 x 540 .txt",5737),fl("Using resolution of 1920 x 1080 .txt",5737)]



C=[1980,8040,32400,129600,518400,2073600]
C1=list(map(math.log,C))
D=[]



for i in range(0,len(vec1)):
	D.append(vec1[i][1]*0.000001)
    

x = C1
y = D
  
plt.plot(x, y,marker='o',color='b')
plt.xlabel("Logarithm of X x Y")  # add X-axis label
plt.ylabel("Runtime in seconds")  # add Y-axis label
plt.title("Plot of log(XY) vs runtime")  # add title
plt.show()

#C1=[7.590852123688581, 8.992184362173012, 10.38591370178042, 11.772208062900312, 13.158502424020202, 14.544796785140093]
#D=[196.950075, 199.38872899999998, 201.61550699999998, 211.288206, 247.88394, 421.86749]


