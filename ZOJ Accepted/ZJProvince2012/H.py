import sys

if __name__ == '__main__':
	fin = sys.stdin
	T = int(fin.readline())
	for o in xrange(T):
		N = int(fin.readline())
		line = fin.readline()
		p = [float(v) for v in line.split()]
		p.append(-1)
		line = fin.readline()
		t = [int(v) for v in line.split()]
		t.append(t[-1]*3)
		tot = []
		maxw = []
		tot.append(p[0])
		maxw.append(t[0])
		maxavg = 0.0
		resw = 0
		if N ==1 or N > 1 and t[1]-t[0] > t[0]:
			maxavg = p[0]
			resw = t[0]

		for i in xrange(1,N):
			tot.append(tot[i-1]+p[i])
			if maxw[i-1] >= t[i]-t[i-1]:
				maxw.append(maxw[i-1])
			else:
				maxw.append(t[i]-t[i-1])
			nowavg = tot[i]/(i+1)
			if t[i+1]-t[i]>maxw[i] and maxavg < nowavg:
				maxavg = nowavg
				resw = maxw[i]
		print '%.6f %.6f' % (resw,maxavg)

