import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

class Node{
	public int mod;
	public String value;
	public Node(int m,String v){
		mod = m;
		value = v;
	}
}

public class Main {
	static boolean appeared[] = new boolean[5000];
	static int n,m;
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		while(in.hasNextInt()){
			n = in.nextInt();
			for(int i=0;i<n;++i){
				appeared[i] = false;
			}
			m = in.nextInt();
			int digits[] = new int[m];
			for(int i=0;i<m;++i){
				digits[i] = in.nextInt();
			}
			if(n==0){
				System.out.println(0);
				continue;
			}
			Arrays.sort(digits);
			List<Node> q = new LinkedList<Node>();
			for(int i=0;i<m;++i){
				if(appeared[digits[i]%n] || 0==digits[i]) continue;
				Node node = new Node(digits[i]%n,String.valueOf((char)('0'+digits[i])));
				q.add(node);
				appeared[digits[i]%n] = true;
			}
			String res = "0";
			while(!q.isEmpty()){
				Node head = q.get(0);
				q.remove(0);
				if(head.mod == 0){
					res = head.value;
					break;
				}
				for(int i=0;i<m;++i){
					if(appeared[(head.mod*10+digits[i])%n])	continue;
					Node node = new Node((head.mod*10+digits[i])%n,head.value+String.valueOf((char)('0'+digits[i])));
					q.add(node);
					appeared[(head.mod*10+digits[i])%n] = true;
				}
			}
			System.out.println(res);
		}
	}
}
