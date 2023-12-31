/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gov.iti.jets.java;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.effect.Reflection;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.paint.CycleMethod;
import javafx.scene.paint.LinearGradient;
import javafx.scene.paint.Stop;
import javafx.scene.text.Text;
import javafx.stage.Stage;

/**
 *
 * @author Ahmed Sameh
 */
public class HelloJFX extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        Text helloTextField = new Text("Hello World");
        helloTextField.setStyle("-fx-fill: red;"+"-fx-font-size: 40;"+"-fx-font-weight: bold;");
        
        Reflection helloTextReflection = new Reflection();
        helloTextField.setEffect(helloTextReflection);
        
        StackPane root = new StackPane();
        root.getChildren().add(helloTextField);
        Stop[] stops = new Stop[]{
                new Stop(0, Color.BLACK),      
                new Stop(0.25, Color.rgb(169, 169, 169)),  
                new Stop(0.5, Color.WHITE),       
                new Stop(0.75,Color.rgb(169, 169, 169)),
                new Stop(1, Color.BLACK)
        };
        LinearGradient gradient = new LinearGradient(0, 0, 0, 1, true, CycleMethod.NO_CYCLE, stops);
        
        //root.setStyle("-fx-background-color: linear-gradient(to bottom,black,#454545,white,#454545,black);");
        //root.setBackground(new Background(new BackgroundFill(gradient, CornerRadii.EMPTY, Insets.EMPTY)));
        
        Scene scene = new Scene(root, 500, 400,gradient);
        
        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
