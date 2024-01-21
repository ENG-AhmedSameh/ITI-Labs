package iti.java.d02l01.controllers;

import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.stage.DirectoryChooser;
import javafx.stage.Stage;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class folderStructurePaneController {

    @FXML
    private Button folderChooserButton;

    @FXML
    private TextField folderPathTextField;

    @FXML
    private AnchorPane listViewAnchorPane;

    @FXML
    private AnchorPane treeViewAnchorPane;

    @FXML
    private TreeView<File> folderBrowsingTreeView;

    @FXML
    private ListView<File> folderContentListView;

    @FXML
    void onFolderChooserClicked(MouseEvent event) {
        DirectoryChooser directoryChooser = new DirectoryChooser();
        directoryChooser.setTitle("Choose a Folder");

        File initialDirectory = new File(System.getProperty("user.home"));
        directoryChooser.setInitialDirectory(initialDirectory);

        Stage primaryStage = (Stage) folderChooserButton.getScene().getWindow();
        File selectedDirectory = directoryChooser.showDialog(primaryStage);

        if (selectedDirectory != null) {
            folderPathTextField.setText(selectedDirectory.getAbsolutePath());
            createTree(primaryStage,selectedDirectory);
        }
    }

    void createTree(Stage primaryStage, File rootDirectory){
        ImageView rootIcon = null;
        try {
            rootIcon = new ImageView(new Image(new FileInputStream("F:\\ITI Courses\\JAVA\\Advanced JavaFx\\Labs\\Day 2\\D02L01\\src\\main\\resources\\iti\\java\\d02l01\\images\\folderIcon.png")));
        } catch (FileNotFoundException e) {
            System.out.println("No Image Found");
        }
        //File rootDirectory = new File("F:\\ITI Courses");
        TreeItem<File> rootItem = new TreeItem<>(rootDirectory,rootIcon);
        populateTree(rootItem, rootDirectory);
        folderBrowsingTreeView.setRoot(rootItem);
        folderBrowsingTreeView.setCellFactory(treeView -> new TreeCell<>() {
            @Override
            protected void updateItem(File item, boolean empty) {
                super.updateItem(item, empty);
                if (empty || item == null) {
                    setText(null);
                    setGraphic(null);
                } else {
                    setText(item.getName());
                    Image icon = new Image(item.isDirectory() ? getClass().getResource("/iti/java/d02l01/images/folderIcon.png").toExternalForm() : getClass().getResource("/iti/java/d02l01/images/fileIcon.png").toExternalForm());
                    ImageView imageView = new ImageView(icon);
                    setGraphic(imageView);
                }
            }
        });
        folderBrowsingTreeView.getSelectionModel().selectedItemProperty().addListener((observable, oldValue, newValue) -> {
            if (newValue != null) {
                //if(newValue.getValue().isDirectory())
                updateListViewContents(newValue.getValue());
            }
        });
        folderContentListView.setCellFactory(listView -> new ListCell<>(){
            @Override
            protected void updateItem(File item, boolean empty) {
                super.updateItem(item, empty);
                if (empty || item == null) {
                    setText(null);
                    setGraphic(null);
                } else {
                    setText(item.getName());
                    Image icon = new Image(item.isDirectory() ? getClass().getResource("/iti/java/d02l01/images/folderIcon.png").toExternalForm() : getClass().getResource("/iti/java/d02l01/images/fileIcon.png").toExternalForm());
                    ImageView imageView = new ImageView(icon);
                    setGraphic(imageView);
                }
            }
        });
    }
    private void updateListViewContents(File selected) {
        if(selected.isDirectory()){
            File[] files = selected.listFiles();
            if (files != null) {
                folderContentListView.getItems().clear();
                for(File file:files)
                    folderContentListView.getItems().addAll(file);
            }
        }else{
            folderContentListView.getItems().clear();
            folderContentListView.getItems().addAll(selected);
        }

    }
    private void populateTree(TreeItem<File> parentItem, File parentFile) {
        File[] files = parentFile.listFiles();
        if (files != null) {
            for (File file : files) {
                TreeItem<File> newItem = new TreeItem<>(file);
                parentItem.getChildren().add(newItem);

                if (file.isDirectory()) {
                    populateTree(newItem, file);
                }
            }
        }
    }

}
