def q2(L,i=0):
  N=len(L)
  if (i==N//2):
    print(L[N-1])
    return
  print(L[N//2+i],end=" ")
  print(L[N//2-i-1],end=" ")
  q2(L,i+1)

L = [1,2,3,4,5,6,7,8,9,10,11]
q2(L)