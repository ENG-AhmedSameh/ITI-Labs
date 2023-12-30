package jets.iti.java;

public class BetterString {
    public static void main(String[] args) {
        String s1 = "Ahmed";
        String s2 = "OMAR";
        String betterStr = StringUtils.betterString(s1,s2,(str1,str2)->(str1.length()>str2.length()));
        System.out.println("Length Wise the better is : "+betterStr);
        betterStr = StringUtils.betterString(s1,s2,StringUtils::hasMoreUpperChars);
        System.out.println("Upper chars Wise the better is : "+betterStr);
    }
}
