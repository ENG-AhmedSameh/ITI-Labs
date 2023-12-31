/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gov.iti.jets.java;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

/**
 *
 * @author Ahmed Sameh
 */
public class JavaFXLifeCycle extends Application {
    public static void main(String[] args) {
        launch(args);
    }
 
    public JavaFXLifeCycle() {
        String name = Thread.currentThread().getName();
        System.out.println("Constructor() method: current Thread:" + name);
    }
 
    @Override
    public void init() throws Exception {
        String name = Thread.currentThread().getName();
        System.out.println("init() method: current Thread:" + name);
        super.init();
    }
 
    @Override
    public void start(Stage primaryStage) {
        String name = Thread.currentThread().getName();
        System.out.println("start() method: current Thread:" + name);
 
        StackPane root = new StackPane();
        root.getChildren().add(new Text("JavaFx Life Cycle"));
        Scene scene = new Scene(root, 300, 250);
        primaryStage.setScene(scene);
        primaryStage.show();
    }
 
    @Override
    public void stop() throws Exception {
        String name = Thread.currentThread().getName();
        System.out.println("Stop() method: current Thread:" + name);
        super.stop();
    }
}