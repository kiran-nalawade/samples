import java.util.Scanner;
import java.util.Arrays;

public class checkpoints {

	static int getAbs(int a){
		if(a<0) return -a;
		return a;
	}

	static int getMax(int a, int b){
		if(a>b) return a;
		return b;
	}
	
	static int getMin(int a, int b){
		if(a>b) return b;
		return a;
	}
	
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt(), pos = sc.nextInt();
		int array[] = new int[N];
		for(int i = 0; i<N; i++) {
			array[i] = sc.nextInt();
		}

		if(N == 1) {
			System.out.println("0");
			sc.close();
			return;
		}

		Arrays.sort(array);
		
		int min = 999999999;
		
		int from_left = getMax(0, pos - array[0]);
		int from_right = getMax(0, array[N-2] - pos);
		
		min = getMin(min, from_left+from_right + getMin(from_left, from_right));
		
		from_left = getMax(0, pos - array[1]);
		from_right = getMax(0, array[N-1] - pos);
		
		min = getMin(min, from_left+from_right + getMin(from_left, from_right));
		
		System.out.println(min);

		sc.close();
	}
}
