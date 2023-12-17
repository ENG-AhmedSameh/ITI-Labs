class PrintSeveralTimes{
	public static void main(String[] args){
		if(args.length!=2)
				System.out.println("Please enter only two arguments");
		else{
			try{
				int numberOfPrints = Integer.parseInt(args[0]);
				if(numberOfPrints>0){
					for(int i=0;i<numberOfPrints;i++)
						System.out.println(args[1]);
				}else
					System.out.println("Error: The first parameter must be an positive integar");
			}
			catch(NumberFormatException e){
				System.out.println("Error: The first parameter must be an integar");
			}
		}
	}
}