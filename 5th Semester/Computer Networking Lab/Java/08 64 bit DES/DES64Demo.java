package DES64bit;

import java.util.HashMap;

public class DES64Demo {
    static String message = "1111110010001001110110111000111001111000011010101010101010101010";
    static String[] keys = {"11100000010111010100001100110101000100110111111100110101", "10001110111111110111101110010100010111010010010011110111" , "10001001101111101110110110101100110011100111100100101101", "11101000110110011001100011000001001001000001010111101001" ,"10011000000001011011100111000001000111100100011000111000","00011111011010000110001101111100011001011100111110011101","01100001101000100100110101001111010100000001110110111011","00001100001101011000011100100010101011000000001100111101","11011010100110100011001011010001110111111111010101111010","01111001111101010011001101010011001100110100010001100110","01101101110001111000101000000000010011101100101100110000","10111101101110001000011011001010100110000011000000110111","01010100101111101001001101000101001001011010100101011000","01010100111111010101001010111101111011001010001110110010","11010101101010000011011100010010110100010100110101011101","00011100110101000001001000001010110011011001110101100101"};





    static int []initial_permu_index={58 ,50 ,42 ,34 ,26 ,18 ,10 ,2,60 ,52 ,44 ,36 ,28 ,20 ,12 ,4,62 ,54 ,46 ,38 ,30 ,22 ,14 ,6,64 ,56 ,48 ,40 ,32 ,24, 16, 8,57, 49, 41, 33, 25, 17, 9 ,1,59, 51, 43, 35, 27, 19, 11, 3,61 ,53 ,45 ,37 ,29 ,21 ,13 ,5,63 ,55 ,47 ,39 ,31 ,23 ,15 ,7};
    static int []expansion_table={32 ,1 ,2 ,3 ,4 ,5,4 ,5 ,6 ,7 ,8 ,9,8 ,9 ,10 ,11 ,12 ,13,12 ,13 ,14 ,15 ,16 ,17,16 ,17 ,18 ,19 ,20 ,21,20 ,21 ,22 ,23 ,24 ,25,24 ,25 ,26 ,27 ,28 ,29,28 ,29 ,30 ,31 ,32 ,1};
    static int[][]   sBox_array = {{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},{0 ,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},{4,1	,14	,8	,13	,6	,2	,11	,15	,12	,9	,7	,3	,10	,5	,0},{15	,12	,8	,2	,4	,9	,1	,7	,5	,11	,3	,14	,10	,0	,6	,13}};

    static int binary_to_int_4bit(String binary){
    HashMap<String,Integer> map=new HashMap<String,Integer>();
    map.put("0000",0);
    map.put("0001",1);
    map.put("0010",2);
    map.put("0011",3);
    map.put("0100",4);
    map.put("0101",5);
    map.put("0110",6);
    map.put("0111",7);
    map.put("1000",8);
    map.put("1001",9);
    map.put("1010",10);
    map.put("1011",11);
    map.put("1100",12);
    map.put("1101",13);
    map.put("1110",14);
    map.put("1111",15);
    return map.get(binary);
}
    static int binary_to_int_2bit(String binary){
    HashMap<String,Integer> map=new HashMap<String,Integer>();
    map.put("00",0);
    map.put("01",1);
    map.put("10",2);
    map.put("11",3);
    return map.get(binary);
}
    static String int_to_binary_4bit(Integer number){
    HashMap<Integer,String> map=new HashMap<Integer, String>();
    map.put(0,"0000");
    map.put(1,"0001");
    map.put(2,"0010");
    map.put(3,"0011");
    map.put(4,"0100");
    map.put(5,"0101");
    map.put(6,"0110");
    map.put(7,"0111");
    map.put(8,"1000");
    map.put(9,"1001");
    map.put(10,"1010");
    map.put(11,"1011");
    map.put(12,"1100");
    map.put(13,"1101");
    map.put(14,"1110");
    map.put(15,"1111");
    return map.get(number);


}
//Initial Permutation
static  String initialPermutation(String value){
        StringBuilder inverted=new StringBuilder();
        for(int i=0;i<initial_permu_index.length;i++){
            inverted.append(value.charAt(initial_permu_index[i]-1));
        }
        return inverted.toString();
    }
//Expansion
static  String expansion(String right32bits){
        StringBuilder expanded=new StringBuilder();
        for(int i=0;i<expansion_table.length;i++){
            expanded.append(right32bits.charAt(expansion_table[i]-1));
        }
        return expanded.toString();
    }

// XOR with 48 bit key expanded value
static String XOR(String message1,String message2){
        StringBuilder xoredmessage=new StringBuilder();
        if(message1.length()==message2.length()){
            for (int i = 0; i <message1.length(); i++) {
                xoredmessage.append(String.valueOf(Integer.parseInt(String.valueOf(message1.charAt(i)))^Integer.parseInt(String.valueOf(message2.charAt(i)))));
            }
        }
        else{
            System.out.println("Message length not same");
        }

        return xoredmessage.toString();
    }
    static String compress(String value_to_compress) {
        int col = binary_to_int_4bit(value_to_compress.substring(1, 5));
        int row = binary_to_int_2bit(String.valueOf(value_to_compress.charAt(0)) +String.valueOf(value_to_compress.charAt(value_to_compress.length()-1)));
//   System.out.println("Col : "+ col+ " Row : "+ row);
       String  compressed_value = sBox(col, row);
//        System.out.println("Compressed "+ compressed_value);
  //  #print(len(compressed_value))

        return compressed_value;

    }
    static String sBox(int col,int row){
        return int_to_binary_4bit(sBox_array[row][col]);

    }
    static   String func(String right,String key){
        StringBuilder primaryXOR=new StringBuilder();
        //key xored with right bits
        for (int i = 0; i <right.length() ; i++) {
            primaryXOR.append(String.valueOf(Integer.parseInt(String.valueOf(right.charAt(i)))^Integer.parseInt(String.valueOf(key.charAt(i)))));

        }
    // Now to compress 48 bits to 32 using sbox
           StringBuilder XOR_to_send=new StringBuilder();
        for (int i = 0; i < 48; i=i+6) {
            XOR_to_send.append(compress(primaryXOR.substring(i,i+6)));
        }
//        System.out.println("Xor ");
//        System.out.println(XOR_to_send);
      return XOR_to_send.toString();

    }
    //Right Exapansion and sboc processing
    static  String round_right_processing(String right,String key){
        String expandedRight=expansion(right);
        String valueTobeXored=func(expandedRight,key.substring(0,48));
        return valueTobeXored;
    }
    static  String encryptor(String message){
//        StringBuilder encryptedmessage=new StringBuilder(message);
        String lefthalf="",righthalf="",fiestaled_value="",newright="",newmessage=message;
        for (int i = 0; i <16 ; i++) {
            lefthalf=newmessage.substring(0,32);
            righthalf=newmessage.substring(32,64);
            fiestaled_value=round_right_processing(righthalf,keys[i]);
            newright=XOR(lefthalf,fiestaled_value);
            newmessage=righthalf+newright;
        }
        lefthalf=newmessage.substring(0,32);
        righthalf=newmessage.substring(32,64);
        newmessage=righthalf+lefthalf;
        return newmessage;
    }
    static String Decryptor(String message){
        String lefthalf="",righthalf="",fiestaled_value="",newright="",newmessage=message;
        for (int i = 0; i <16 ; i++) {
            lefthalf=newmessage.substring(0,32);
            righthalf=newmessage.substring(32,64);
            fiestaled_value=round_right_processing(righthalf,keys[15-i]);
            newright=XOR(lefthalf,fiestaled_value);
            newmessage=righthalf+newright;
        }
        lefthalf=newmessage.substring(0,32);
        righthalf=newmessage.substring(32,64);
        newmessage=righthalf+lefthalf;
        return newmessage;
    }
    public static void main(String args[]){
    System.out.println("Encrypted Message"+encryptor(message));
    System.out.println("initial   Message"+(message));
    System.out.println("Decrypted Message"+Decryptor(encryptor(message)));

    }
}
