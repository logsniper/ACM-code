import java.util.Scanner;

class Primes{
	public int prime[],num;
	Primes(){
		num = 0;
		prime = new int[4000];
	}
	boolean isPrime(int n){
		for(int i=0;i<num;++i){
			if(n%prime[i] == 0)	return false;
		}
		return true;
	}
	void getPrimes(){
		for(int k=2;k<31650;++k){
			if(isPrime(k)){
				prime[num++] = k;
			}
		}
//		System.out.println(num);
	}
}

class Num{
	int value;
	int facval[],facnum,tot;
	Num(int value){
		this.value = value;
	}
	public int getfac(Primes pp){
		facval = new int[100];
		facnum = 0;
		tot = 0;
		int n = value;
		int q = (int)Math.sqrt(n);
		for(int k=0;pp.prime[k]<=q;++k){
			int p = pp.prime[k];
			if(n%p != 0)	continue;
			while(n%p == 0){
				++tot;
				facval[facnum]++;
				n/=p;
			}
			facnum++;
			q = (int)Math.sqrt(n);
		}
		if(n!=1){
			++tot;
			facval[facnum++] = 1;
		}
		return tot;
	}
	public long result(){
		long ret = 1;
		int tot=1;
		for(int i=0;i<facnum;++i){
			for(int j=1;j<=facval[i];++j){
				ret *= (long)tot;
				ret /= (long)j;
				++tot;
			}
		}
		return ret;
	}
}

public class Main {
	static long dp[];
	public static void main(String[] args){
		dp = new long[100];
		dp[1]=1;
		dp[2]=1;
		for(int i=3;i<100;++i){
			dp[i] = 0;
			for(int j=1;j<i;++j)
				dp[i] += dp[j]*dp[i-j];
		}
		Scanner in = new Scanner(System.in);
		Primes pp = new Primes();
		pp.getPrimes();
		while(in.hasNextInt()){
			Num n = new Num(in.nextInt());
			int tot = n.getfac(pp);
			System.out.println(dp[tot]*n.result());
		}
	}
}

