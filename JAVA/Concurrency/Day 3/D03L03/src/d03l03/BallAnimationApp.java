/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package d03l03;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 *
 * @author Ahmed Sameh
 */
public class BallAnimationApp extends JFrame{
    
    JLabel imageLabel = new JLabel();

    static BallAnimationApp app;
    
    public BallAnimationApp(){
        
        this.setTitle("Moving Ball");
        try {
            ImageIcon imageIcon = new ImageIcon("src\\Resources\\Images\\ball.png");
            imageLabel.setIcon(imageIcon);
            imageLabel.setSize(50,50);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        this.setLayout(null);
        this.add(imageLabel);
        ExecutorService executorService = Executors.newSingleThreadExecutor();
        Runnable runnable = () -> {
            
        int xLocation = 1;
        int yLocation = 1;
        int dx = 5;
        int dy = 5;
        imageLabel.setLocation(xLocation,yLocation);
        while(true){
            if (xLocation<=0||(xLocation+imageLabel.getWidth()*1.5>=app.getWidth()))
                 dx*=-1; 
            else if (yLocation<=0||(yLocation+imageLabel.getHeight()*2>=app.getHeight()))
                 dy*=-1;
            
            xLocation += dx;
            yLocation += dy;
            
            imageLabel.setLocation(xLocation,yLocation);
            try {
                Thread.sleep(10);
            }catch(InterruptedException ex) {
                ex.printStackTrace();
            }
         }
        };
        executorService.submit(runnable);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        executorService.shutdown();
    }
    
    public static void main(String[] args){
        app = new BallAnimationApp();
        app.setBounds(50,50,600,400);
        app.setVisible(true);
    }
}
