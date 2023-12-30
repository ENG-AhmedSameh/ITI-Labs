package jets.iti.java;
public class TreatingException {
    public static void main(String[] args) {
        ManagingException obj = new ManagingException();
        try {
            obj.firstMethod(); //will be an exception here so method 2&3 won't be invoked
            obj.secondMethod();
            obj.thirdMethod();
        } catch (MyException e) {
            e.getStackTrace();
        }finally {
            System.out.println("I'm the finally block");
        }
    }
}
