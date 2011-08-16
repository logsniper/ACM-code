import java.util.Scanner;
import java.util.regex.*;;

class MDY{
	public long month,day,year;
	MDY(int year){
		this.year = year;
	}
	MDY(String s){
		int i;
		month = 0;
		for(i=0;i<s.length() && s.charAt(i) != '-';++i){
			month = month*10 + s.charAt(i)-'0';
		}
		day = 0;
		for(++i;i<s.length() && s.charAt(i) != '-';++i){
			day = day*10 + s.charAt(i)-'0';
		}
		year = 0;
		for(++i;i<s.length() && s.charAt(i) != '-';++i){
			year = year*10 + s.charAt(i)-'0';
		}
//		System.out.println(month+" "+day+" "+year);
/*		正则表达式处理字符串，效率较低
 * 		Pattern pattern = Pattern.compile("[0-9]+");
		Matcher matcher = pattern.matcher(s);
		Scanner in;
		String m,d,y;
		if(matcher.find()){
			m = matcher.group();
			in = new Scanner(m);
			month = in.nextInt();
		}
		if(matcher.find()){
			d = matcher.group();
			in = new Scanner(d);
			day = in.nextInt();
		}
		if(matcher.find()){
			y = matcher.group();
			in = new Scanner(y);
			year = in.nextInt();
		}*/
	}
	public static int daysInTheYear(int year){
		int m = year%12 + 1;
		int ret = (m*(m+1)/2)*(m*(m+1)/2);
		if(year%11 == 0)	++ret;
		return ret;
	}
	public long daysInTheYear(){
		long m = year%12 + 1;
		long ret = (m*(m+1)/2)*(m*(m+1)/2);
		if(year%11 == 0)	++ret;
		return ret;
	}
	public long daysBeforeToday(){
		long ret = (month*(month-1)/2)*(month*(month-1)/2);
		ret += day-1;
		if(year%11==0 && month>=2)	++ret;
		return ret;
	}
}

public class Main {
	static long matrix[][];
	public static void main(String[] args){
		long round = 0;
		matrix = new long[133][133];
		for(int i=0;i<132;++i){
			round += (long)MDY.daysInTheYear(i);
			matrix[i][0] = 0;
		}
		for(int step = 1;step<132;++step){
			for(int i=0;i<132;++i){
				matrix[i][step] = matrix[i][step-1]+(long)MDY.daysInTheYear(i+step-1);
			}
		}

		Scanner in = new Scanner(System.in);
		String line;
		while(in.hasNextLine()){
			long res = 0;
			line = in.nextLine();
			MDY mdy1 = new MDY(line);
			line = in.nextLine();
			MDY mdy2 = new MDY(line);
			
			if(mdy2.year<mdy1.year || (mdy2.year==mdy1.year&&mdy2.month<mdy1.month) || 
					(mdy2.year==mdy1.year&&mdy2.month==mdy1.month&&mdy2.day<mdy1.day)){
				MDY mdy3 = mdy1;
				mdy1 = mdy2;
				mdy2 = mdy3;
			}
			if(mdy1.year == mdy2.year){
				res = (long)mdy2.daysBeforeToday() - mdy1.daysBeforeToday() + 1;
			}
			else{
				res = mdy1.daysInTheYear()-mdy1.daysBeforeToday() + mdy2.daysBeforeToday()+1;
				long year1 = mdy1.year+1,year2 = mdy2.year-1;
				if(year1<=year2){
					res += matrix[(int)(year1%132)][(int)((year2-year1+1)%132)];
					long roundnum = (year2+1-year1)/132;
					res += (long)roundnum*round;
			//		System.out.println(roundnum+" "+round+" "+matrix[(int)(year1%132)][(int)((year2-year1)%132)]);
				}
			}
			System.out.println(res);
		}
	}
}
