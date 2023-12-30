package jets.iti.java;

import java.io.IOException;

public class MyException extends IOException{
    MyException(){
        System.out.println("I'm the new exception");
    }
    MyException(String message){
        super(message);
        System.out.println("I'm the new exception");
    }
}
