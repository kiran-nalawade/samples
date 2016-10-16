import java.util.Scanner;

public class fibo {

	static void matrixMultilication(long mat1[][], long mat2[][], long mod){

		long a00 = ((mat1[0][0]*mat2[0][0])%mod + (mat1[0][1]*mat2[1][0])%mod)%mod;
		long a01 = ((mat1[0][0]*mat2[0][1])%mod + (mat1[0][1]*mat2[1][1])%mod)%mod;
		long a10 = ((mat1[1][0]*mat2[0][0])%mod + (mat1[1][1]*mat2[1][0])%mod)%mod;
		long a11 = ((mat1[1][0]*mat2[0][1])%mod + (mat1[1][1]*mat2[1][1])%mod)%mod;

		mat1[0][0] = a00;
		mat1[0][1] = a01;
		mat1[1][0] = a10;
		mat1[1][1] = a11;
	}

	static void nth_term(long mat[][], long base[][], int N, long mod){

		if(N < 2) return;

		nth_term(mat, base, N/2, mod);
		matrixMultilication(mat, mat, mod);

		if(N%2 != 0){
			matrixMultilication(mat, base, mod);
		}

	}

	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();

		while(T-- >0){
			long a, b, mod = 1000000007;
			a = sc.nextLong();b = sc.nextLong(); int n = sc.nextInt();

			long mat[][] = {{1,1},{1,0}};
			long base[][] = {{1,1},{1,0}};

			if(n == 1){
				System.out.println(b);
			}else{
				nth_term(mat, base, n-1, mod);
				System.out.println((mat[0][0]*b+mat[0][1]*a)%mod);
			}
		}
	}
}
