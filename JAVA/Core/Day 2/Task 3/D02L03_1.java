import java.util.StringTokenizer;
class SplitCounter{
	
	public static void main(String[] args){
		if(args.length < 2){
			System.out.println("Please Enter the word you want to search in then enter the sentence");
			return;
		}
		countWithSplit(args);
		
	}
	
	private static void countWithSplit(String[] arr){

		String str = String.join(" ", arr);
		String[] arrOfStr = str.split("\\s+");
		int counter = 0;
		for (int i =1 ; i<arrOfStr.length; i++)
			if(arrOfStr[i].equals(arr[0]))
				counter++;
		System.out.println("The number of apperance of word "+arr[0]+" is "+counter);		

	}
}