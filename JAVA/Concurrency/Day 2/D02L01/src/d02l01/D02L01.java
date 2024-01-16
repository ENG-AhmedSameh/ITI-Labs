/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package d02l01;

import java.util.Arrays;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Ahmed Sameh
 */
public class D02L01 {

    static int insertIndex;
    
    public static void main(String[] args) {
        // TODO code application logic here
        int firstArray[] = {1,2,3,4};        
        int secondArray[] = {5,6,7,8};
        int thirdArray[] = {9,10,11,12};
        
        int combinedArray1[] = combineArraysWithOutSync(firstArray,secondArray,thirdArray);
        System.out.println("Without Sync : "+Arrays.toString(combinedArray1));
        
        int combinedArray2[] = new int[firstArray.length+secondArray.length+thirdArray.length];
        

        Thread t1 =new Thread(()->{
            copyArraysWithSync(firstArray, combinedArray2);
        });
        Thread t2 =new Thread(()->{
            copyArraysWithSync(secondArray, combinedArray2);
        });
        Thread t3 =new Thread(()->{
            copyArraysWithSync(thirdArray, combinedArray2);
        });
        
        t3.start();
        t1.start();
        t2.start();
        
        try {
            t3.join();
            t2.join();
            t1.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(D02L01.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
        System.out.println("With Sync : "+Arrays.toString(combinedArray2));

    }
    
    public static int[] combineArraysWithOutSync(int[] arr1, int[] arr2, int[] arr3){
        int combinedArray[] = new int[arr1.length+arr2.length+arr3.length];
        Thread t1 =new Thread(()->{
            for(int i = 0 ; i<arr1.length;i++){
                combinedArray[i] = arr1[i];
            }
        });
        
        Thread t2 =new Thread(()->{
            for(int i = 0 ; i<arr1.length;i++){
                combinedArray[i+arr1.length] = arr2[i];
            }
        });
        
        Thread t3 =new Thread(()->{
            for(int i = 0 ; i<arr1.length;i++){
                combinedArray[i+arr1.length+arr2.length] = arr3[i];
            }
        });
        
        t1.start();
        t2.start();
        t3.start();
        
        try {
            t1.join();
            t2.join();
            t3.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(D02L01.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
        return combinedArray;
    }
    
    public static void copyArraysWithSync(int[] arr, int[] combinedArray){
        synchronized(combinedArray){
            for(int i = insertIndex;i< insertIndex+arr.length&&i<combinedArray.length;i++){
                combinedArray[i] = arr[i-insertIndex];
            }
            insertIndex += arr.length;
        }
    }
    
}
