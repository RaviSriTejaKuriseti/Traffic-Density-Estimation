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
vec.reverse()
vec1=[fl("Using resolution of 60 x 33 .txt",5737),fl("Using resolution of 120 x 67 .txt",5737),fl("Using resolution of 240 x 135 .txt",5737),
fl("Using resolution of 480 x 270 .txt",5737),fl("Using resolution of 960 x 540 .txt",5737),fl("Using resolution of 1920 x 1080 .txt",5737)]
A=[]
B=[]
C=[]
D=[]

for i in range(0,len(vec)):
	A.append(utilitypercent(vec[i]))
	B.append(vec[i][1]*0.000001)
    
for i in range(0,len(vec1)):
	C.append(utilitypercent(vec1[i]))
	D.append(vec1[i][1]*0.000001)
    
    
