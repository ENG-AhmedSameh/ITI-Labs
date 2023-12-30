package jets.iti.java;
import java.util.function.Predicate;

public class AlphabetString {
    public static void main(String[] args) {
        String str1 ="A7med";
        printStringIsAlphaOrNot(str1,(s1)->(checkStringChars(s1)));
        String str2 ="Ahmed";
        printStringIsAlphaOrNot(str2,AlphabetString::checkStringChars);
    }
    public static void printStringIsAlphaOrNot(String str, Predicate<String> p){
        if(p.test(str))
            System.out.println("String "+str+" is Alphabet");
        else
            System.out.println("String "+str+" isn't Alphabet");
    }
    public static boolean checkStringChars(String str){
        for(int i =0;i<str.length();i++)
            if(!Character.isLetter(str.charAt(i)))
                return false;
        return true;
    }
}
