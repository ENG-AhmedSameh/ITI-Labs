/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package d03l02;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 *
 * @author Ahmed Sameh
 */

public class BannerApp extends JFrame{

    JLabel bannerLabel = new JLabel();
    static BannerApp app;
    public BannerApp(){
        this.setTitle("Banner Application");
        bannerLabel.setHorizontalAlignment(JLabel.CENTER);
        bannerLabel.setText("Java World");
        bannerLabel.setSize(65,30);
        this.setLayout(null);
        this.add(bannerLabel);
        ExecutorService executorService = Executors.newSingleThreadExecutor();
        Runnable runnable = () -> {
            
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
        };
        executorService.submit(runnable);
        
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        executorService.shutdown();
    }
    
    public static void main(String[] args){
        app = new BannerApp();
        app.setBounds(50,50,600,400);
        app.setVisible(true);
    }    
}
