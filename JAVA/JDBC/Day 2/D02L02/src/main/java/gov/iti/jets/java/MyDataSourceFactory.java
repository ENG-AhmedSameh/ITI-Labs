package gov.iti.jets.java;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

import javax.sql.DataSource;

import com.mysql.cj.jdbc.MysqlDataSource;

class MyDataSourceFactory {
    public static DataSource getMySQLDataSource() {
        Properties prop = new Properties();
        FileInputStream fis = null;
        MysqlDataSource mysqlDS = null;
        try {
            fis = new FileInputStream("db.properties");
            prop.load(fis);
            mysqlDS = new MysqlDataSource();
            mysqlDS.setURL(prop.getProperty("MYSQL_DB_URL"));
            mysqlDS.setUser(prop.getProperty("MYSQL_DB_USERNAME"));
            mysqlDS.setPassword(prop.getProperty("MYSQL_DB_PASSWORD"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return mysqlDS;
    }
}
