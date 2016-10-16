//https://www.cs.duke.edu/csed/algoprobs/floodrelief.html

/* 
Problem Statement

Global warming has caused your home town to receive far more rain than usual, and it is in danger of becoming flooded. You have been put in charge of buying and installing pumps that will carry away the water. There is no limit on how much water a pump can handle, but they must be placed correctly so that all the water will flow into a pump, with no lakes or even puddles left over. The pumps are also expensive, so you must determine the minimum number that need to be bought.
You are given a String[] heights. This is a rectangular grid representing the height of each square meter of your town. It contains only lowercase letters ('a' - 'z'), with 'a' meaning low ground and 'z' meaning high ground. Water flows from a cell to every cell that shares an edge and is of equal or lower height. The town is surrounded by high mountains on all sides, so water cannot flow off the map. You must return the minimum number of pumps that can be placed to ensure that all rain will eventually flow to some pump.

*/




import java.util.Scanner;

public class floodrelief {
	
	static int min_v = 'z'+1, min_x, min_y;
	
	static void get_min(int m [][], int visited[][], int W, int H){
		
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if(visited[i][j] == 0){
					if(min_v > m[i][j]){
						min_v = m[i][j];
						min_x = i; min_y = j;
					}
				}
			}
		}
	}
	
	static int find_min_pipes(int m[][], int visited[][], int W, int H){
		
		int count  = 0;
		while(true){
			get_min(m, visited, W, H);
			
			if(min_v == ('z'+1)) return count;
			
			count++;
			flood_relief(m, visited, W, H, min_x, min_y, min_v);
			min_v = 'z' + 1;
		}		
	}
	
	static void flood_relief(int m[][], int visited[][], int W, int H, int x, int y, int prev){
	
		if( x < 0 || y < 0 || x >= H || y >= W) return;
		
		if(visited[x][y] == 1) return;
		
		if(prev > m[x][y])return;
		
		visited[x][y] = 1;
		
		flood_relief(m, visited, W, H,    x,   y+1, m[x][y]);
		flood_relief(m, visited, W, H,    x,   y-1, m[x][y]);
		flood_relief(m, visited, W, H,  x+1,   y, m[x][y]);
		flood_relief(m, visited, W, H,  x-1,  y, m[x][y]);
	}
	
	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for(int test_case = 0; test_case<T; test_case++){
			
			int H = in.nextInt();
			int W = in.nextInt();
			int m[][] = new int[H][W];
			int visited[][] = new int[H][W];
			
			for(int i = 0; i < H; i++){
				String land = in.next();
				for(int j = 0; j < W; j++){
					m[i][j] = land.charAt(j);
				}
			}
			
			int pipes = find_min_pipes(m, visited, W, H);
			
			System.out.println("Case #"+ (test_case+1));
			System.out.println(pipes);
			
		}
		
	}
}