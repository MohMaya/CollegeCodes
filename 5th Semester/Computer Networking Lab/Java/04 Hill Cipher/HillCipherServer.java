import Encryption_Decryption.HillCipher;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by sanchit on 16/8/17.
 */
public class HillCipherServer {

    public static float[][]inverse(float[][]mat){
        float[][]inv=new float[3][3];
        float sign=1,modDet=0;
        float det=mat[0][0]*determinant(cofactors(mat,0,0))
                -mat[0][1]*determinant(cofactors(mat,0,1))
                +mat[0][2]*determinant(cofactors(mat,0,2));
        System.out.println("determinant "+det);
        while (true) {
            if ((det * modDet) % 26 == 1)
                break;
            modDet++;
        }
        for (int i = 0; i <3 ; i++) {
            for (int j = 0; j < 3; j++) {
                if(sign>0){
                    inv[j][i]=((sign*determinant(cofactors(mat,i,j)))*modDet)%26;
                    sign*=-1;
                }
                else{
                    inv[j][i]=((sign*determinant(cofactors(mat,i,j)))*modDet)%26;
                    sign*=-1;
                }
            }
        }
        return inv;
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
    public static float determinant(float[][]mat){
        return (mat[0][0]*mat[1][1])-(mat[1][0]*mat[0][1]);
    }

    public static String decrypt(String message,String key){
        String finalMessage="";
        message=message.toUpperCase().replace(" ","");
        float[][] matKey=makeKey(key);
        float[][] invKey=inverse(matKey);

        ArrayList<HillCipherServer.ThreeSet> setArrayList=new ArrayList<>();
        for (int i = 0; i <message.length() ; i=i+3) {
            setArrayList.add(new HillCipherServer.ThreeSet(message.charAt(i)-65,message.charAt(i+1)-65,message.charAt(i+2)-65));
        }

//    System.out.println();
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j <3 ; j++) {
//            System.out.print(" "+invKey[i][j]);
//        }
//        System.out.println();
//    }
        for (int j = 0; j < setArrayList.size(); j++) {

            for (int i = 0; i <3 ; i++) {
                int z= (int) ((invKey[i][0]*setArrayList.get(j).first+invKey[i][1]*setArrayList.get(j).second+invKey[i][2]*setArrayList.get(j).third)%26);
                if(z<0)
                    z+=26;
//            finalMessage+=(char)(((invKey[i][0]*setArrayList.get(j).first+invKey[i][1]*setArrayList.get(j).second+invKey[i][2]*setArrayList.get(j).third)%26)+65);
                finalMessage+=(char)(z+65);
            }
        }
        return finalMessage.replace("X","");
    }
    public static void main(String args[]){
        int port=8085;
        try {
            Scanner scn=new Scanner(System.in);
            ServerSocket serverSocket=new ServerSocket(port);
            serverSocket.setSoTimeout(10000);
            System.out.println("Server Says: Client Connected to Server at port "+serverSocket.getLocalPort());
            Socket socket=serverSocket.accept();
            System.out.println("Server Says: Client Connected "+socket.getLocalAddress());
            String clientText="",key="";
            InputStream ios= socket.getInputStream();
            DataInputStream dataInputStream=new DataInputStream(ios);

            DataOutputStream dataOutputStream=new DataOutputStream(socket.getOutputStream());
            // This stops
            while(true){
                if(ios.available()>0) {
                    clientText = dataInputStream.readUTF();
                    System.out.println("ENTER KEY");
                    key=scn.nextLine();
                    if (!clientText.isEmpty())
                        System.out.println("Client Says: " + decrypt(clientText,key));
                    else
                        System.out.println("Client Text Empty: ");
                }
                else{
//                    System.out.println("Server:Client Didn't Write anything");
                }
            }


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
