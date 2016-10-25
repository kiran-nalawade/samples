
public class minPath {

	static int min(int a, int b, int c){
		int min = (a>b)?b:a;
		min = (min>c)?c:min;
		return min;
	}
	static int minPathDP(int cost[][], int R, int C){
		
		int dp[][] = new int[R+1][C+1];
		
		for(int i = 0; i<R; i++){
			dp[R][i] = Integer.MAX_VALUE;
			dp[i][C] = Integer.MAX_VALUE;
		}
		
		dp[R][C] = 0;
		
		for(int i = R-1; i>=0; i--){
			for(int j = C-1; j>=0; j--){
				dp[i][j] = cost[i][j]+min(dp[i+1][j],dp[i][j+1],dp[i+1][j+1]);
			}
		}
		
		return dp[0][0];
	}
	
	static int minPathRecursion(int cost[][], int r, int c, int R, int C){
		if(r==R-1 && c==C-1) return cost[R-1][C-1];
		if(r>=R || c>=C) return Integer.MAX_VALUE;
		
		return (cost[r][c]+min(minPathRecursion(cost, r+1, c, R, C),
				minPathRecursion(cost, r, c+1, R, C),
				minPathRecursion(cost, r+1, c+1, R, C)));
	}
	
	public static void main(String[] args) {

		 int cost[][] = { {1, 2, 3},
                 {4, 8, 2},
                 {1, 5, 3}};
		
		 int R = cost.length;
		 int C = cost[0].length;

//		 System.out.println(minPathRecursion(cost, 0, 0, R, C));
		 System.out.println(minPathDP(cost, R, C));
	}
}
