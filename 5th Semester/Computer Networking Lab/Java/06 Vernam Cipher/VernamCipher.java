package Encryption_Decryption;

import java.util.Scanner;

/**
 * Created by sanchit on 22/8/17.
 */
public class VernamCipher {

//    Function for Encrypting Text
    public static String encryptor(String message,String key){
        StringBuilder stringBuilder=new StringBuilder();
        if(message.length()!=key.length())
            return null;
        for (int i = 0; i <message.length() ; i++) {
            //Logic
            int value=message.charAt(i)+key.charAt(i);
            value%=128;
            int newValue=value%128;
            if(newValue<0)
                newValue+=128;
            stringBuilder.append((char)newValue);
        }

        return stringBuilder.toString();
    }
    //    Function for Decrypting Text
    public static String decryptor(String message,String key){
        StringBuilder stringBuilder=new StringBuilder();
        if(message.length()!=key.length())
            return null;
        for (int i = 0; i <message.length() ; i++) {
            //Logic
            int value=message.charAt(i)-key.charAt(i);
            int newValue=value%128;
            if(newValue<0)
                newValue+=128;

            stringBuilder.append((char)newValue);
        }

        return stringBuilder.toString();
    }
    public static void main(String args[]){
        String key,message,encrypedMessage,decryptedMessage;
        Scanner scanner=new Scanner(System.in);
        System.out.println("Enter Message");
        message=scanner.nextLine();
        System.out.println("Enter key");
        key=scanner.nextLine();
        if(key.length()==message.length()){
            encrypedMessage=encryptor(message,key);
            System.out.println("Encrypted Message: "+encrypedMessage);

            decryptedMessage=decryptor(encrypedMessage,key);
            System.out.println("Decrypted Message: "+decryptedMessage);
        }
        else{
            System.out.println("Invalid key");
        }
    }
}
