import math
import sys

up = 'Jia, Yi, Bing, Ding, Wu, Ji, Geng, Xin, Ren, Gui'.split(', ')
down = 'Zi, Chou, Yin, Mao, Chen, Si, Wu, Wei, Shen, You, Xu, Hai'.lower().split(', ')

def get_year(year):
	if year < 0:
		year += 1
	dist = 0
	if year > 1924:
		dist = (year-1924)%60
	else:
		dist = 60 - (1924-year)%60
	return up[dist%10]+down[dist%12]

if __name__ == '__main__':
	lines = int(sys.stdin.readline())
	for i in range(lines):
		year = int(sys.stdin.readline())
		print get_year(year)
