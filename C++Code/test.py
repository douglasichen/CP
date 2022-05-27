
import copy

H=W=n=cnt=0

def print2d(a):
  for rw in a:
    for i in rw: print(i,end=" ")
    print()
  print()

def dfs1(pos,f):
  global cnt,H,W
  f[pos[0]][pos[1]]=1
  if (pos[0]==H-1 and pos[1]==W-1):
    f[H-1][W-1]="◘"
    print2d(f)
    cnt+=1
  if (pos[0]<H-1):
    f[pos[0]][pos[1]]="↓"
    dfs1((pos[0]+1,pos[1]),copy.deepcopy(f))
  if (pos[1]<W-1):
    f[pos[0]][pos[1]]="→"
    dfs1((pos[0],pos[1]+1),copy.deepcopy(f))


dirs=[[1,1],[-1,-1],[-1,1],[1,-1]]
def dfs2(pos,f):
  global cnt,n,dirs
  if (pos[0]==n-1 and pos[1]==n-1):
    f[n-1][n-1]="◘"
    print2d(f)
    cnt+=1
  for dir in dirs:
    nxt=(pos[0]+dir[0],pos[1]+dir[1])
    if (dir[0]==1 and dir[1]==1): f[pos[0]][pos[1]]="↘"
    elif (dir[0]==-1 and dir[1]==-1): f[pos[0]][pos[1]]="↖"
    elif (dir[0]==-1 and dir[1]==1): f[pos[0]][pos[1]]="↗"
    else: f[pos[0]][pos[1]]="↙"
    if (nxt[0]>=0 and nxt[0]<n and nxt[1]>=0 and nxt[1]<n and f[nxt[0]][nxt[1]]=="•"): dfs2(nxt,copy.deepcopy(f))

def dfs2_it():
  print("Very hard to make an elegant solution...\n")
  

def newD(h,w):
  d=[]
  for y in range(h):
    tmp=[]
    for x in range(w):
      tmp.append("•")
    d.append(tmp)
  return d

print("Q1:")
print("H: ",end="")
H=int(input())+1
print("W: ",end="")
W=int(input())+1
dfs1((0,0),newD(H,W))
print("There are",cnt,"different paths.")

print("Q2:")
cnt=0
print("(iterative) n: ",end="")
n=int(input())+1
dfs2_it()
# print("There are ",cnt," different paths.")

cnt=0
print("(recursive) n: ",end="")
n=int(input())+1
dfs2((0,0),newD(n,n))
print("There are",cnt,"different paths.")