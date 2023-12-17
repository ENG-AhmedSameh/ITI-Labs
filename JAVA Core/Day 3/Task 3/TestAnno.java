import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

@Retention(RetentionPolicy.RUNTIME)
@Target({ElementType.TYPE, ElementType.METHOD, ElementType.CONSTRUCTOR, ElementType.FIELD})
@interface Author {
    int val() default 0;
    String text() default "annonated";
}


@Author(val=10,text="annoated class")
class testAnno{

    @Author
    private int salary = 1000;

    public int id=20;

    @Author
    public testAnno(){
        System.out.println("This is the testAnno constructor");
    }

    @Author
    public void displayId(){
        System.out.println("Id Displayed Successfully = "+id);
    }

    public void printSalary(){
        System.out.println("Salary = "+salary);
    }
}
