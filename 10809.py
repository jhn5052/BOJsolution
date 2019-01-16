S = input()
al = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
alnum = []
n = 0
for i in range(26):
    n = S.find(al[i])
    alnum.append(n)
for i in range(26):
    print(alnum[i],end=' ')
    
