/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package d03l06;

import java.util.concurrent.RecursiveAction;
import javax.swing.JLabel;

/**
 *
 * @author Ahmed Sameh
 */
public class BannerRecursiveAction extends RecursiveAction {
    CombinationApp app;
    JLabel bannerLabel;
    public BannerRecursiveAction(CombinationApp cApp,JLabel lbl){
        app= cApp;
        bannerLabel = lbl;
    }
    
    @Override
    public void compute(){
        
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
