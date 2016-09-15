import java.util.Scanner;

class island {

	static int islands_in_one_visit = 0;
	static int total_no_islands = 0;

	static void find_islands(int I[][], int visited[][],  int row, int column, int m, int n){

		if(row >= m
				|| row < 0
				|| column >= n
				|| column < 0){
			return;
		}

		if(visited[row][column] == 1){
			return;
		}

		visited[row][column] = 1;

		if(I[row][column] == 1){
			islands_in_one_visit++;
		}else{
			return;
		}

		//horizontal left		
		find_islands(I, visited, row - 1, column, m, n);

		//horizontal right
		find_islands(I, visited, row + 1, column, m, n);	

		//vertical up
		find_islands(I, visited, row, column - 1, m, n);

		//vertical down
		find_islands(I, visited, row, column + 1, m, n);

		//diagonal left up
		find_islands(I, visited, row - 1 , column - 1, m, n);

		//diagonal left down
		find_islands(I, visited, row + 1, column - 1, m, n);

		//diagonal right up
		find_islands(I, visited, row - 1, column + 1, m, n);

		//diagonal right down
		find_islands(I, visited, row + 1, column + 1, m, n);
	}

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int i = 0; i<T; i++){
			int m, n;
			total_no_islands = 0;
			m = in.nextInt();
			n = in.nextInt();
			int I[][] = new int[m][n];
			int visited[][] = new int[m][n];

			for(int row = 0; row < m; row++){
				for(int column = 0; column < n; column++){
					I[row][column] = in.nextInt(); 
				}
			}

			for(int r = 0; r<m; r++){
				for(int c = 0; c<n; c++){
					if(visited[r][c] == 1){
						continue;
					}

					find_islands(I, visited, r, c, m, n);
					if(islands_in_one_visit>0){
						total_no_islands++;
					}
					islands_in_one_visit = 0;
				}
			}

			System.out.println(total_no_islands);
		}
	}
}




2
5 8 
1 0 1 0 0 0 
0 0 0 0 0 0 
0 0 0 0 1 0 
0 0 0 0 0 0 
0 0 0 0 1 0 
0 0 0 0 0 0 
0 1 0 0 
7 6 
1 0 0 0 0 0 0 
0 1 1 1 0 0 0 
0 1 0 0 0 0 0 
1 0 0 0 0 0 1 
0 0 1 0 0 0 1 
0 0 0 0 0 0 0 
