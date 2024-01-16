package d01l01;

import java.util.Date;
import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 *
 * @author Ahmed Sameh
 */
public class DateTimeApp extends JFrame implements Runnable{

    Thread th; 
    Date d = new Date();
    JLabel timeLabel = new JLabel();
    public DateTimeApp(){
        this.setTitle("Date & Time Frame Application");
        timeLabel.setHorizontalAlignment(JLabel.CENTER);
        timeLabel.setText(d.toString());
        timeLabel.setLocation(130,150);
        timeLabel.setSize(300,30);
        this.setLayout(null);
        this.add(timeLabel);
        th = new Thread(this); 
        th.start();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public static void main(String[] args){
        DateTimeApp app = new DateTimeApp();
        app.setBounds(50,50,600,400);
        app.setVisible(true);
        app.setResizable(false);
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
