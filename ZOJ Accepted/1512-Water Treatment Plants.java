import java.math.BigInteger;
import java.util.Scanner;
public class Main{
	static final int maxn = 104;
	static BigInteger dp[][] = new BigInteger[maxn+1][3];
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		dp[1][0] = BigInteger.valueOf(0);
		dp[1][1] = BigInteger.valueOf(1);
		dp[1][2] = BigInteger.valueOf(1);
		for(int i=2;i<=maxn;++i){
			dp[i][0] = dp[i-1][0].add(dp[i-1][1]);
			dp[i][1] = dp[i-1][0].add(dp[i-1][1]).add(dp[i-1][2]);
			dp[i][2] = dp[i][1];
		}
		while(in.hasNextInt()){
			int n = in.nextInt();
			System.out.println(dp[n][0].add(dp[n][1]));
		}
	}
}