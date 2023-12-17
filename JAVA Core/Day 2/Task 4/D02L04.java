import java.util.regex.Pattern;
class WordsCounter{

	public static void main(String[] args){
		String str = String.join(" ", args);
		Pattern pattern = Pattern.compile("\\b[\\w'_\\-]+\\b\\.?");
		//Matcher matcher = Patter.matcher(str); 
		String[] result = pattern.split(str);
		int counter = result.length;
		if(result[0].equals("")&&counter==1)
			counter = 0;
		System.out.println("The number of words equals " + counter);
	}

}