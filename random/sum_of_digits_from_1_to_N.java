class sum_of_digits_from_1_N {

	static int sum_of_digits_1_N(int no){

		if(no < 10) return (no *(no+1)/2);

		int digit_places = (int) Math.log10(no);
		int p10 = (int) Math.pow(10, digit_places);
		int first_digit = (int) (no / p10);

		int result = 45* (p10 / 10) * first_digit * digit_places;

		int remaining = (int) (no % p10);

		return (int) (result + first_digit + first_digit * remaining + 
					(first_digit * (first_digit-1) /2 * p10) + sum_of_digits_1_N(remaining));
	}
	
	public static void main(String[] args){
		
		System.out.println(sum_of_digits_1_N(324));
	}
}