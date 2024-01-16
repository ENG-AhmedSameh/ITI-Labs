package gov.iti.jets.java.d01l01.Controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.VBox;

import java.io.IOException;
import java.util.Objects;

public class ChatPaneController {

    @FXML
    private Label fullNameTextField;

    @FXML
    private ImageView imageProfilePictureImageView;

    @FXML
    private TextField messageTextField;

    @FXML
    private ScrollPane messagesScrollPane;

    @FXML
    private VBox messagesVBox;

    @FXML
    private Button sendButton;

    public void setDate(String text, Image image){
        fullNameTextField.setText(text);
        imageProfilePictureImageView.setImage(image);
    }


    @FXML
    void onMessageSentHandler(ActionEvent event) {

    }

    public void sendMessageHandler(ActionEvent event) {
        appendMessage(messageTextField.getText());
    }
    private void appendMessage(String messageString) {
        try {
            Node node = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("/gov/iti/jets/java/d01l01/views/messagePane.fxml")));

            Label messagelabel = (Label) node.lookup("#messageLabel");
            messagelabel.setText(messageString);
            messagelabel.setWrapText(true);
            messageTextField.setText("");
            messagesScrollPane.setVvalue(1D);

            messagesVBox.getChildren().add(node);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
