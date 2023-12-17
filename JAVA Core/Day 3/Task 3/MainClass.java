import java.lang.annotation.*;
import java.lang.reflect.*;

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

class mainClass{
    public static void main(String[] args) {
        try {
            testAnno testAnnoObj = new testAnno();
            Class<?> testAnnoObjClass = testAnnoObj.getClass();
            if (testAnnoObjClass.isAnnotationPresent(Author.class)) {
                System.out.println(testAnnoObjClass);
            }

            Author authorAnno = testAnnoObjClass.getAnnotation(Author.class);
            System.out.println("Value of the annotation of class = " + authorAnno.val());
            System.out.println("Text of the annotation of class = " + authorAnno.text());


            Constructor testAnnoCons = testAnnoObjClass.getConstructor();
            if (testAnnoCons.isAnnotationPresent(Author.class)){
                System.out.println("Constructor has an Author annotation");
            }

            Method[] testAnnoMethods = testAnnoObjClass.getMethods();
            for (Method m:testAnnoMethods) {
                if(m.isAnnotationPresent(Author.class))
                    m.invoke(testAnnoObj);
            }

            Field[] testAnnoFields = testAnnoObjClass.getDeclaredFields();
            for (Field f:testAnnoFields) {
                if(f.isAnnotationPresent(Author.class)) {
                    f.setAccessible(true);
                    f.set(testAnnoObj, 500);
                }
            }
            testAnnoObj.printSalary();
            testAnnoObj.displayId();


        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }
    }
}