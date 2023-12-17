import java.util.StringTokenizer;
class TokenCounter{
	
	public static void main(String[] args){
		if(args.length < 2){
			System.out.println("Please Enter the word you want to search in then enter the sentence");
			return;
		}
		countWithStringTokenizer(args);
		
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

}