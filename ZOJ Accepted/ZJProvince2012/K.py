import sys

if __name__ == '__main__':
	T = int(sys.stdin.readline())
	for i in range(T):
		line = sys.stdin.readline()
		arr = line.split()
		print '%s will survive' % arr[1]
