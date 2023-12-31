package gov.iti.jets.java;

import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.scene.Scene;
import javafx.scene.effect.Reflection;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

/**
 *
 * @author Ahmed Sameh
 */
public class HelloJFXUsingCss extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        Text helloTextField = new Text("Hello World");
        helloTextField.setId("helloText");
        
        Reflection helloTextReflection = new Reflection();
        helloTextField.setEffect(helloTextReflection);
        
        StackPane root = new StackPane();
        root.getChildren().add(helloTextField);
        
        
        Scene scene = new Scene(root, 500, 400);
        scene.getStylesheets().add(getClass().getResource("/Styles/MyStyle.css").toString());
        
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
