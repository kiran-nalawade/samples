//find total no of ways to get a given change from given coins.

public class CoinChange {
	static int total_coin_change(int coins[], int last_added, int left){
		if(left == 0){ 
			return 1;
		}
		if(left < 0) return 0;
		int ans = 0;
		for(int i = 0; i<coins.length; i++){
			if(i >= last_added){
				ans += total_coin_change(coins, i, left-coins[i]);
			}
		}
		return ans;
	}
	public static void main(String[] args) {
		int coins[] = {1,2,3,4};
		int change = 5;
		
		int ways = total_coin_change(coins, -1, change);
		
		System.out.println("Total ways :"+ways);
	}
}