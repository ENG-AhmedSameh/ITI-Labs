/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package d01l02;

import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 *
 * @author Ahmed Sameh
 */

public class BannerApp extends JFrame implements Runnable{

    Thread th; 
    JLabel bannerLabel = new JLabel();
    static BannerApp app;
    public BannerApp(){
        this.setTitle("Banner Application");
        bannerLabel.setHorizontalAlignment(JLabel.CENTER);
        bannerLabel.setText("Java World");
        bannerLabel.setSize(65,30);
        this.setLayout(null);
        this.add(bannerLabel);
        th = new Thread(this); 
        th.start();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    
    public static void main(String[] args){
        app = new BannerApp();
        app.setBounds(50,50,600,400);
        app.setVisible(true);
        
    }
    
    @Override
    public void run(){
        
        int xLocation = 0;
        int yLocation = 70;
        
        while(true){
            if(xLocation == app.getWidth())
                xLocation = 0;
            else
                xLocation += 10;
            bannerLabel.setLocation(xLocation,yLocation);
            
            try {
                Thread.sleep(50);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    }
    
}
