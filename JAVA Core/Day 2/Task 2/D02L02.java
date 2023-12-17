class BinarySearch{

	public static void main(String[] args){
		
		int[] arr = new int[1000];
		for(int i=0;i<arr.length;i++)
			arr[i] = (int) (Math.random()*1000);
		sort(arr);
		printArray(arr);
		long startTime = System.nanoTime();
		int minIndex = binarySearch(arr,arr[0]);
		int maxIndex = binarySearch(arr,arr[arr.length-1]);
		long endTime = System.nanoTime();
		System.out.println("The minimum number in the array = "+arr[minIndex]);
		System.out.println("The maximum number in the array = "+arr[maxIndex]);
		System.out.println("The search running time = "+(endTime-startTime)+" nano second.");
		
		
	}
	private static void sort(int[] arr){
		boolean isSorted = false;
		int i=0;
		while(!isSorted){
			isSorted =true;
			for(int j =0; j<arr.length-i-1; j++){
				if(arr[j] > arr[j+1]){
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
					isSorted = false;
				}
			}
			i++;
		}
	}
	private static void printArray(int[] arr){
		System.out.print("Array: [ ");
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
		System.out.println("]");
	}

	private static int binarySearch(int[] arr, int target){
		int left = 0;
        	int right = arr.length - 1;
		int mid;
        	while (left <= right) {
            		mid = (left+right)/ 2;
			if (arr[mid] < target) 
                		left = mid + 1;
			else if(arr[mid]> target)
                		right = mid - 1;
            		else
                		return mid;			
        	}
	        return -1;
	}

}