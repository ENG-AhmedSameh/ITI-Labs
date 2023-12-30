package jets.iti.java;

import java.util.function.BiPredicate;

public class StringUtils {
    public static String betterString(String s1, String s2, BiPredicate<String,String> checkFirstIsBetter){
        if(checkFirstIsBetter.test(s1,s2))
            return s1;
        return s2;
    }
    public static boolean hasMoreUpperChars(String s1,String s2){
        return countUpperChars(s1) > countUpperChars(s2);
    }
    public static int countUpperChars(String s){
        char[] charArr = s.toCharArray();
        int count = 0;
        for(char c : charArr)
            if(Character.isUpperCase(c))
                count ++;
        return count;
    }
}
