import sys

def swap(array,i,j,prob):
	x = array[i]*(1-prob) + array[j]*prob
	y = array[j]*(1-prob) + array[i]*prob
	array[i] = x
	array[j] = y

if __name__ == '__main__':
	fin = sys.stdin
	N = int(fin.readline())
	for i in xrange(N):
		line = fin.readline()
		arr = [int(v) for v in line.split()]
		(n,m,k,s) = arr
		if m == 0:
			print s
			continue
		prob = k*1.0/m
		array = [0.0 for j in range(n+1)]
		array[s] = 1e100
		for j in xrange(m):
			line = fin.readline()
			pair = [int(v) for v in line.split()]
			swap(array,pair[0],pair[1],prob)
		maxp = 0
		for j in xrange(n+1):
			if array[maxp] < array[j]:
				maxp = j
		print maxp
