f=open("data.txt")
L=f.readlines()
h=open("data.csv","w")
for i in range(0,len(L)):
	s=L[i].split()
	t=''
	for j in range(0,2):
		t+=s[j]+','
	t+=s[2]+"\n"
	h.write(t)
h.close()
f.close()

