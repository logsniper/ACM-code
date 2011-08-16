#include <cstdio>
#include <cmath>
#define Q 1E-9
struct _3DARRAY{
	double x,y,z;
	_3DARRAY(double _x,double _y,double _z)
	{
		x=_x,y=_y,z=_z;
	}
	_3DARRAY(){}
	double operator*(const _3DARRAY &b)
	{
		double ret;
		ret=x*b.x+y*b.y+z*b.z;
		return ret;
	}
};
inline _3DARRAY getN(_3DARRAY p1,_3DARRAY p2,_3DARRAY p3)
{
	_3DARRAY ret;
	_3DARRAY a(p1.x-p2.x,p1.y-p2.y,p1.z-p2.z);
	_3DARRAY b(p1.x-p3.x,p1.y-p3.y,p1.z-p3.z);
	if(a.x*b.y==b.x*a.y){
		ret.z=0;
		if(fabs(a.x)<Q)	{
			ret.y=0;
			ret.x=1;
		}
		else{
			ret.y=1;
			ret.x=-a.y/a.x;
		}
	}
	else{
		ret.z=1;
		double D=a.x*b.y-b.x*a.y;
		double Dx=-a.z*b.y+b.z*a.y;
		double Dy=-a.x*b.z+b.x*a.z;
		ret.x = Dx/D;
		ret.y = Dy/D;
	}
	return ret;
}

inline int side(_3DARRAY n,_3DARRAY p1,_3DARRAY p4)
{
	_3DARRAY a(p1.x-p4.x,p1.y-p4.y,p1.z-p4.z);
	double ret = n*a;
	if(fabs(ret)<Q)	return 0;
	else if(ret>0)	return 1;
	else		return -1;
}

inline double dist(_3DARRAY p1,_3DARRAY p2)
{
	double ret = sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
	return ret;
}

inline double area(_3DARRAY p1,_3DARRAY p2,_3DARRAY p3)
{
	double a=dist(p1,p2),b=dist(p2,p3),c=dist(p3,p1);
	double p=(a+b+c)/2;
	double ret=sqrt(p*(p-a)*(p-b)*(p-c));
	return ret;
}

_3DARRAY point[25];
int num;

int main()
{
	while(scanf("%d",&num)&&num>0){
		double res=0;
		for(int i=0;i<num;++i)
			scanf("%lf%lf%lf",&point[i].x,&point[i].y,&point[i].z);
		for(int i=0;i<num;++i)
			for(int j=i+1;j<num;++j)
				for(int k=j+1;k<num;++k){
					_3DARRAY n=getN(point[i],point[j],point[k]);
					bool big=false,small=false,zero=false;
					for(int t=0;t<num;++t){
						if(t==i||t==j||t==k)	continue;
						int sd=side(n,point[i],point[t]);
						if(sd==1)	big=true;
						else if(sd==0)	zero=true;
						else if(sd==-1)	small=true;
					}
					if(!zero&&(big^small)){
						res+=area(point[i],point[j],point[k]);
					}
				}
		int ans=(int)(res*10+5)/10;
		printf("%d\n",ans);
	}
	return 0;
}