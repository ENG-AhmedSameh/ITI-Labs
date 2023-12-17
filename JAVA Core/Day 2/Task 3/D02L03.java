import java.util.StringTokenizer;
class WordCounter{
	
	public static void main(String[] args){
		if(args.length < 2){
			System.out.println("Please Enter the word you want to search in then enter the sentence");
			return;
		}
		countWithStringTokenizer(args);
		
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
	private static void countWithIndexOf(String[] arr){
		String target = arr[0];
		String str = String.join(" ", arr);
		int index = str.indexOf(target) , counter = -1, indexOfCharAfterTarget = 0;
		while (index != -1){
			indexOfCharAfterTarget = index+arr[0].length();
			if(indexOfCharAfterTarget == str.length())
				counter++;
			else if(indexOfCharAfterTarget<str.length() && (str.charAt(indexOfCharAfterTarget) == '.' || str.charAt(indexOfCharAfterTarget) == ' '||str.charAt(indexOfCharAfterTarget) == ','))
				counter++;
			index = str.indexOf(target,index+1);
		}
		System.out.println("The number of apperance of word "+arr[0]+" is "+counter);
	}

	private static void countWithStringTokenizer(String[] arr){
		int counter= -1;
		String str = String.join(" ", arr);
		StringTokenizer st = new StringTokenizer(str," ");
		while(st.hasMoreTokens()){
			if(st.nextToken().equals(arr[0])) 
				counter++;
		}
		System.out.println("The number of apperance of word "+arr[0]+" is "+counter);

	}

	/*private static void printArray(String[] arr){
		System.out.print("Array: [ ");
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+",");
		System.out.println("\b]");
	}*/

}