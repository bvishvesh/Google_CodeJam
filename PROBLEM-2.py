def par(t1,res,p):
    if p != '' and t1 != '':
        if int(p) > int(t1[0]):
            for k in range(int(p)-int(t1[0])):
                res = res + ')'
    if t1 == '':
        for l in range(int(p)):
            res = res + ')'
        return res
    if int(t1[0]) == 0:
        return par(t1[1:],res + t1[0],t1[0])
    if int(t1[0]) == 1:
        if p!= '':
            if int(p) == 0:
                res = res + '(' + t1[0]
            else:
                res = res + t1[0]
        else:
            res = res + '(' + t1[0]
        return par(t1[1:],res,t1[0])
    if int(t1[0]) > 1:
        if p!= '':
            for w in range(int(t1[0]) - int(p)):
                res = res + '('
            res = res + t1[0]
        else:
            for i in range(int(t1[0])):
                res = res + '('
            res = res + t1[0]
        return par(t1[1:],res,t1[0])
test = int(input())
for n in range(1,test+1):
    item=input()
    print('Case #{}: {}'.format(n,par(item,'','')))