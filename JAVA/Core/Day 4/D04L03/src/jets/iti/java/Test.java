package jets.iti.java;

public class Test {


    public static void main(String[] args) {
        ComplexNumber<Double> c1 = new ComplexNumber<>(5.0,6.0);
        ComplexNumber<Double> c2 = new ComplexNumber<>(3.0,2.0);

        ComplexNumber<Double> c3 = c1.addComplex(c2);
        ComplexNumber<Double> c4 = c1.subtractComplex(c2);
        c1.print();
        c2.print();
        c3.print();
        c4.print();
    }


}
