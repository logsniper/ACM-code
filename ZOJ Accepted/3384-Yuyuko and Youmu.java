import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int n;
		int need[],serve[],now[];
		while(in.hasNextInt()){
			n = in.nextInt();
			need = new int[n];
			serve = new int[n];
			now = new int[n];
			for(int i=0;i<n;++i){
				need[i] = in.nextInt();
			}
			for(int i=0;i<n;++i){
				serve[i] = in.nextInt();
			}
			boolean res = true;
			for(int i=0;i<n;++i){
				now[i] = need[i]<serve[i]?need[i]:serve[i];
				if(need[i]>serve[i]){
					int left = need[i] - serve[i];
					for(int j=i-1;j>=0&&left>0;--j){
						if(now[j]<serve[j]){
							if(left > serve[j] - now[j]){
								left -= serve[j] - now[j];
								now[j] = serve[j];
							}
							else{
								now[j] += left;
								left = 0;
							}
						}
					}
					if(left > 0){
						res = false;
						break;
					}
				}
			}
			if(res){
				System.out.print(now[0]);
				for(int i=1;i<n;++i)
					System.out.printf(" %d",now[i]);
				System.out.println();
			}
			else{
				System.out.println("Myon");
			}
		}
	}
}
