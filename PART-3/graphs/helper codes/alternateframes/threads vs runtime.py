# -*- coding: utf-8 -*-
"""
Created on Tue Mar 30 19:29:38 2021

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

vec2=[fl("Using 1 threads.txt",5737),fl("Using 2 threads.txt",5737),fl("Using 3 threads.txt",5737),fl("Using 4 threads.txt",5737),fl("Using 5 threads.txt",5737)]
A=[]
B=[]


for i in range(0,len(vec2)):
	A.append(i+1)
	B.append(vec2[i][1]*0.000001)
    

x = A
y = B
  
plt.plot(x, y,marker='o',color='b')
plt.xlabel("No.of Threads")  # add X-axis label
plt.ylabel("Runtime in seconds")  # add Y-axis label
plt.title("Plot of No.of threads vs runtime")  # add title
plt.show()


#A=[1, 2, 3, 4, 5]
#[194.33439199999998, 183.288793, 182.028051, 181.227609, 187.827055]




