package gov.iti.jets.java.d01l01.Controllers;

import gov.iti.jets.java.d01l01.HelloApplication;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.shape.Circle;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

import java.io.File;
import java.io.IOException;
import java.util.Objects;

public class WelcomePaneController {

    Boolean validInformation = true;

    @FXML
    private Button choosePictureButton;

    @FXML
    private Circle imageProfileClip;

    @FXML
    private ImageView profilePictureImageView;

    @FXML
    private TextField userFullNameTextField;


    public void choosePictureHandler(MouseEvent mouseEvent) {
        FileChooser fileChooser = new FileChooser();
        fileChooser.getExtensionFilters().addAll(
                new FileChooser.ExtensionFilter("Image Files", "*.png", "*.jpg", "*.jpeg"));
        File selectedFile = fileChooser.showOpenDialog(null);
        if (selectedFile != null) {
            Image profileImage = new Image(selectedFile.toURI().toString());
//            profilePictureImageView.setFitWidth(imageProfileClip.getRadius() * 2);
//            profilePictureImageView.setFitHeight(imageProfileClip.getRadius() * 2);
            profilePictureImageView.setImage(profileImage);
        }

    }

    @FXML
    public void onStartChatClickedHandler(MouseEvent mouseEvent) throws IOException {
        //validate();
        if(validInformation){
            Stage stage=(Stage) choosePictureButton.getScene().getWindow();
            FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("/gov/iti/jets/java/d01l01/views/ChatPane.fxml"));

            Scene scene = new Scene(fxmlLoader.load(), 600, 400);
            ChatPaneController controller = fxmlLoader.getController();
            System.out.println();
            controller.setDate(userFullNameTextField.getText(),profilePictureImageView.getImage());

            stage.setTitle("Hello!");
            stage.setScene(scene);
            stage.show();
        }
    }
    public void validate(){
        if(Objects.equals(userFullNameTextField.getText(), "")){
            validInformation = false;
        }
//        if(profilePictureImageView.getImage()==null){
//            validInformation = false;
//        }
    }
}
