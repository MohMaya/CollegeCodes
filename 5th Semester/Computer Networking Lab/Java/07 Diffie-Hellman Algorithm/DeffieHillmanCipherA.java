import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by pramo on 29-08-2017.
 */
public class DeffieHillmanCipherA {
public static int findMod(int number,int exponent,int mod){
    int finalMod=number%mod;
    for (int i = 0; i <exponent-1 ; i++) {
        finalMod=(finalMod*number)%mod;
    }
return finalMod;
}
    public static void main(String args[]){
    HashMap<Integer,Integer[]> pgMap=new HashMap<Integer,Integer[]>();
    pgMap.put(1 , new Integer[]{0});
    pgMap.put(2 , new Integer[]{1});
    pgMap.put(3 , new Integer[]{2});
    pgMap.put(4 , new Integer[]{3});
    pgMap.put(5 , new Integer[]{2,3});
    pgMap.put(6 , new Integer[]{5});
    pgMap.put(7 , new Integer[]{3,5});
    pgMap.put(9 , new Integer[]{2,5});
    pgMap.put(10, new Integer[]{3, 7});
    pgMap.put(11, new Integer[]{2, 6, 7, 8});
    pgMap.put(13, new Integer[]{2, 6, 7, 11});
    pgMap.put(14, new Integer[]{3, 5});
    pgMap.put(17, new Integer[]{3, 5, 6, 7, 10, 11, 12, 14});
    pgMap.put(18, new Integer[]{5, 11});
    pgMap.put(19, new Integer[]{2, 3, 10, 13, 14, 15});
    pgMap.put(22, new Integer[]{7, 13, 17, 19});
    pgMap.put(23, new Integer[]{5, 7, 10, 11, 14, 15, 17, 19, 20, 21});
    pgMap.put(25, new Integer[]{2, 3, 8, 12, 13, 17, 22, 23});
    pgMap.put(26, new Integer[]{7, 11, 15, 19});
    pgMap.put(27, new Integer[]{2, 5, 11, 14, 20, 23});
    pgMap.put(29, new Integer[]{2, 3, 8, 10, 11, 14, 15, 18, 19, 21, 26, 27});
    pgMap.put(31, new Integer[]{3, 11, 12, 13, 17, 21, 22, 24});
    pgMap.put(34, new Integer[]{3, 5, 7, 11, 23, 27, 29, 31});
    pgMap.put(37, new Integer[]{2, 5, 13, 15, 17, 18, 19, 20, 22, 24, 32, 35});
    pgMap.put(38, new Integer[]{3, 13, 15, 21, 29, 33});
    pgMap.put(41, new Integer[]{6, 7, 11, 12, 13, 15, 17, 19, 22, 24, 26, 28, 29, 30, 34, 35});
    pgMap.put(43, new Integer[]{3, 5, 12, 18, 19, 20, 26, 28, 29, 30, 33, 34});
    pgMap.put(46, new Integer[]{5, 7, 11, 15, 17, 19, 21, 33, 37, 43});
    pgMap.put(47, new Integer[]{5, 10, 11, 13, 15, 19, 20, 22, 23, 26, 29, 30, 31, 33, 35, 38, 39, 40, 41, 43, 44, 45});
    pgMap.put(49, new Integer[]{3, 5, 10, 12, 17, 24, 26, 33, 38, 40, 45, 47});
    pgMap.put(50, new Integer[]{3, 13, 17, 23, 27, 33, 37, 47});
    pgMap.put(53, new Integer[]{2, 3, 5, 8, 12, 14, 18, 19, 20, 21, 22, 26, 27, 31, 32, 33, 34, 35, 39, 41, 45, 48, 50, 51});
    pgMap.put(54, new Integer[]{5, 11, 23, 29, 41, 47});
    pgMap.put(58, new Integer[]{3, 11, 15, 19, 21, 27, 31, 37, 39, 43, 47, 55});
    pgMap.put(59, new Integer[]{2, 6, 8, 10, 11, 13, 14, 18, 23, 24, 30, 31, 32, 33, 34, 37, 38, 39, 40, 42, 43, 44, 47, 50, 52, 54, 55, 56});
    pgMap.put(61, new Integer[]{2, 6, 7, 10, 17, 18, 26, 30, 31, 35, 43, 44, 51, 54, 55, 59});
    pgMap.put(62, new Integer[]{3, 11, 13, 17, 21, 43, 53, 55});
    pgMap.put(67, new Integer[]{2, 7, 11, 12, 13, 18, 20, 28, 31, 32, 34, 41, 44, 46, 48, 50, 51, 57, 61, 63});
    pgMap.put(71, new Integer[]{7, 11, 13, 21, 22, 28, 31, 33, 35, 42, 44, 47, 52, 53, 55, 56, 59, 61, 62, 63, 65, 67, 68, 69});

    ServerSocket serverSocket;
    int port=8085;
    Scanner scn=new Scanner(System.in);
    int p,y,g,myKey;
    try {
         serverSocket=new ServerSocket(port);
        serverSocket.setSoTimeout(30*1000);
        System.out.println("A Says: Client Connected to Server at port "+serverSocket.getLocalPort());
        Socket socket=serverSocket.accept();
        System.out.println("A Says: Client Connected "+socket.getLocalAddress());
        while (true) {
            System.out.println("Enter A Valid Value of p Exponent in range [1 - 71] : ");
            p=scn.nextInt();
            if(pgMap.containsKey(p))
            break;
        else
            System.out.println("Please Choose A Valid Value !!");
        }
        while (true) {
            System.out.print("Choose a value of g Base from  ");
            for(int i:pgMap.get(p)){
                System.out.print(" "+i);
            }
            System.out.println();
            g=scn.nextInt();
            if(Arrays.binarySearch(pgMap.get(p),g)>=0){
                break;
            }

            else
                System.out.println("Please Choose A Valid Value !!");
        }
        System.out.println("Choose a secret Number");
        y=scn.nextInt();
        System.out.println("P "+p+" G "+g);
        DataOutputStream dataOutputStream=new DataOutputStream(socket.getOutputStream());
        if(dataOutputStream!=null)
        dataOutputStream.writeUTF(String.valueOf(findMod(g,y,p)));
        DataInputStream dataInputStream=new DataInputStream(socket.getInputStream());
        while (true){
            if(dataInputStream!=null&&dataInputStream.available()>0){
                String Btext=dataInputStream.readUTF();
                int b=Integer.parseInt(Btext);
                myKey=(findMod(b,y,p));
                System.out.println("MY SHARED KEY "+myKey);

                break;
            }
        }

    } catch (IOException e) {
        e.printStackTrace();
    }



}
}
