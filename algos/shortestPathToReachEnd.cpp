/* 
1				// Test case no
4 5				//no of rows and column
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
*/

// go from [0][0] to [4][4]

import java.util.Scanner;

public class shortestPath {
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for(int test_case = 0; test_case < T; test_case++){
			int R = in.nextInt(); int C = in.nextInt();
			int map[][] = new int[R][C];
			
			for(int r = 0; r<R; r++){
				for(int c = 0; c<C; c++){
					map[r][c] = in.nextInt();
				}
			}
			
			int dp[][] = new int[R+1][C+1];
			
			for(int i = 0; i<C; i++){
				dp[R][i] = Integer.MAX_VALUE;
			}
			
			for(int i = 0; i<R; i++){
				dp[i][C] = Integer.MAX_VALUE;
			}
			
			dp[R-1][C] = 0;	dp[R][C] = 0; dp[R][C-1] = 0;
			
			for(int i = R-1; i>=0; i--){
				for(int j = C-1; j>=0; j--){
					dp[i][j] = (dp[i+1][j] > dp[i][j+1] ? dp[i][j+1] : dp[i+1][j]) + map[i][j];
				}
			}
			
			System.out.print("# " + (test_case+1) + " ");
			System.out.print(dp[0][0]);
			System.out.println();
		}
	}
}