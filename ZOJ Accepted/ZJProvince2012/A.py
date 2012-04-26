import math
import sys

def origin(dis,time):
	res = 10.0
	if dis >=10:
		res += 7*2
		res += (dis-10)*3
	elif dis >=3:
		res += (dis-3)*2
	#res += math.floor((time*1.0)/5)*2
	res += (time*1.0)/5*2
	res += 1
	return math.floor(res + 0.5)

def new(dis,time):
	res = 11.0
	if dis >=10:
		res += 7*2.5
		res += (dis-10)*3.75
	elif dis>=3:
		res += (dis-3)*2.5
	#res += math.floor((time*1.0)/4)*2.5
	res += (time*1.0)/4*2.5
	return math.floor(res+0.5)

if __name__=='__main__':
	T = int(sys.stdin.readline())
	for i in range(T):
		line = sys.stdin.readline()
		arr = line.split()
		d = int(arr[0])
		t = int(arr[1])
		diff = new(d,t) - origin(d,t)
		print int(diff)
