
public class truckLoad {
	
	static int find_no_of_trucks_rqd(int Load, int capacity){
		
		if(Load <= capacity) return 1;
		
		return (find_no_of_trucks_rqd(Load/2, capacity) + find_no_of_trucks_rqd(Load - Load /2, capacity));
	}
	
	static int total;
	
	static void find(int L, int C){
		
		if(L <= C) {
			total++;
			return;
		}
		
		find(L/2, C);
		find(L-L/2, C);
	}
	
	public static void main(String[] args){
	
		int L = 1024, C = 5;
		
//		int truck = find_no_of_trucks_rqd(L,C);
		find(L,C);
		System.out.println(total);
	}
}
