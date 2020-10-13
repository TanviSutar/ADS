def power(base,n,mod):
    if n == 1:
        return base%mod
    if n%2 == 0:
        var = power(base,n/2,mod)
        return (var%mod * var%mod)%mod
    else:
        return (base%mod * power(base,n-1,mod)%mod)%mod

print(power(2,10**4+7,1009))