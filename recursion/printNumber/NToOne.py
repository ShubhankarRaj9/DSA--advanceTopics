def printFun(n):
    if n==1:
        print(n)
        return 
    print(n, end='\t')
    printFun(n-1)

printFun(7)