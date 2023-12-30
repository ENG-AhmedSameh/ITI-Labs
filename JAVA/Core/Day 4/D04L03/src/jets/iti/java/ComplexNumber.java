package jets.iti.java;

public class ComplexNumber<T extends Number> {
    private T real;
    private T imag;

    public ComplexNumber(T real, T imaginary) {
        this.real = real;
        this.imag = imaginary;
    }

    public T getReal() {
        return real;
    }

    public T getImag() {
        return imag;
    }

    public void setReal(T real) {
        this.real = real;
    }

    public void setImag(T imag) {
        this.imag = imag;
    }

    public ComplexNumber<T> addComplex(ComplexNumber<T> c){
        /*this.real = (T) Double.valueOf(this.real.doubleValue()+c.real.doubleValue());
        this.imag = (T) Double.valueOf(this.imag.doubleValue()+c.imag.doubleValue());*/
        if (c.real instanceof Double || c.imag instanceof Double) {
            ComplexNumber<Double> newComplex = new ComplexNumber<>(0.0,0.0);
            newComplex.real = Double.valueOf(this.real.doubleValue()+c.real.doubleValue());
            newComplex.imag = Double.valueOf(this.imag.doubleValue()+c.imag.doubleValue());
            return (ComplexNumber<T>) newComplex;
        } else if (c.real instanceof Float || c.imag instanceof Float) {
            ComplexNumber<Float> newComplex = new ComplexNumber<Float>(0.0f,60.0f);
            newComplex.real = Float.valueOf(this.real.floatValue()+c.real.floatValue());
            newComplex.imag = Float.valueOf(this.imag.floatValue()+c.imag.floatValue());
            return (ComplexNumber<T>) newComplex;
        } else if (c.real instanceof Long || c.imag instanceof Long) {
            ComplexNumber<Long> newComplex = new ComplexNumber<Long>(0l,0l);
            newComplex.real = Long.valueOf(this.real.longValue()+c.real.longValue());
            newComplex.imag = Long.valueOf(this.imag.longValue()+c.imag.longValue());
            return (ComplexNumber<T>) newComplex;
        } else {
            ComplexNumber<Integer> newComplex = new ComplexNumber<Integer>(0,0);
            newComplex.real = Integer.valueOf(this.real.intValue()+c.real.intValue());
            newComplex.imag = Integer.valueOf(this.imag.intValue()+c.imag.intValue());
            return (ComplexNumber<T>) newComplex;
        }
    }
    public ComplexNumber<T> subtractComplex(ComplexNumber<T> c){
        /*this.real = (T) Double.valueOf(this.real.doubleValue()+c.real.doubleValue());
        this.imag = (T) Double.valueOf(this.imag.doubleValue()+c.imag.doubleValue());*/
        if (c.real instanceof Double || c.imag instanceof Double) {
            ComplexNumber<Double> newComplex = new ComplexNumber<>(0.0,0.0);
            newComplex.real = Double.valueOf(this.real.doubleValue()-c.real.doubleValue());
            newComplex.imag = Double.valueOf(this.imag.doubleValue()-c.imag.doubleValue());
            return (ComplexNumber<T>) newComplex;
        } else if (c.real instanceof Float || c.imag instanceof Float) {
            ComplexNumber<Float> newComplex = new ComplexNumber<Float>(0.0f,60.0f);
            newComplex.real = Float.valueOf(this.real.floatValue()-c.real.floatValue());
            newComplex.imag = Float.valueOf(this.imag.floatValue()-c.imag.floatValue());
            return (ComplexNumber<T>) newComplex;
        } else if (c.real instanceof Long || c.imag instanceof Long) {
            ComplexNumber<Long> newComplex = new ComplexNumber<Long>(0l,0l);
            newComplex.real = Long.valueOf(this.real.longValue()-c.real.longValue());
            newComplex.imag = Long.valueOf(this.imag.longValue()-c.imag.longValue());
            return (ComplexNumber<T>) newComplex;
        } else {
            ComplexNumber<Integer> newComplex = new ComplexNumber<Integer>(0,0);
            newComplex.real = Integer.valueOf(this.real.intValue()-c.real.intValue());
            newComplex.imag = Integer.valueOf(this.imag.intValue()-c.imag.intValue());
            return (ComplexNumber<T>) newComplex;
        }
    }
    public void print(){
        System.out.println(this.real + "+" + this.imag + "i");
    }
}

