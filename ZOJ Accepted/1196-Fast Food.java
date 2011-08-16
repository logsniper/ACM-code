import java.util.Scanner;

public class Main {
	final static int MAX = (1<<31)-1;
	static int n,k;
	static int d[];
	public static int getdist(int i,int j){
		if(d[i]>d[j])	return d[i]-d[j];
		else	return d[j]-d[i];
	}
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		for(int chain=1;;++chain){
			n = in.nextInt();
			k = in.nextInt();
			if(n==0)	break;
			d = new int[n];
			for(int i=0;i<n;++i){
				d[i] = in.nextInt();
			}
			//sumdist[i][j]表示j,j+1,...,n-1到i的距离和
			int sumdist[][] = new int[n][n];
			for(int i=0;i<n;++i){
				sumdist[i][n-1] = getdist(i,n-1);
				for(int j=n-2;j>=0;--j){
					sumdist[i][j] = sumdist[i][j+1] + getdist(i,j);
				}
			}
			//dp[i][j]表示i个仓库且最后一个位置在餐馆j时的最小路程和
			int dp[][] = new int[k+1][n];
			for(int j=0;j<n;++j){
				dp[1][j] = sumdist[j][0];
			}
			for(int i=2;i<=k;++i){
				for(int j=i-1;j<n;++j){
					int min = MAX;
					int pos = j;
					for(int r=j-1;r>=i-2;--r){
						while(getdist(r,pos)>=getdist(pos,j))	--pos;
						int tmp = dp[i-1][r] - sumdist[r][pos+1] + sumdist[j][pos+1];
//						System.out.println("fuck: "+i+" "+j+" "+r+" "+pos);
						if(min > tmp)	min = tmp;
					}
					dp[i][j] = min;
				}
			}
//			System.out.println("ok: "+dp[1][0]+" "+sumdist[0][1]+" "+sumdist[1][1]);
			int min = MAX;
			for(int i=k-1;i<n;++i){
				if(min > dp[k][i]){
					min = dp[k][i];
				}
			}
/*			for(int i=1;i<=k;++i){
				for(int j=0;j<n;++j){
					System.out.print(dp[i][j]+" ");
				}
				System.out.println();
			}*/
			System.out.println("Chain "+chain);
			System.out.println("Total distance sum = "+min);
			System.out.println();
		}
	}
}
