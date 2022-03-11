def larger_remainder(a, b, c):
  '''
  Returns whether mod a, c is larger than mod b, c
    Parameters:
      a, b, c
    Returns:
      True or False
  Process:
    This algorithm calculates the remainder of a/c and b/c. the two remainders are then compared to tell whether remainder 1 is bigger than remainder 2.
  '''
  return a%c > b%c

def nth_digit(a, i):
  '''
  Returns the i'th digit of a, counting from right to left
  starting at 0.
    Parameters:
      a, i
    Returns:
      Integer at index i from right to left
  Process:
    This algorithm converts the number 'a' into an iterable instance called string. The location of digit 'i' is then calculated by subtracting i from the last index. Let 'loc' be the location of 'i'. The value of 's' index 'loc' is the answer. A 'loc' lower than 0 and a non integer value is handled only to reuse this function for the third function.
  '''
  s = str(a)
  loc = len(s)-1-i
  if (loc < 0): return -1
  if s[loc]<='9' and s[loc]>='0': return int(s[loc])
  return s[loc]

LETS = ['A','B','C','D','E','F']
def nth_digit_w_base(a, i, b):
  '''
  Returns the value of index i from right to left of the
  number N, where N is base b of a.
    Parameters:
      a, b, i
    Returns:
      Integer or Char
  Process:
    This algorithm repeatedly divides the 'a' by the base 'b'. The remainders are continuously added to a list. If a remainder is greater than 9, the coresponding letter is added to the list instead to accomodate for bases above 10. The list is then reversed and indexed with the second function to return the answer.
  '''
  if b<=1: return -1
  l = []
  while (a>0):
    r = a%b
    c = str(r)
    if r > 9:
      r -= 10
      c = LETS[r];
    l.append(c)
    a//=b
  
  s = ""
  for o in range(len(l)-1, -1, -1): s += str(l[o])
  return nth_digit(s,i)