import numpy as np
t=int(input())
for a in range(t):
    m1=[]
    rowcount,colcount=0,0
    sumdia=0
    size1=int(input())
    for w in range(size1):
        item=list(map(int,input().split()))
        m1.append(item)
    mat=np.array(m1)
    for i in range(len(mat)):
        setr=set(mat[i])
        if(len(setr)!=len(mat[i])):
            rowcount=rowcount+1
        else:
            continue
    sumdia=np.trace(mat)
    mat2=mat.transpose()
    for b in range(len(mat2)):
        setc=set(mat2[b])
        if(len(setc)!=len(mat2[b])):
            colcount=colcount+1
        else:
            continue
    print("Case #{}: {} {} {}".format(a+1,sumdia,rowcount,colcount))