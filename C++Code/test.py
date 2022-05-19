def fun(x,y,L):
  if x == -5: 
    print(L)
    return 1
  L.append(x);
  
  return fun(x-1,y,L)

L = []
print(fun(5,5,L))