#Demo for Substitution Cipher By Shivanshu Chaudhary aka MOHMAYA


def encryptor(originalMessage):        #Function for encrypting the originalMessage
    encryptedMessage = ""
    #logic for encryption
    for character in originalMessage:
        asciiValueOfCharacter = ord(character)
        newAsciiValue = (asciiValueOfCharacter + 13)%256    #Shifting By 13 units to right
        newCharacter = chr(newAsciiValue)
        encryptedMessage += newCharacter
    return encryptedMessage


def decryptor(encryptedMessage):        #Function for decrypting the encryptedMessage
    originalMessage = ""
    #logic for decrypting
    for character in encryptedMessage:
        asciiValueOfCharacter = ord(character)
        newAsciiValue = (asciiValueOfCharacter - 13)%256    #Shifting By 13 units to left
        newCharacter = chr(newAsciiValue)
        originalMessage += newCharacter
    return originalMessage


userInput = input("\nPlease Enter Your Desired Message : ")
encryptedMesasge = encryptor(userInput)

print("\nThe Encypted Message is  : "+encryptedMesasge)

originalMessage = decryptor(encryptedMesasge)
print("\nThe Decrypted Message is : "+originalMessage)