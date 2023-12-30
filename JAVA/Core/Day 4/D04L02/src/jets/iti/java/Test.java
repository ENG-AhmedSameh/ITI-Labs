package jets.iti.java;

import java.util.ArrayList;
import java.util.List;

public class Test {
    public static void main(String[] args) {
        List<Rectangle> l1 = new ArrayList<>();
        l1.add(new Rectangle());
        l1.add(new Rectangle());
        l1.add(new Rectangle());
        l1.add(new Rectangle());
        l1.add(new Rectangle());

        testMethod(l1);

        List<Circle> l2 = new ArrayList<Circle>();
        l2.add(new Circle());
        l2.add(new Circle());
        l2.add(new Circle());

        testMethod(l2);

    }
    public static <T extends Shape> void testMethod(List<T> l){
        for(T shapeObj : l ) {
            shapeObj.draw();
        }

    }
}
