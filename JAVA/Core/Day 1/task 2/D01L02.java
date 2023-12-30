class OnlyString{

	public static void main(String[] args){
		for(int i=0;i<args.length;i++){
			if(isNumberCheckParse(args[i]))
				continue;
			else
				System.out.println(args[i]);
		}
		
	}
	public static Boolean isNumberCheckRegex(String str){
		String reg = "[-|+]?([.]?\\d+|\\d+[.]\\d*|\\d+[.]?)";
		if(!str.matches(reg))
			return true;
		return false;
		
	}
	public static Boolean isNumberCheckParse(String str){
		try{
			double numberOfPrints = Double.parseDouble(str);
			return true;
			
		}
		catch(NumberFormatException e){
			return false;
		}
	}

	public static Boolean isNumberCheckDigits(String str){
		Boolean hasDot= false;
		char[] charArr = str.toCharArray();
		//check if the first character is + or - and it's not the only char in the string
		if(charArr.length>1 && (charArr[0]=='+' || charArr[0]=='-')){
			charArr[0]='0';
		}
		for(char c : charArr){
			//check if the digit is number
			if(Character.isDigit(c))
				continue;
			//check if it is dot and this is the first appearence of the dot and the string comtains another chars not only the dots
			else if(c=='.' && hasDot==false &&charArr.length>1){
				hasDot=true;
				continue;
			}
			else
				return false;
		}
		return true;
	}
}