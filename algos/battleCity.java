import java.util.Scanner;

public class battleCity {

	static int MAX_VALUE = Integer.MAX_VALUE-1;
	static int dfs(int m[][], int v[][], int d[][], int r, int c, int h, int w)
	{
		if(r < 0 || c < 0 || r>=h || c>=w) return -1;

		if(m[r][c] == -1) return -1;

		if(m[r][c] == 3) return 0;

		if(d[r][c] != -1) return d[r][c];

		if(v[r][c] == 1) return d[r][c];

		v[r][c] = 1;

		int b = 0;

		if(m[r][c] == 0){
			b = 1;
		}

		int min;
		int right = dfs(m, v, d, r, c+1, h, w);
		int down = dfs(m, v, d, r+1, c, h, w);
		int left = dfs(m, v, d, r, c-1, h, w);
		int top = dfs(m, v, d, r-1, c, h, w);

		if(left == -1) left = MAX_VALUE;
		if(right == -1) right = MAX_VALUE;
		if(top == -1) top = MAX_VALUE;
		if(down == -1) down = MAX_VALUE;

		min = left < right ? left : right;
		min = min < top ? min : top;
		min = min < down ? min : down;

		if(r == 1 && c  == 1){
			v[r][c] = 0;
		}
		if(min != MAX_VALUE){
			d[r][c] = min + b + 1;
		}

		v[r][c] = 0;
		return d[r][c];
	}

	static public void main(String[]args)
	{
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();

		for(int test_case = 0; test_case < T; test_case++){

			int r, c;
			r = sc.nextInt();
			c = sc.nextInt();

			int m[][] = new int[r][c];
			int v[][] = new int[r][c];
			int d[][] = new int[r][c];

			int sp_x = 0, sp_y = 0;
			for(int i = 0; i <r; i++){
				String val = sc.next();
				for(int j = 0; j<c; j++){
					d[i][j] = -1;

					if(val.charAt(j) == 'Y'){
						m[i][j] = 2;sp_x = i; sp_y = j;
					}else if(val.charAt(j) == 'T'){
						m[i][j] = 3;
					}else if(val.charAt(j) == 'R'){
						m[i][j] = -1;
					}else if(val.charAt(j) == 'S'){
						m[i][j] = -1;
					}else if(val.charAt(j) == 'B'){
						m[i][j] = 0;
					}else if(val.charAt(j) == 'E'){
						m[i][j] = 1;
					}
				}
			}

			int a = dfs(m, v, d, sp_x, sp_y, r, c);
			for(int i = 0; i<r;i++){
				for(int j = 0; j<c; j++){
					System.out.print(d[i][j]+" ");
				}
				System.out.println();
			}

			System.out.println(a);
		}

	}
}
