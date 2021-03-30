# -*- coding: utf-8 -*-
"""
Created on Tue Mar 30 20:32:17 2021

@author: Lenovo
"""

import matplotlib.pyplot as plt

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

vec=[fl("skipping each 2 th frame.txt",5737),fl("skipping each 5 th frame.txt",5737),fl("skipping each 10 th frame.txt",5737),fl("skipping each 50 th frame.txt",5737),
fl("skipping each 100 th frame.txt",5737),fl("skipping each 500 th frame.txt",5737)]


A=[2,5,10,50,100,500]
B=[]




for i in range(0,len(vec)):
	B.append(vec[i][1]*0.000001)



x = A
y = B
  
plt.plot(x, y,marker='o',color='b')
plt.xlabel("Skipped Frame ")  # add X-axis label
plt.ylabel("Runtime in seconds")  # add Y-axis label
plt.title("Plot of k vs runtime")  # add title
plt.show()

print(B)
#B=[122.33691599999999, 68.520466, 49.714748, 33.547692, 30.382731, 30.740019999999998]





