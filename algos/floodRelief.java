package test;

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

5
5 5
ccccc
cbbbc
cbabc
cbbbc
ccccc
4 9
cbabcbabc
cbabcbabc
cbabcbabc
cbabcbabc
2 2
ab
ba
2 4
cccc
cccc
11 11
ccccccccccc
caaaaaaaaac
caaaaaaaaac
caazpppzaac
caapdddpaac
caapdddpaac
caapdddpaac
caazpppzaac
caaaaaaaaac
caaaaaaaaac
ccccccccccc

Case #1
1
Case #2
2
Case #3
2
Case #4
1
Case #5
2