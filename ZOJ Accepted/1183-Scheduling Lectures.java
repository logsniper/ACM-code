import java.util.Scanner;

public class Main {
	static int MAX = 1<<30;
	static int N,n,L,c;
	public static int getdi(int t){
		if(t==0)	return 0;
		else if(t<=10)	return -c;
		else	return (t-10)*(t-10);
	}
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		while(N-->0){
			int cas = 0;
			while(in.hasNextInt()){
				n = in.nextInt();
				if(n==0)	break;
				int[] t = new int[n+1];
				L = in.nextInt();
				c = in.nextInt();
				for(int i=1;i<=n;++i)
					t[i] = in.nextInt();
				//lecture[i][j]表示前i个topic且最后一个lecture剩余时间为j时的lecture数量
				int lecture[][] = new int[n+1][L+1];
				int di[][] = new int[n+1][L+1];
				for(int i=0;i<=n;++i){
					for(int j=0;j<=L;++j){
						lecture[i][j] = -1;
						di[i][j] = -1;
					}
				}
				lecture[0][L] = 1;
				di[0][L] = getdi(L);
				for(int i=1;i<=n;++i){
					for(int j=0;j<=L;++j){
						if(L-j>=t[i] && lecture[i-1][j+t[i]]!=-1){
							lecture[i][j] = lecture[i-1][j+t[i]];
							di[i][j] = di[i-1][j+t[i]] - getdi(j+t[i]) + getdi(j);
						}					
					}
					int minlec = MAX;
					int mindi = MAX;
					for(int j=0;j<=L;++j){
						if(lecture[i-1][j] == -1)	continue;
						if(lecture[i-1][j] < minlec){
							minlec = lecture[i-1][j];
							mindi = di[i-1][j];
						}
						else if(lecture[i-1][j] == minlec && mindi>di[i-1][j]){
							mindi = di[i-1][j];
						}
					}
					++minlec;
					mindi += getdi(L-t[i]);
					if(lecture[i][L-t[i]]==-1 || lecture[i][L-t[i]] > minlec){
						lecture[i][L-t[i]] = minlec;
						di[i][L-t[i]] = mindi;
					}
					else if(lecture[i][L-t[i]] == minlec && di[i][L-t[i]]>mindi){
						di[i][L-t[i]] = mindi;
					}
				}
	
				int minlec = MAX;
				int mindi = MAX;
				for(int j=0;j<=L;++j){
					if(lecture[n][j] == -1)	continue;
//					System.out.println(j+" "+lecture[n][j]+" "+di[n][j]);
					if(lecture[n][j] < minlec){
						minlec = lecture[n][j];
						mindi = di[n][j];
					}
					else if(lecture[n][j] == minlec && mindi>di[n][j]){
						mindi = di[n][j];
					}
				}
				if(cas!=0)	System.out.println();
				System.out.printf("Case %d:\n\n",++cas);
				System.out.println("Minimum number of lectures: "+minlec);
				System.out.println("Total dissatisfaction index: "+mindi);
			}
			if(N>0)	System.out.println();
		}
	}
}
