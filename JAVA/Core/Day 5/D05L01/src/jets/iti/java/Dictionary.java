package jets.iti.java;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeSet;

//computeIfAbsent
public class Dictionary {
    Map<Character, TreeSet<String>> hashMap = new HashMap<>();
    public Dictionary(String[] words){
        for(String word:words){
            addWord(word);
        }
    }
    public void printDictionary(){
        hashMap.forEach((k,t)->{
            getWordsOfChar(k);
        });
    }
    public void addWord(String word){
        if(word.length()<=0)
            System.out.println("Can't add this String");
        else {
            if (!hashMap.containsKey(Character.toUpperCase(word.charAt(0))))
                hashMap.put(Character.toUpperCase(word.charAt(0)), new TreeSet<String>(Arrays.asList(word.toLowerCase())));
            else
                hashMap.get(Character.toUpperCase(word.charAt(0))).add(word.toLowerCase());
        }
    }
    public void getWordsOfChar(char k){
        if(hashMap.containsKey(Character.toUpperCase(k)))
            System.out.println("The Key "+k+" contains Words: "+hashMap.get(Character.toUpperCase(k)));
        else
            System.out.println("Please Enter a valid character");
    }
}
