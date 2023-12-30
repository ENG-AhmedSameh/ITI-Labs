package TestFunctionalIntefaces;
import java.util.function.Function;

class TestFunctionalInterfaces {

    public static void main(String[] args) {
        double celisuis = 20.0;
        displayTempInFeh(celisuis,(c)-> c*(9.0/5.0)+32);
    }

    private static void displayTempInFeh(double cel,Function<Double,Double> convertCelTofeh){
        double feh = convertCelTofeh.apply(cel);
        System.out.println("The temperature is "+feh+" Fahrenheit");
    }
}