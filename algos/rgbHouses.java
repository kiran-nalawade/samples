/*
There are a row of houses, each house can be painted with three colors red, blue and green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color. You have to paint the houses with minimum cost. How would you do it? 

Note: Painting house-1 with red costs different from painting house-2 with red. The costs are different for each house and each color.
*/

//https://www.careercup.com/question?id=9941005
import java.util.Scanner;

public class rgbHouses {

	static int min = Integer.MAX_VALUE;

	static void dfs(int m[][], int colors_added, int last_painted, 
			int r, int total_cost, int total_items){

		if(colors_added == total_items){
			if(min>total_cost){
				min = total_cost;
			}
			return;
		}
		if(r > (total_items-1)) return;
		//red
		if(last_painted != 0){
			dfs(m, colors_added+1, 0, r+1, total_cost + m[r][0], total_items);
		}

		//green
		if(last_painted != 1){
			dfs(m, colors_added+1, 1, r+1, total_cost + m[r][1], total_items);
		}

		//blue
		if(last_painted != 2){
			dfs(m, colors_added+1, 2, r+1, total_cost + m[r][2], total_items);
		}

	}

	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();

		for(int test_case = 0; test_case <T; test_case++){
			min = Integer.MAX_VALUE;
			int m[][] = new int[100][3];
			
			String a = sc.next();
			System.out.println(a);
			int length = a.length();
			int r = 0, c = 0;
			int prev = 0;
			for(int i = 0; i<length; i++){
				if(c == 3){c = 0; r++;}
				char at = a.charAt(i);
				if(at < '0' || at > '9') {
					if(prev > 0){
						m[r][c++] = prev;
						prev = 0;
					}
					continue;
				}
				
				prev = prev*10 + (at-48);
			}
			
			for(int i = 0; i<r; i++){
				for(int j = 0; j<3; j++){
					System.out.print(m[i][j] + " ");
				}
				System.out.println();
			}
			
			dfs(m, 0, -1, 0, 0, r);

			System.out.println("Case #" + (test_case+1));
			System.out.println(min);
		}
	}
}

