/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package notepad;

import java.io.ByteArrayOutputStream;
import java.io.File;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.SeparatorMenuItem;
import javafx.scene.control.TextArea;
import javafx.scene.layout.BorderPane;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import javax.tools.JavaCompiler;
import javax.tools.ToolProvider;

/**
 *
 * @author Ahmed Sameh
 */
public class NotePad extends Application {
    
    MenuBar topBar;
    
    Menu fileMenu;
    Menu editMenu;
    Menu helpMenu;
    
    MenuItem newMenuItem;
    MenuItem openMenuItem;
    MenuItem saveMenuItem;
    MenuItem exitMenuItem;
    
    MenuItem undoMenuItem;
    MenuItem cutMenuItem;
    MenuItem copyMenuItem;
    MenuItem pasteMenuItem;
    MenuItem deleteMenuItem;
    MenuItem selectAllMenuItem;
    
    MenuItem aboutMenuItem;
    MenuItem compileMenuItem;
    
    TextArea textArea;
    @Override
    public void init() throws Exception{
        topBar = new MenuBar();
        
        textArea = new TextArea();
        textArea.setPromptText("Write Text Here");
        
        initializeFileMenu();
        initializeEditMenu();
        initializeAboutMenu();
        
        topBar.getMenus().addAll(fileMenu,editMenu,helpMenu);

        super.init();
    }
    
    private void initializeFileMenu(){
        fileMenu = new Menu("File");
        newMenuItem = new MenuItem("New");
        openMenuItem = new MenuItem("Open...");
        saveMenuItem = new MenuItem("Save");
        exitMenuItem = new MenuItem("Exit");
        fileMenu.getItems().addAll(newMenuItem,openMenuItem,saveMenuItem,new SeparatorMenuItem(),exitMenuItem);
    }
    
    private void initializeEditMenu(){
        editMenu = new Menu("Edit");
        undoMenuItem = new MenuItem("Undo");
        cutMenuItem = new MenuItem("Cut");
        cutMenuItem.setDisable(true);
        copyMenuItem = new MenuItem("Copy");
        copyMenuItem.setDisable(true);
        pasteMenuItem = new MenuItem("Paste");
        deleteMenuItem = new MenuItem("Delete");
        deleteMenuItem.setDisable(true);
        selectAllMenuItem = new MenuItem("Select All");
        editMenu.getItems().addAll(undoMenuItem,new SeparatorMenuItem(),cutMenuItem,copyMenuItem,pasteMenuItem
                ,deleteMenuItem,new SeparatorMenuItem(),selectAllMenuItem);
    }
    
    private void initializeAboutMenu(){
        helpMenu = new Menu("Help");
        
        aboutMenuItem = new MenuItem("About Notepad");
        compileMenuItem = new MenuItem("Compile Java Code");
        helpMenu.getItems().addAll(aboutMenuItem,compileMenuItem);
    }
    
    private void setEditMenuItemsActions(){
        textArea.selectedTextProperty().addListener((observable, oldValue, newValue) -> {
            boolean isEmptySelectedText = newValue.isEmpty();
            copyMenuItem.setDisable(isEmptySelectedText);
            cutMenuItem.setDisable(isEmptySelectedText);
            deleteMenuItem.setDisable(isEmptySelectedText);
        });
        
        undoMenuItem.setOnAction(e -> {
            textArea.undo();
        });
        
        copyMenuItem.setOnAction(e->{
            textArea.copy();
        });
        pasteMenuItem.setOnAction(e->{
            textArea.paste();
        });
        deleteMenuItem.setOnAction(e->{
            textArea.replaceSelection("");
        });
        selectAllMenuItem.setOnAction(e->{
            textArea.selectAll();
        });
    }
    
    private void setFileMenuItemsActions(Stage primaryStage){
        newMenuItem.setOnAction(e->{
            displayConfirmationDialoug(primaryStage);
            textArea.clear();
        });
        openMenuItem.setOnAction(e->{
            displayConfirmationDialoug(primaryStage);
            openFile(primaryStage);
        });
        
        saveMenuItem.setOnAction(e->{
            saveToFile(primaryStage);
        });
        
        exitMenuItem.setOnAction(e->{
            displayConfirmationDialoug(primaryStage);
            System.exit(0);
        });
        
    }
    
    private void displayConfirmationDialoug(Stage primaryStage){
        if(!"".equals(textArea.getText())){
                Alert confirmationDialog = new Alert(AlertType.CONFIRMATION);
                confirmationDialog.setTitle("Confirmation");
                confirmationDialog.setHeaderText("Save first ?");
                confirmationDialog.setContentText("Do you want to save your current document first?");

                ButtonType buttonTypeSave = new ButtonType("Save");
                ButtonType buttonTypeNoSave = new ButtonType("Don't Save");
                confirmationDialog.getButtonTypes().setAll(buttonTypeSave, buttonTypeNoSave);
                confirmationDialog.showAndWait().ifPresent(response -> {
                    if (response == buttonTypeSave) {
                        saveToFile(primaryStage);
                    }
                });
            }
    }
    
    private void saveToFile(Stage primaryStage){
        FileChooser fileChooser = new FileChooser();

        fileChooser.setTitle("Save File");
        FileChooser.ExtensionFilter txtExt = new FileChooser.ExtensionFilter("Text Files (*.txt)", "*.txt");
        FileChooser.ExtensionFilter javaExt = new FileChooser.ExtensionFilter("Java Code (*.java)", "*.java");
        fileChooser.getExtensionFilters().addAll(txtExt,javaExt);

        File selectedFile = fileChooser.showSaveDialog(primaryStage);    
        if(selectedFile!=null)
            System.out.println("The Saved File location is : "+selectedFile.getAbsolutePath());
        
            
    }
    
    private void openFile(Stage primaryStage){
        FileChooser fileChooser = new FileChooser();

        fileChooser.setTitle("Open File");
        FileChooser.ExtensionFilter txtExt = new FileChooser.ExtensionFilter("Text Files (*.txt)", "*.txt");
        FileChooser.ExtensionFilter javaExt = new FileChooser.ExtensionFilter("Java Code (*.java)", "*.java");
        fileChooser.getExtensionFilters().addAll(txtExt,javaExt);

        File selectedFile = fileChooser.showOpenDialog(primaryStage);    
        if(selectedFile!=null)
            System.out.println("The opened File location is : "+selectedFile.getAbsolutePath());
        
            
    }
    
    private void setAboutMenuItemsActions(){
        aboutMenuItem.setOnAction(e->{
            Alert confirmationDialog = new Alert(AlertType.INFORMATION);
            confirmationDialog.setTitle("About Us");
            confirmationDialog.setHeaderText("Credits to : ");
            confirmationDialog.setContentText("© Ahmed Sameh");
            confirmationDialog.showAndWait();
        });
        
//        compileMenuItem.setOnAction(e->{
//            compileAndRun();
//        });
    }
    /*public void compileAndRun() {
                String userCode = textArea.getText();

                JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
                ByteArrayOutputStream output = new ByteArrayOutputStream();
                 int compileResult = compiler.run(null, output, null, userCode);

                if (compileResult != 0) {
                    return;
                }

                String resultText = output.toString();
                System.out.println(resultText);

            }  */
    
    
    
    @Override
    public void start(Stage primaryStage) {
        
        setFileMenuItemsActions(primaryStage);
        setEditMenuItemsActions();
        setAboutMenuItemsActions();
        BorderPane root = new BorderPane();
        root.setTop(topBar);
        root.setCenter(textArea);
        
        Scene scene = new Scene(root, 300, 250);
        
        primaryStage.setTitle("NotePad");
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
