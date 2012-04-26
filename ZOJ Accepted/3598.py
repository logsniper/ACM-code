import math
PI = 3.14159265359

def get_position(alpha,beta):
	h = math.sin(PI*beta/180)
	R = math.cos(PI*beta/180)
	x = R*math.cos(PI*alpha/180)
	y = R*math.sin(PI*alpha/180)
	return (x,y,h)

def projection_point(point,plane):
	'''
	point = (x,y,z)
	plane = (A,B,C,D)	means Ax + By + Cz + D = 0
	'''
	(A,B,C,D) = plane
	v_normal = (A,B,C)
	len_normal = math.sqrt(A*A+B*B+C*C)
	rp = None # rp : random poine
	if A != 0:
		rp = (-1.0*D/A,0,0)
	elif B != 0:
		rp = (0,-1.0*D/B,0)
	elif C != 0:
		rp = (0,0,-1.0*D/C)
	else:
		pass
	
	distance = sum([(rp[i]-point[i])*v_normal[i] for i in range(3)])*1.0/len_normal
	return tuple([point[i]+distance*v_normal[i]/len_normal for i in range(3)])

def cosineABC(a,b,c):
	''' a,b,c are all points'''
	plane = (b[0],b[1],b[2],-1)
	aa = projection_point(a,plane)
	cc = projection_point(c,plane)
	return sum([(aa[i]-b[i])*(cc[i]-b[i]) for i in range(3)])*1.0 / math.sqrt(sum([(aa[i]-b[i])*(aa[i]-b[i]) for i in range(3)])*sum([(cc[i]-b[i])*(cc[i]-b[i]) for i in range(3)]))

def gao(alpha,beta):
	(a,b,c) = tuple([get_position(alpha[i],beta[i]) for i in range(3)])
	return math.acos(cosineABC(a,b,c)) + math.acos(cosineABC(b,c,a)) + math.acos(cosineABC(c,a,b))

if __name__ == '__main__':
	import sys
	T = int(sys.stdin.readline())
	alpha = range(3)
	beta = range(3)
	for i in range(T):
		for j in range(3):
			line = sys.stdin.readline()
			arr = line.split()
			alpha[j] = float(arr[0])
			beta[j] = float(arr[1])
		print '%.2f' % (gao(alpha,beta)/PI*180)
