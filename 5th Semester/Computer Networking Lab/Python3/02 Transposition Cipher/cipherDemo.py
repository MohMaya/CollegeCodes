#Demo for Transposition Cipher By Shivanshu Chaudhary aka MOHMAYA



##RAIL FENCE CIPHER
##Taking three rails for our demo can be changed as per your disposition

def encryptor(originalMessage,numberOfRails):        #Function for encrypting the originalMessage
    encryptedMessage = ""

    #Preparing Rail Strings
    railStrings = []
    for i in range(numberOfRails):
        railStrings.append("")
    # logic for encryption
    counter = 0
    for character in originalMessage:
        #if character == ' ' or character == '.':
        #    continue
        railStrings[counter]+=character
        counter = (counter+1)%numberOfRails
    for row in railStrings:
        encryptedMessage+=(row+"$")     #Using $ as A Separator for ease in decryption


    return encryptedMessage


def decryptor(encryptedMessage,numberOfRails):        #Function for decrypting the encryptedMessage
    originalMessage = ""

    #preparing Rail Strings
    railStrings = []
    tempString = ""
    for character in encryptedMessage:
        if character == "$":
            #create a new RailString
            railStrings.append(tempString)
            tempString = ""
        else:
            tempString += character
    #logic for decrypting

    counter = 0
    while True:
        flag = 0
        for row in railStrings:
            if(counter+1 <= len(row)):
                originalMessage += row[counter]
            else:
                flag+=1
        counter += 1
        if flag == numberOfRails:
            break

    return originalMessage



numberOfRails = 3

userInput = input("\nPlease Enter Your Desired Message : ")
encryptedMesasge = encryptor(userInput,numberOfRails)

print("\nThe Encypted Message is  : "+encryptedMesasge)

originalMessage = decryptor(encryptedMesasge,numberOfRails)
print("\nThe Decrypted Message is : "+originalMessage)