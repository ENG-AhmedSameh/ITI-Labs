package util;

import model.Contact;

import java.util.ArrayList;
import java.util.List;

public class ContactUtil{
    Contact c1 = new Contact("1","Ahmed","Sameh","011","010","ahmedsameh@gmail.com");
    Contact c2 = new Contact("3","Omar","Mohamed","011","010","omarMohamed@gmail.com");
    Contact c3 = new Contact("2","Mohamed","Nofal","011","010","Nofal@gmail.com");
    public List<Contact>getContacts(){
        ArrayList l1 = new ArrayList<>();
        l1.add(c1);
        l1.add(c2);
        l1.add(c3);
        return l1;
    }
}