#include<iostream>
using namespace std;
int main()
{
	bool matrix[100][100];
	int col[100],row[100];
	int odd_row,odd_col;
	int n;
	int xi,yi,x,y;
	while(cin>>n&&n!=0){
		odd_row=0,odd_col=0;
		for(yi=0;yi<n;yi++){
			row[yi]=0;
			for(xi=0;xi<n;xi++){
				cin>>matrix[yi][xi];
				row[yi]+=matrix[yi][xi];
			}
			if(row[yi]%2){
				odd_row++;
				y=yi+1;
			}
		}
		for(xi=0;xi<n;xi++){
			col[xi]=0;
			for(yi=0;yi<n;yi++)
				col[xi]+=matrix[yi][xi];
			if(col[xi]%2){
				odd_col++;
				x=xi+1;
			}
		}
		if(odd_row==0&&odd_col==0)	cout<<"OK\n";
		else if(odd_col==1&&odd_row==1)
			cout<<"Change bit ("<<y<<","<<x<<")\n";
		else	cout<<"Corrupt\n";
	}
	return 0;
}
