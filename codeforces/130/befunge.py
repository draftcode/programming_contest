x = [
	['~','9','2','*','5','*','6','+','-','.','2','5','*',',','v'],
	['^','~',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','<']
	]

import os.path
import random

def read2array(file):
	if not os.path.isfile(file): return 0
	A = [] #Array
	main = open(file, "r")
	try: size = int(main.readline())
	except: size = 60
	while not (A[len(A)-1]=''):
		A.append(main.readline())
		A[(len(A)-1)].pop()		
def bef(array):
	A = array
	pointer = 0,0
	stringmode = False
	direction = 0,1
	s = [] #stack
	x = A[pointer[0]][pointer[1]]
	digits = [0,1,2,3,4,5,6,7,8,9]

	if x=='"': stringmode = not stringmode
	elif stringmode: s.append(ord(x))
	elif x=='+': s.append(s.pop() + s.pop())
	elif x=='-': s.append(s.pop() - s.pop())
	elif x=='*': s.append(s.pop() * s.pop())
	elif x=='/': s.append(s.pop() / s.pop()))
	elif x=='%': s.append(s.pop() % s.pop())
	elif x=="'": s.append(s.pop() > s.pop())
	
	elif x=='>': direction = 0,1
	elif x=='<': direction = 0,-1
	elif x=='^': direction = -1,0
	elif x=='v': direction = 1,0
	elif x=='V': direction = 1,0
	
	elif x=='?':
		d = random.randint(1,4)
		elif d==1: direction =  0, 1
		elif d==2: direction =  0,-1
		elif d==3: direction = -1, 0
		elif d==4: direction =  1, 0
	
	elif x=='!': s.append(not s.pop())
	elif x=='_': direction = 0,(-1+2*int(not s.pop()))
	elif x=='|': direction = (-1+2*int(not s.pop())),0
	try: if digits.count(int(x))>0: stack.append(int(x))
	except: pass
