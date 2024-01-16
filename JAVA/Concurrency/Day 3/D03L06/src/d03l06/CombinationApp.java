/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package d03l06;

/**
 *
 * @author Ahmed Sameh
 */

import java.util.Date;
import java.util.concurrent.ForkJoinPool;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.ImageIcon;



public class CombinationApp extends JFrame{

    Thread th1,th2,th3; 
    Date d = new Date();
    JLabel timeLabel = new JLabel();
    JLabel bannerLabel = new JLabel();
    JLabel imageLabel = new JLabel();
    
    static CombinationApp app;
    
    public CombinationApp(){
        this.setTitle("Combination");
        
        timeLabel.setHorizontalAlignment(JLabel.CENTER);
        timeLabel.setText(d.toString());
        timeLabel.setLocation(130,150);
        timeLabel.setSize(300,30);
        this.setLayout(null);
        this.add(timeLabel);
        
        bannerLabel.setHorizontalAlignment(JLabel.CENTER);
        bannerLabel.setText("Java World");
        bannerLabel.setSize(65,30);
        this.add(bannerLabel);
        
        try {
            ImageIcon imageIcon = new ImageIcon("src\\Resources\\Images\\ball.png");
            imageLabel.setIcon(imageIcon);
            imageLabel.setSize(50,50);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        this.add(imageLabel);
        
        ForkJoinPool fjp = new ForkJoinPool();
        
        DateTimeRecursiveAction task1 = new DateTimeRecursiveAction(d,timeLabel);

        
        BannerRecursiveAction task2 = new BannerRecursiveAction(this,bannerLabel);

        BallRecursiveAction task3 = new BallRecursiveAction(this,imageLabel);

        fjp.execute(task1);        
        fjp.execute(task2);
        fjp.execute(task3);

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    
    public static void main(String[] args) {
        app = new CombinationApp();
        app.setBounds(50,50,600,400);
        app.setVisible(true);
    }
    
}
