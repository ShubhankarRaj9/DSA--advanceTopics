def factorial(n) -> int:
    if n==0 :
        return 1
    res = n
    return (res*factorial(n-1))%100000000

ans = factorial(15)
print(ans)