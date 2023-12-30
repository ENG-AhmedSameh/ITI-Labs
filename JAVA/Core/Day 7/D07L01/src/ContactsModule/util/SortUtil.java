package util;

import model.Contact;

import java.util.List;

public class SortUtil {
    public static List<Contact> sortList(List<Contact> contactsList){
        contactsList.sort((c1,c2)->(Integer.valueOf(c1.getId())-Integer.valueOf(c2.getId())));
        return contactsList;
    }
}