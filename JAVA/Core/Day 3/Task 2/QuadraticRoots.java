
import java.util.function.Function;

class QuadraticRoots {
    public static void main(String[] args) {
        double[] roots = {1,5,6};
        displayRoots(roots,
                (n)-> ((-1*n[1])+Math.sqrt(Math.pow(n[1],2)-(4*n[0]*n[2])))/2.0*n[0],
                (n)-> ((-1*n[1])-Math.sqrt(Math.pow(n[1],2)-(4*n[0]*n[2])))/2.0*n[0]
        );
    }
    private static void displayRoots(double[] nums, Function<double[], Double> calcFirstRoot,Function<double[], Double> calcSecondRoot){
        double root1 = 0, root2 = 0;
        if(((nums[1]*nums[1])-(4*nums[0]*nums[2])) >= 0) {
            root1 = calcFirstRoot.apply(nums);
            root2 = calcSecondRoot.apply(nums);
            System.out.println("The roots are "+root1+"  "+root2);
        }else
            System.out.println("The equation doesn't have real roots");
    }
}
