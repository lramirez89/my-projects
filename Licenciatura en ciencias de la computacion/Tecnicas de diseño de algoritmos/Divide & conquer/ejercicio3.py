def potLog(a,b):
    if b==0:
        return 1
    elif b==1:
        return a
    else:
        temp= potLog(a,b//2)
        if b%2 ==0:
            return temp*temp
        else:
            return temp*temp*a