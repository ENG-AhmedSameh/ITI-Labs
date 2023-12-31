package gov.iti.jets.java;
import java.awt.*;
import java.awt.event.*;
import java.net.*;
import javax.swing.*;

public class BuildGui extends JFrame {

    public BuildGui() {
        this.setLayout(new FlowLayout());

        JLabel label = new JLabel("Enter URL");
        JTextField tf = new JTextField(25);

        JButton okButton = new JButton("Find IP");
        
        okButton.addActionListener((ActionEvent actionEvent)->{
            try {
                    InetAddress inetAddress = InetAddress.getByName(tf.getText());
                    String message = "URL: " + tf.getText() + "\nIP: " + inetAddress.getHostAddress();

                    JOptionPane.showMessageDialog(okButton, message, "IP Finder",
                            JOptionPane.INFORMATION_MESSAGE);

                    System.out.println("IP Address: " + inetAddress.getHostAddress());
                }catch (UnknownHostException e) {
                    JOptionPane.showMessageDialog(okButton, "Invalid URL", "IP Finder",
                            JOptionPane.ERROR_MESSAGE);

                }
        });

        this.add(label);
        this.add(tf);
        this.add(okButton);

        this.setSize(550, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(()->new BuildGui());
    }
}
