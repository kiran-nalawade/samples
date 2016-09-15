
import java.util.Scanner;

class ticTacToe {

	static int total_x_score;
	static int total_o_score;

	static int occurrence_in_one_visit = 0;

	//visited 0b0000 (rd)(ld)(v)(h)
	static void check_horizontal(int B[][], int visited[][],
			int row, int column, int bsize, int char_to_compare){
		
		if(row < 0
				|| row >= bsize
				|| column < 0
				|| column >= bsize){
			return;
		}
		
		if(B[row][column] != char_to_compare){
			return;
		}
		
		if((visited[row][column] & 0x01) > 0){
			return;
		}

		visited[row][column] |= 0x01;

		occurrence_in_one_visit++;
		
		//horizontal left		
		check_horizontal(B, visited, row, column - 1, bsize, char_to_compare);

		//horizontal right
		check_horizontal(B, visited, row, column + 1, bsize, char_to_compare);	
		
		if(occurrence_in_one_visit == 1)
			visited[row][column] &= 0xFE; //1111 1110
	}

	static void check_vertical(int B[][], int visited[][],
			int row, int column, int bsize, int char_to_compare){

		if(row < 0
				|| row >= bsize
				|| column < 0
				|| column >= bsize){
			return;
		}
		
		if(B[row][column] != char_to_compare){
			return;
		}

		if((visited[row][column] & 0x02) > 0){
			return;
		}

		visited[row][column] |= 0x02;
		
		occurrence_in_one_visit++;

		//vertical up
		check_vertical(B, visited, row - 1 , column, bsize, char_to_compare);

		//vertical down
		check_vertical(B, visited, row + 1, column, bsize, char_to_compare);

		if(occurrence_in_one_visit == 1){
			visited[row][column] &= 0xFD; //1111 1101
		}
	}

	static void check_left_diagonal(int B[][], int visited[][],
			int row, int column, int bsize, int char_to_compare){

		if(row < 0
				|| row >= bsize
				|| column < 0
				|| column >= bsize){
			return;
		}
		
		if(B[row][column] != char_to_compare){
			return;
		}
		
		if((visited[row][column] & 0x04) > 1){
			return;
		}

		visited[row][column] |= 0x04;
		
		occurrence_in_one_visit++;

		//diagonal left up
		check_left_diagonal(B, visited, row - 1 , column - 1, bsize, char_to_compare);

		//diagonal right down
		check_left_diagonal(B, visited, row + 1, column + 1, bsize, char_to_compare);

		if(occurrence_in_one_visit == 1){
			visited[row][column] &= 0xFB; // 1111 1011
		}
	}

	static void check_right_diagonal(int B[][], int visited[][],
			int row, int column, int bsize, int char_to_compare){

		if(row < 0
				|| row >= bsize
				|| column < 0
				|| column >= bsize){
			return;
		}
		
		if(B[row][column] != char_to_compare){
			return;
		}

		if((visited[row][column] & 0x08) > 1){
			return;
		}

		visited[row][column] |= 0x08;
		
		occurrence_in_one_visit++;

		//diagonal right up
		check_right_diagonal(B, visited, row - 1, column + 1, bsize, char_to_compare);

		//diagonal left down
		check_right_diagonal(B, visited, row + 1, column - 1, bsize, char_to_compare);

		if(occurrence_in_one_visit == 1){
			visited[row][column] &= 0xF7;//1111 0111
		}
	}

	static void update_score(int char_to_compare){
		int score = (occurrence_in_one_visit > 2) ? (occurrence_in_one_visit - 2) : 0;

		if(char_to_compare == 1){
			total_x_score += score;
		}else{
			total_o_score += score;
		}
		
		occurrence_in_one_visit = 0;
	}
	
	static void check_for_occurence(int B[][], int visited[][],
			int row, int column, int bsize, int char_to_compare){
		
		occurrence_in_one_visit = 0;
		
		check_horizontal(B, visited, row, column, bsize, char_to_compare);
		update_score(char_to_compare);		
		
		check_vertical(B, visited, row, column, bsize, char_to_compare);
		update_score(char_to_compare);
	
		check_left_diagonal(B, visited, row, column, bsize, char_to_compare);
		update_score(char_to_compare);

		check_right_diagonal(B, visited, row, column, bsize, char_to_compare);
		update_score(char_to_compare);

		visited[row][column] = 0x0F;
	}

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int taste_case = 0; taste_case<T; taste_case++){
			int bsize = in.nextInt();

			int B[][] = new int[bsize][bsize];
			int visited[][] = new int[bsize][bsize];
			
			total_x_score = 0;
			total_o_score = 0;
			
			for(int r = 0; r<bsize; r++){
				for(int c = 0; c<bsize; c++){
					String input = in.next();
					if(input.charAt(0) == 'o'){
						B[r][c] = 0;
					}else{
						B[r][c] = 1;
					}
				}
			}

			//for x
			for(int r = 0; r<bsize; r++){
				for(int c = 0; c<bsize; c++){
					if(B[r][c] == 0){
						continue;
					}
					
					if(visited[r][c] == 0x0F){
						continue;
					}
					
					check_for_occurence(B, visited, 
							r, c, bsize, 1);
				}
			}
			
			//for o
			for(int r = 0; r<bsize; r++){
				for(int c = 0; c<bsize; c++){
					if(B[r][c] == 1){
						continue;
					}
					if(visited[r][c] == 0x0F){
						continue;
					}
					
					check_for_occurence(B, visited, 
							r, c, bsize, 0);
				}
			}

			System.out.println(total_x_score + " " + total_o_score);
		}
		//end of taste case
	}
}

/*
3
3
o x x
x o x
o x x
6
o o x x o o 
o o x o x x 
x o x o x o 
x o o x x x 
x o o o x x 
o x x o x o 
9
x x o x x o o x x 
x x o o x o x o x 
o o x x o x o o x 
o x o o x o x x x 
x o x x x x o x x 
x o x o x x o o x 
o x x x x x o o o 
o o o o o x o o o 
x o x o o x o o o
*/