class MinAndMax{

	public static void main(String[] args){
		
		int[] arr = new int[1000];
		for(int i=0;i<arr.length;i++)
			arr[i] = (int) (Math.random()*1000);
		printArray(arr);
		long startTime = System.nanoTime();
		int minimum = searchMin(arr);
		int maximum = searchMax(arr);
		long endTime = System.nanoTime();
		System.out.println("The minimum number in the array = "+minimum);
		System.out.println("The minimum number in the array = "+maximum);
		System.out.println("The search running time = "+(endTime-startTime)+" nano second.");

		
	}
	private static int searchMin(int[] arr){
		int min = arr[0];
		for (int i=1; i<arr.length; i++){
			if(arr[i]<min)
				min = arr[i];
		}
		return min;
	}
	private static int searchMax(int[] arr){
		int max = arr[0];
		for (int i=1; i<arr.length; i++){
			if(arr[i]>max)
				max = arr[i];
		}
		return max;
	}
	private static void printArray(int[] arr){
		System.out.print("The provided array: [ ");
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
		System.out.println("]");
	}

}