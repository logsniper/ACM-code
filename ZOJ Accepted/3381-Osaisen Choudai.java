import java.util.ArrayList;
import java.util.Scanner;

class Node{
	public int l,r;
	public int max;
	public Node lc,rc;
	public void initNode(int l, int r){
		this.l = l;
		this.r = r;
		max = 0;
		lc = null;
		rc = null;
	}
}

class Tree{
	private static int MAXN = 50000;
	private static ArrayList<Node> tree = new ArrayList<Node>(MAXN*3+10);
	public Tree(int n){
		if(tree.size() == 0){
			for(int i=0;i<=MAXN*3;++i){
				tree.add(new Node());
			}
		}
		createTree(1,0,n-1);
	}
	private Node createTree(int index, int a,int b){
		Node head = tree.get(index);
		head.initNode(a, b);
		if(a < b){
			int mid = (a+b)/2;
			head.lc = createTree(index*2,a,mid);
			head.rc = createTree(index*2+1,mid+1,b);
		}
		return head;
	}
	public void updateNode(int n, int value){
		Node p = tree.get(1);
		while(p != null){
			if(p.max < value)	p.max = value;
			if(n <= (p.l+p.r)/2)	p = p.lc;
			else	p = p.rc;
		}
	}
	public int getMax(int a,int b){
		return search(tree.get(1), a,b);
	}
	private int search(Node p,int a,int b){
//		if(a > b)	System.out.println(a+" "+b);
		int max = 0;
		if(a < p.l)	a = p.l;
		if(b > p.r) b = p.r;
		if(p.l==a && p.r==b){
			max = p.max;
		}
		else{
			int mid = (p.l+p.r)/2;
			if(a<=mid && b>mid){
				int ret1 = search(p.lc,a,mid);
				if(max < ret1)	max = ret1;
				int ret2 = search(p.rc,mid+1,b);
				if(max < ret2)	max = ret2;
			}
			else if(b <= mid){
				int ret = search(p.lc,a,b);
				if(max < ret)	max = ret;
			}
			else if(a > mid){
				int ret = search(p.rc,a,b);
				if(max < ret)	max = ret;
			}
		}
		return max;
	}
}

public class Main {
	static int si[],xi[],yi[];
	static int MAXN = 50010;

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		si = new int[MAXN];
		xi = new int[MAXN];
		yi = new int[MAXN];
		while(in.hasNextInt()){
			int n = in.nextInt();
//			long a = System.currentTimeMillis();
			for(int i=0;i<n;++i){
				si[i] = in.nextInt();
				xi[i] = in.nextInt();
				yi[i] = in.nextInt();
//				si[i] = (int)(Math.random()*(MAXN-1));
//				yi[i] = (int)(Math.random()*(MAXN-3))+2;
//				xi[i] = (int)(Math.random()*(yi[i]-2))+1;
			}
			Tree dp = new Tree(n);
			for(int i=n-1;i>=0;--i){
				int l = i + xi[i];
				int r = i + yi[i]-1;
				if(l>r){
					System.out.println("lr : "+l+" "+r);
					System.out.println("xy : "+xi[i]+" "+yi[i]);
				}
				int max = 0;
				if(l<n){
					if(r >= n){
						r = n-1;
					}
					max = dp.getMax(l, r);
				}
				dp.updateNode(i, max + si[i]);
			}
			System.out.println(dp.getMax(0,0));
//			long b = System.currentTimeMillis();
//			System.out.println("time cost: "+(b-a)+" ms");
		}
	}
}
