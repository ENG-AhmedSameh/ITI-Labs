    package jets.iti.java;

    public class ManagingException {
        public void firstMethod() throws MyException{
            System.out.println("I'm the firstMethod");
            throw new MyException();
        }
        public void secondMethod() throws MyException{
            System.out.println("I'm the secondMethod");
            throw new MyException("Invalid file");
        }
        public void thirdMethod(){
            System.out.println("I'm the thirdMethod");
            System.out.println("No Exception here");
        }

    }
