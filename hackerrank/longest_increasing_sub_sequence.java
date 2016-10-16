
public class longest_increasing_sub_sequence{
	
	static int MAX;
	static int memo[];
	
	static int lis(int i, int N, int array[], int prev){
		
		if(i == N) return 0;
		int max = 0;

		if(memo[i]!=-1)return memo[i];
		
		for(int j = i; j<N; j++){
			int ans = 0;
			if(array[j]>prev){
				ans = 1+lis(j+1,N,array, array[j]);
			}
			
			if(ans>max) max = ans;
		}
		
		memo[i] = max;
		return memo[i];
	}
	
	static int max(int a, int b){ if(a>b) return a; return b;}
	
//second approach
	static int getlislen(int array[], int len){
		int dp[] = new int[len];
		for(int i = 0; i<len; i++) dp[i] = 1;
		
		for(int j = 1; j<len; j++){
			for(int k = 0; k<j; k++){
				if(array[j]>array[k]){
					dp[j] = max(dp[j], dp[k]+1);
				}
			}
		}
		
		return dp[len-1];
	}
	
	public static void main(String[] args){

		int array[] = {3, 2, 6, 4, 37, 332, 6, 32, 5, 33, 9 ,54};
		
		int N = array.length;
		memo = new int[N];

		for(int i = 0; i<N; i++) memo[i] = -1;
		
		for(int i = 0; i<N-1; i++){
			int ans = 1+lis(i+1, N, array, array[i]);
			if(ans > MAX){
				MAX = ans;
			}
		}
		System.out.println(MAX);
		
//		System.out.println(getlislen(array, N));
	}
}
