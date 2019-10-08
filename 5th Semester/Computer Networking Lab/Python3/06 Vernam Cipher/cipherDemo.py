#Demo for Vernam Cipher By Shivanshu Chaudhary aka MOHMAYA


def valueOfAlphabet(alphabet):
    return ord(alphabet)


def alphabetOfValue(value):
    return chr(value)



def encryptor(originalMessage,key):        #Function for encrypting the originalMessage
    #logic for encryption
    originalMessageList = [character for character in originalMessage]
    keyList = [character for character in key]

    encodedMessageValueList = []

    encodedMessage = ""

    for c in range(len(originalMessageList)):
        encodedMessageValueList.append((valueOfAlphabet(originalMessageList[c])+valueOfAlphabet(keyList[c]))% 128)
        encodedMessage += alphabetOfValue(encodedMessageValueList[c])

    return encodedMessage


def decryptor(encodedMessage, key):        #Function for decrypting the encryptedMessage
    originalMessage = ""
    #logic for decrypting
    encodedMessageList = [character for character in encodedMessage]
    keyList = [character for character in key]

    decodedMessageValueList = []

    decodedMessage = ""

    for c in range(len(encodedMessageList)):
        decodedMessageValueList.append((valueOfAlphabet(encodedMessageList[c]) - valueOfAlphabet(keyList[c])) % 128)
        decodedMessage += alphabetOfValue(decodedMessageValueList[c])



    return decodedMessage





userInput = input("\nPlease Enter Your Desired Message : ")

key = ""
while(len(key)!=len(userInput)):
    key = input("\nPlease Enter A Valid Key : ")

encryptedMessage = encryptor(userInput,key)

print("\nThe Encypted Message is  : "+encryptedMessage)

originalMessage = decryptor(encryptedMessage, key)
print("\nThe Decrypted Message is : "+originalMessage)