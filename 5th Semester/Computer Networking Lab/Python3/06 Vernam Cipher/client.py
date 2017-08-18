import socket

s = socket.socket()
host = socket.gethostname()
port = 8080

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
        encodedMessageValueList.append((valueOfAlphabet(originalMessageList[c])+valueOfAlphabet(keyList[c]))%128)
        encodedMessage += alphabetOfValue(encodedMessageValueList[c])

    return encodedMessage

userInput = input("\nPlease Enter Your Desired Message : ")



key = ""
while(len(key)!=len(userInput)):
    key = input("\nPlease Enter A Valid Key : ")

encryptedMessage = encryptor(userInput,key)

print("\nThe Encypted Message is  : "+encryptedMessage)



s.connect((host, port))
s.send(str.encode(encryptedMessage))
print("Client Sent Message : ",encryptedMessage)

s.close