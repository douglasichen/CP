# PYTHON
N = int(input())
Q = int(input())
V = []

for i in range(N):
	V.append(int(input()))

psa = [V[0]]
for i in range(1,N):
	psa.append(psa[i-1]+V[i])

for i in range(Q):
	L = int(input())
	R = int(input())
	rem = 0
	if (L>0): rem = psa[L-1]
	ans = psa[R]-rem
	print(ans)