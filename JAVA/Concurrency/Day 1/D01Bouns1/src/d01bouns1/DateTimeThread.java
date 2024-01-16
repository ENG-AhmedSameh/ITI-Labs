/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package d01bouns1;

import java.util.Date;
import javax.swing.JLabel;

/**
 *
 * @author Ahmed Sameh
 */
public class DateTimeThread implements Runnable{
    
    Date d;
    JLabel timeLabel;
    public DateTimeThread(Date date,JLabel lbl){
        d = date;
        timeLabel = lbl;
    }
    
    @Override
    public void run(){
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
