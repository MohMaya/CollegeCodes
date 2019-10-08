# to run, enter the following in terminal
#python server.py & python client.py

import socket

s = socket.socket()
host = socket.gethostname()
port = 8080

s.bind((host,port))

s.listen(5)


def valueOfAlphabet(alphabet):
    return ord(alphabet)


def alphabetOfValue(value):
    return chr(value)

def decryptor(encodedMessage, key):        #Function for decrypting the encryptedMessage
    #logic for decrypting
    encodedMessageList = [character for character in encodedMessage]
    keyList = [character for character in key]

    decodedMessageValueList = []

    decodedMessage = ""

    for c in range(len(encodedMessageList)):
        decodedMessageValueList.append((valueOfAlphabet(encodedMessageList[c]) - valueOfAlphabet(keyList[c])) % 128)
        decodedMessage += alphabetOfValue(decodedMessageValueList[c])



    return decodedMessage



while True:
    c,addr = s.accept()
    print("Got Connection From : ",addr)
    encryptedMessage = (c.recv(2048)).decode('utf-8')
    print("Server Received Message : ",encryptedMessage)

    key = ""
    while (len(key) != len(encryptedMessage)):
        key = input("\nPlease Enter A Valid Key : ")

    originalMessage = decryptor(encryptedMessage, key)
    print("\nThe Decrypted Message is : " + originalMessage)

    c.close()

s.close