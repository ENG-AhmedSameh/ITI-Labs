import java.util.StringTokenizer;
class IndexOfCounter{
	
	public static void main(String[] args){
		if(args.length < 2){
			System.out.println("Please Enter the word you want to search in then enter the sentence");
			return;
		}
		countWithIndexOf(args);
		
	}
	
	private static void countWithIndexOf(String[] arr){
		String target = arr[0];
		String str = String.join(" ", arr);
		int index = str.indexOf(target) , counter = -1, indexOfCharAfterTarget = 0;
		while (index != -1){
			indexOfCharAfterTarget = index+arr[0].length();
			if(indexOfCharAfterTarget == str.length()) //not to count the dot and comma in the end of sentence 
				counter++;
			else if(indexOfCharAfterTarget<str.length() && (str.charAt(indexOfCharAfterTarget) == '.' || str.charAt(indexOfCharAfterTarget) == ' '||str.charAt(indexOfCharAfterTarget) == ','))
				counter++;
			index = str.indexOf(target,index+1);
		}
		System.out.println("The number of apperance of word "+arr[0]+" is "+counter);
	}
}