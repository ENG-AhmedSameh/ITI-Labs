/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package d01bouns1;

import javax.swing.JLabel;

/**
 *
 * @author Ahmed Sameh
 */
public class BannerThread implements Runnable{
    CombinationApp app;
    JLabel bannerLabel;
    public BannerThread(CombinationApp cApp,JLabel lbl){
        app= cApp;
        bannerLabel = lbl;
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
