import Encryption_Decryption.HillCipher;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by sanchit on 16/8/17.
 */
public class HillCipherClient {

    public static float[][]cofactors(float[][]mat,float row,float col){
        float [][]cof=new float[2][2];
        int temprow=0,tempcol=0;
        for (int i = 0; i <3 ; i++) {
            for (int j = 0; j <3 ; j++) {
                if(i!=row&&j!=col){
                    if(tempcol<2)
                        cof[temprow][tempcol++]=mat[i][j];
                    else{
                        temprow++;
                        tempcol=0;
                        cof[temprow][tempcol++]=mat[i][j];
                    }
                }
            }
        }
        return cof;
    }
    public static float[][] makeKey(String key){
        float[][] mat=new float[3][3];
        key.toUpperCase();
        int count=0;
        for (int i = 0; i <3 ; i++) {
            for (int j = 0; j <3 ; j++) {
                mat[i][j]=key.charAt(count++)-65;
            }
        }
        return mat;
    }
    public static float determinant(float[][]mat){
        return (mat[0][0]*mat[1][1])-(mat[1][0]*mat[0][1]);
    }
    public static String encrypt(String message,String key){
        String finalMessage="";
        message=message.toUpperCase().replace(" ","");
        float[][] matKey=makeKey(key);
        int rem=message.length()%3;
        ArrayList<HillCipherClient.ThreeSet> setArrayList=new ArrayList<>();
        if(rem!=0){
            for (int i = 0; i <3-rem ; i++) {
                message=message+"X";
            }
        }
        for (int i = 0; i <message.length() ; i=i+3) {
            setArrayList.add(new HillCipherClient.ThreeSet(message.charAt(i)-65,message.charAt(i+1)-65,message.charAt(i+2)-65));
        }
        for (int j = 0; j < setArrayList.size(); j++) {

            for (int i = 0; i <3 ; i++) {
//            System.out.println((((matKey[i][0]*setArrayList.get(j).first+matKey[i][1]*setArrayList.get(j).second+matKey[i][2]*setArrayList.get(j).third)%26)));
                finalMessage+=(char)(((matKey[i][0]*setArrayList.get(j).first+matKey[i][1]*setArrayList.get(j).second+matKey[i][2]*setArrayList.get(j).third)%26)+65);
            }
        }

        return finalMessage;
    }
    public static void main(String args[]){
        int port=8085;
        try {
            Scanner scn=new Scanner(System.in);
            Socket socket=new Socket("127.0.0.1",port);
            System.out.println("BaseClient Connected to "+socket.getRemoteSocketAddress());
            String key="",clientText="";

            InputStream ios= socket.getInputStream();
            DataInputStream dataInputStream=new DataInputStream(ios);

            DataOutputStream dataOutputStream=new DataOutputStream(socket.getOutputStream());
            while(true){
                System.out.println("Put your Text");
                clientText=scn.nextLine();
                System.out.println("ENTER KEY");
                key=scn.nextLine();
                String encryptedMessage=encrypt(clientText,key);
                dataOutputStream.writeUTF(encryptedMessage);
                System.out.println("Encrypted Message "+encryptedMessage);

            }
        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
    static class ThreeSet {
        float first;
        float second;
        float third;

        public ThreeSet(float first, float second, float third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }


    }


}
