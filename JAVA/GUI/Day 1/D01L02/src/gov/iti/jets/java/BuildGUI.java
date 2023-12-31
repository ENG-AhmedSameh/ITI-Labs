package gov.iti.jets.java;
import java.awt.*;
import javax.swing.*;

public class BuildGUI extends JFrame {

    public BuildGUI() {
        this.setLayout(new FlowLayout());

        JTextArea ta = new JTextArea(10, 40);
        JScrollPane scroll = new JScrollPane(ta);

        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new FlowLayout());

        JButton charButton = new JButton("Character");
        JButton stringButton = new JButton("String");

        charButton.addActionListener(e -> {
            
        String message = "Number of chars: " + ta.getText().length();
        JOptionPane.showMessageDialog(null, message, "Character Count", JOptionPane.INFORMATION_MESSAGE);
            });

	    stringButton.addActionListener(e -> {
          String[] arr = ta.getText().split("\\W+");
		  
        String message = "Number of String: " + arr.length;
        JOptionPane.showMessageDialog(null, message, "Character Count", JOptionPane.INFORMATION_MESSAGE);
        });

        buttonPanel.add(charButton);
        buttonPanel.add(stringButton);

        this.add(scroll, BorderLayout.CENTER);
        this.add(buttonPanel, BorderLayout.SOUTH);

        this.setSize(500, 400);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        this.setResizable(false);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new BuildGUI();
            }
    });
}
}

