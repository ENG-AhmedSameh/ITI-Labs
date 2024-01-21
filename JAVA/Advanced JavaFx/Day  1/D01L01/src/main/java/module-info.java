module gov.iti.jets.java.d01l01 {
    requires javafx.controls;
    requires javafx.fxml;


    opens gov.iti.jets.java.d01l01 to javafx.fxml;
    exports gov.iti.jets.java.d01l01;
    exports gov.iti.jets.java.d01l01.Controllers;
    opens gov.iti.jets.java.d01l01.Controllers to javafx.fxml;
}