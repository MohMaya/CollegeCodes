package Encryption_Decryption;

import java.util.ArrayList;

/**
 * Created by sanchit on 2/8/17.
 */
public class TranspositionCipher {

    public static String encryptor(String str,int rails){
        String finalString="";
        if(str.isEmpty())
            return str;
        ArrayList<String>  encryptedMessage=new ArrayList<>();

        // Initialising Encrypted Message
        for (int i = 0; i <rails ; i++) {
            encryptedMessage.add("");
        }
        // adding Char by Char in rails
        for (int i = 0; i <str.length() ; i++) {
            encryptedMessage.set(i%rails,encryptedMessage.get(i%rails)+str.charAt(i));
        }
        // addind $ to mark the end of the line
        for (int i = 0; i <rails ; i++) {
            finalString+=encryptedMessage.get(i)+"$";
        }
        return finalString;
    }
    public static String decryptor(String str){
        ArrayList<String> railString=new ArrayList<>();
        StringBuilder tempString=new StringBuilder();
        StringBuilder finalString=new StringBuilder();
        //Getting the rails by segregating with thehelp of $
        for (int i = 0; i <str.length() ; i++) {
            if(str.charAt(i)=='$')
            {
                railString.add(tempString.toString());
                tempString=new StringBuilder();
            }
            else{
                tempString.append(str.charAt(i));
            }

        }
        // code for Decrypting Rails
        int counter=0,flag=1;
        while (flag<=railString.size()){
        for (int i = 0; i <railString.size(); i++) {
            if (counter < railString.get(i).length())
                finalString.append(railString.get(i).charAt(counter));
            else
                ++flag;
        }
        counter++;
        }
        return finalString.toString();
    }
    public static void main(String args[]){

        String encString=encryptor("WE ARE DISCOVERED. FLEE AT ONCE",3);
        System.out.println(encString);
        String decrypted=decryptor(encString);
        System.out.println(decrypted);


    }
}
