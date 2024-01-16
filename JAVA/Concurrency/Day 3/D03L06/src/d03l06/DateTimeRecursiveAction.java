/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package d03l06;

import java.util.Date;
import java.util.concurrent.RecursiveAction;
import javax.swing.JLabel;

/**
 *
 * @author Ahmed Sameh
 */
public class DateTimeRecursiveAction extends RecursiveAction{
    
    Date d;
    JLabel timeLabel;
    public DateTimeRecursiveAction(Date date,JLabel lbl){
        d = date;
        timeLabel = lbl;
    }
    
    @Override
    public void compute(){
        while(true){
            d= new Date();
            timeLabel.setText(d.toString());
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    }
    
}
