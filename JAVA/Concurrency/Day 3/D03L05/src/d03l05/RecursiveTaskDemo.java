package D03L05;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveTask;

public class RecursiveTaskDemo{
    public static void main(String [] args){
        ForkJoinPool fjp = new ForkJoinPool();
        double[] nums = new double[5000];
        
        for(int i=0; i<nums.length; i++) 
            nums[i]=(double) (((i%2) == 0 ? i : -i));
        
        Sum task = new Sum(nums, 0, nums.length);
        double summation = (Double)(fjp.invoke(task)); 
        System.out.println("The Summation = " + summation );
    }
}

class Sum extends RecursiveTask {
    final int seqThreshold = 500;
    double data[];
    int start, end;
    
    Sum(double[] vals, int s, int e){
        data = vals; start = s; end = e;
    }
    protected Double compute(){
        double sum = 0;
        if((end - start) < seqThreshold){
            for(int i = start; i < end; i++)
            {
                sum+= data[i]; 
            }
        }else{
            int middle = (end + start) / 2;
            Sum subTaskA = new Sum(data, start, middle);
            Sum subTaskB = new Sum(data, middle, end);
            //subTaskA.fork();
            subTaskB.fork();
            // To minimize the number of used threads
            sum = (Double)subTaskA.compute() + (Double)subTaskB.join();
        }
        return sum;
    }
}


