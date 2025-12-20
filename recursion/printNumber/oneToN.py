def printFun(n) :
    if n==1:
        print(n, end='\t')
        return
    # hypothesis
    printFun(n-1)
    # induction
    print(n, end='\t')

printFun(7)