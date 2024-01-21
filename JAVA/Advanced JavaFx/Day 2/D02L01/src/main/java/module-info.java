module iti.java.d02l01 {
    requires javafx.controls;
    requires javafx.fxml;


    opens iti.java.d02l01.controllers to javafx.fxml;
    exports iti.java.d02l01;
}