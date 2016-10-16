class search{

	static int search_in_sorted_n_rotated(int array[], int left, int right, int No){

		int mid = (right+left)/2;

		if(array[mid] == No) return mid;
				
		if((No>=array[left] && No<=array[mid]) || 
				(array[left]>array[mid] && No>=array[left]) ||
				(No<=array[left] && No<=array[mid])){
			return search_in_sorted_n_rotated(array, left, mid, No);
		}else 
			if(No>=array[mid] && No<=array[right])
				return search_in_sorted_n_rotated(array, mid, right, No);

		return -1;
	}

	public static void main(String[] args){

		int array[] = {4,5,8,-6,-5,-4,-3,-3,-1,1,3};
		int length = array.length;

		int no = -6;

		int pos = search_in_sorted_n_rotated(array, 0, length-1, no);

		System.out.println("pos:"+pos);

	}
}