//http://www.spoj.com/problems/TRUCKL/

/*
We have a pile of crates at our warehouse that we want to load onto trucks. 
Our plan is to divide the pile in half forming two smaller piles,
 then continuing dividing each of the small piles in half until we get piles that will fit on a truck. 
 (Of course, when we divide an odd number of crates in "half", one of the resulting piles will have one more crate than the other.) 
 Our problem is to determine how many trucks we will need to ship the crates.
*/

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
		find(L,C);
		System.out.println(total);
	}
}
