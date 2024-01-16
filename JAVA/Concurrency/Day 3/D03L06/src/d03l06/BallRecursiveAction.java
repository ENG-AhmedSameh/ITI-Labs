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
public class BallRecursiveAction extends RecursiveAction{
    
    CombinationApp app;
    JLabel imageLabel;
    public BallRecursiveAction(CombinationApp cApp,JLabel lbl){
        app= cApp;
        imageLabel = lbl;
    }
    
    @Override
    public void compute(){
        
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
    }
}
