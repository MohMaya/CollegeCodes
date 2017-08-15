package Encryption_Decryption;

import java.util.ArrayList;

/**
 * Created by sanchit on 15/8/17.
 */
public class HillCipher {
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


    public static void main(String args[]){
        float [][]a={{9,3,5},{-6,-9,7},{-1,-8,1}};
//        for (float i = 0; i <3 ; i++) {
//            for (float j = 0; j <3 ; j++) {
//               float[][]z= cofactors(a,i,j);
//                for (float k = 0; k < 2; k++) {
//                    for (float l = 0; l <2 ; l++) {
//                        System.out.print(" "+z[k][l]);
//                    }
//                    System.out.println();
//                }
//                System.out.println();
//            }
//        }
        float[][]b=makeKey("IFKVIVVMI");
        for (int i = 0; i <3 ; i++) {
            for (int j = 0; j <3 ; j++) {
                System.out.print(" "+b[i][j]);
            }
            System.out.println();
        }
        String encryptedMess=encrypt("heybaby","GYBNQKURP");
        System.out.println("Encrypted Message "+encryptedMess);
        System.out.println("Decrypted Message "+decrypt(encryptedMess,"GYBNQKURP"));
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
public static String encrypt(String message,String key){
    String finalMessage="";
    message=message.toUpperCase().replace(" ","");
    float[][] matKey=makeKey(key);
    int rem=message.length()%3;
    ArrayList<ThreeSet> setArrayList=new ArrayList<>();
    if(rem!=0){
        for (int i = 0; i <3-rem ; i++) {
            message=message+"X";
        }
    }
    for (int i = 0; i <message.length() ; i=i+3) {
        setArrayList.add(new ThreeSet(message.charAt(i)-65,message.charAt(i+1)-65,message.charAt(i+2)-65));
    }
    for (int j = 0; j < setArrayList.size(); j++) {

        for (int i = 0; i <3 ; i++) {
//            System.out.println((((matKey[i][0]*setArrayList.get(j).first+matKey[i][1]*setArrayList.get(j).second+matKey[i][2]*setArrayList.get(j).third)%26)));
            finalMessage+=(char)(((matKey[i][0]*setArrayList.get(j).first+matKey[i][1]*setArrayList.get(j).second+matKey[i][2]*setArrayList.get(j).third)%26)+65);
        }
    }

return finalMessage;
}
public static String decrypt(String message,String key){
    String finalMessage="";
    message=message.toUpperCase().replace(" ","");
    float[][] matKey=makeKey(key);
    float[][] invKey=inverse(matKey);

    ArrayList<ThreeSet> setArrayList=new ArrayList<>();
    for (int i = 0; i <message.length() ; i=i+3) {
        setArrayList.add(new ThreeSet(message.charAt(i)-65,message.charAt(i+1)-65,message.charAt(i+2)-65));
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
static class ThreeSet{
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
