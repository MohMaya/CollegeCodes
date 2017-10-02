initial_permu_index=[58 ,50 ,42 ,34 ,26 ,18 ,10 ,2,60 ,52 ,44 ,36 ,28 ,20 ,12 ,4,62 ,54 ,46 ,38 ,30 ,22 ,14 ,6,64 ,56 ,48 ,40 ,32 ,24, 16, 8,57, 49, 41, 33, 25, 17, 9 ,1,59, 51, 43, 35, 27, 19, 11, 3,61 ,53 ,45 ,37 ,29 ,21 ,13 ,5,63 ,55 ,47 ,39 ,31 ,23 ,15 ,7]

inverse_permu_index=[40, 8 ,48 ,16 ,56 ,24 ,64 ,32,39 ,7 ,47 ,15 ,55 ,23 ,63 ,31,38 ,6 ,46 ,14 ,54 ,22 ,62 ,30,37 ,5 ,45 ,13 ,53 ,21 ,61 ,29,36 ,4 ,44 ,12 ,52 ,20 ,60 ,28,35 ,3 ,43 ,11 ,51 ,19 ,59 ,27,34,2, 42, 10,50,18,58 , 26,33 ,1 ,41 ,9 ,49 ,17 ,57 ,25,]

expansion_table=[32 ,1 ,2 ,3 ,4 ,5,4 ,5 ,6 ,7 ,8 ,9,8 ,9 ,10 ,11 ,12 ,13,12 ,13 ,14 ,15 ,16 ,17,16 ,17 ,18 ,19 ,20 ,21,20 ,21 ,22 ,23 ,24 ,25,24 ,25 ,26 ,27 ,28 ,29,28 ,29 ,30 ,31 ,32 ,1,]

permu_table=[16 ,7 ,20 ,21 ,29 ,12 ,28 ,17,1 ,15 ,23 ,26 ,5 ,18 ,31 ,10,2 ,8,24 ,14 ,32 ,27 ,3 ,9,19 ,13 ,30 ,6 ,22 ,11 ,4 ,25]



def final_permu(value):
    inverted = ''
    for i in inverse_permu_index:
        inverted += value[i-1]
    return inverted



def iniPermu(original_message):
    mess = ''
    for i in initial_permu_index:
        mess += message[i-1]

    return mess



def expansion(right_half):
    expanded_right = ''
    for i in expansion_table:
        expanded_right += right_half[i-1]
    return expanded_right



def binary_to_int_4bit(binary):
    binary_to_int_4b = {'0000':0,'0001':1,'0010':2,'0011':3,'0100':4,'0101':5,'0110':6,'0111':7,'1000':8,'1001':9,'1010':10,'1011':11,'1100':12,'1101':13,'1110':14,'1111':15}
    x = binary_to_int_4b[binary]
    return x



def binary_to_int_2bit(binary):
    binary_to_int_2b = {'00':0,'01':1,'10':2,'11':3}
    return binary_to_int_2b[binary]



def int_to_binary_4bit(intVal):
    int_to_binary_4b = {0:'0000',1:'0001',2:'0010',3:'0011',4:'0100',5:'0101',6:'0110',7:'0111',8:'1000',9:'1001',10:'1010',11:'1011',12:'1100',13:'1101',14:'1110',15:'1111'}
    return int_to_binary_4b[intVal]



def sBox(col,row):
    sBox_array = [[14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7],[0 ,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8],[4,1	,14	,8	,13	,6	,2	,11	,15	,12	,9	,7	,3	,10	,5	,0],[15	,12	,8	,2	,4	,9	,1	,7	,5	,11	,3	,14	,10	,0	,6	,13]]
    return int_to_binary_4bit(sBox_array[row][col])



def compress(value_to_compress):
    col = binary_to_int_4bit(value_to_compress[1:5])
    row = binary_to_int_2bit(value_to_compress[0]+value_to_compress[-1])
    #print("Col : ",col," Row : ",row)
    compressed_value = sBox(col, row)
    #print(len(compressed_value))
    return compressed_value



def func(R, K):
    primary_XOR = ''
    #print("R : ",len(R))
    for i in range(len(R)):
        primary_XOR += str(int(R[i])^int(K[i]))
    XOR_to_send =''
    for i in range(0,48,6):
        XOR_to_send += compress(primary_XOR[i:i+6])
    return XOR_to_send



def fiestal_round_right_processing(right_half, key):
    expanded_right = expansion(right_half)
    value_to_be_XORed = func(expanded_right, key[:48])
    return value_to_be_XORed



def XOR_left_fiestal(l_half, f_value):
    XOR_value = ''
    for i in range(len(l_half)):
        XOR_value += str(int(l_half[i])^int(f_value[i]))
    return XOR_value


message = '1111110010001001110110111000111001111000011010101010101010101010'
keys = ['11100000010111010100001100110101000100110111111100110101', '10001110111111110111101110010100010111010010010011110111' , '10001001101111101110110110101100110011100111100100101101', '11101000110110011001100011000001001001000001010111101001' ,'10011000000001011011100111000001000111100100011000111000','00011111011010000110001101111100011001011100111110011101','01100001101000100100110101001111010100000001110110111011','00001100001101011000011100100010101011000000001100111101','11011010100110100011001011010001110111111111010101111010','01111001111101010011001101010011001100110100010001100110','01101101110001111000101000000000010011101100101100110000','10111101101110001000011011001010100110000011000000110111','01010100101111101001001101000101001001011010100101011000','01010100111111010101001010111101111011001010001110110010','11010101101010000011011100010010110100010100110101011101','00011100110101000001001000001010110011011001110101100101']


new_message = message
print(message)


for i in range(16):
    left_half = new_message[:32]
    right_half = new_message[32:]
    fiestaled_value = fiestal_round_right_processing(right_half, keys[i])
    new_right = XOR_left_fiestal(left_half, fiestaled_value)
    new_message = right_half+new_right


left_half = new_message[:32]
right_half = new_message[32:]
new_message = right_half+left_half


message = new_message


print(new_message)
# Decryption

new_message = message

for i in range(16):
    left_half = new_message[:32]
    right_half = new_message[32:]
    fiestaled_value = fiestal_round_right_processing(right_half, keys[15-i])
    new_right = XOR_left_fiestal(left_half, fiestaled_value)
    new_message = right_half + new_right

left_half = new_message[:32]
right_half = new_message[32:]
new_message = right_half+left_half
#new_message = final_permu(new_message)

print(new_message)