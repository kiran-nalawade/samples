class sudoku{

	static int hcombo[][], vcombo[][];

	static void print_table(int grid[][], int N){
		for(int i = 0; i<N; i++){
			for(int j = 0; j<N; j++){
				System.out.print(grid[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println();
	}

	static void solve_sudoku(int grid[][], int row, int column, int N){

		if((row == N-1) && (column == N-1)){
			print_table(grid, N);
			return;
		}

		int newr = row, newc = (column+1)%N;
		if(newc < column){
			newr++;
		}

		if(newr == N) return;

		if(grid[newr][newc] > 0){
			solve_sudoku(grid, newr, newc, N);
			return;
		}

		for(int i = 1; i<=N; i++){

			if(hcombo[newr][i] == -1 || vcombo[newc][i] == -1) continue;

			grid[newr][newc] = i; hcombo[newr][i] = -1; vcombo[newc][i] = -1;
			solve_sudoku(grid, newr, newc, N);
			grid[newr][newc] = 0; hcombo[newr][i] = 0; vcombo[newc][i] = 0;
		}
	}

	public static void main(String[] args){
		
		int grid[][] = {{2,0,0,1,7,8,0,3,0},
                     {0,4,0,3,0,2,0,9,0},
                     {1,0,0,0,0,0,0,0,6},
                     {0,0,8,6,0,3,5,0,0},
					 {3,0,0,0,0,0,0,0,4},
                     {0,0,6,7,0,9,2,0,0},
                     {9,0,0,0,0,0,0,0,2},
                     {0,8,0,9,0,1,0,6,0},
                     {0,0,1,4,3,6,0,5,0}};

		int N = grid.length;

		hcombo = new int[N][N+1];
		vcombo = new int[N][N+1];

		for(int i = 0; i<N; i++){
			for(int j = 0; j<N; j++){
				if(grid[i][j]>0){
					hcombo[i][grid[i][j]] = -1;
					vcombo[j][grid[i][j]] = -1;
				}
			}
		}

		solve_sudoku(grid, 0, -1, N);
	}
}
