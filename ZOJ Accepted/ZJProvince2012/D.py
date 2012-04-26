import sys

def common(str1,str2):
	str1.sort()
	str2.sort()

	res = []
	i = 0
	j = 0
	while i<len(str1) and j<len(str2):
		if str1[i] == str2[j]:
			res.append(str1[i])
			i += 1
			j += 1
		elif ord(str1[i])<ord(str2[j]):
			i += 1
		else:
			j += 1
	return res

def gao(strlist):
	if len(strlist)==1:
		res = list(strlist[0])
		res.sort()
	else:
		res = common(list(strlist[0]),list(strlist[1]))
	for i in range(2,len(strlist)):
		res = common(res,list(strlist[i]))
	return ''.join(res)

if __name__ == '__main__':
	T = int(sys.stdin.readline())
	for i in range(T):
		N = int(sys.stdin.readline())
		strlist = []
		for i in range(N):
			line = sys.stdin.readline()
			strlist.append(line[:-1])
		print gao(strlist)
