import java.util.Scanner;
import java.math.*;

public class Main {
	public static void main(String[] args){
		int T;
		Scanner in = new Scanner(System.in);
		T = in.nextInt();
		int sum;
		while(T-->0){
			sum = in.nextInt();
			int whiteOdd = 0, whiteEven = 0;
			for(int i=0;i<sum;++i){
				int t = in.nextInt();
				if(t == 0){
					if(i%2 == 0 )	whiteEven ++;
					else	whiteOdd ++;
				}
			}
//			System.out.println(whiteEven+" "+whiteOdd);
			if(sum %2 == 1)	System.out.println("YES");
			else if(Math.abs(whiteEven-whiteOdd) <= 1)
				System.out.println("YES");
			else	System.out.println("NO");
		}
	}
}
