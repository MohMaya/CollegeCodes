# to run, enter the following in terminal
#python server.py & python client.py

import socket

s = socket.socket()
host = socket.gethostname()
port = 8080

s.bind((host,port))

s.listen(5)

def decryptor(encryptedMessage,privateKey):        #Function for decrypting the encryptedMessage
    originalMessage = pow(encryptedMessage,privateKey[1]) % privateKey[0]
    #logic for decrypting
    return originalMessage

while True:
    c,addr = s.accept()
    print("Got Connection From : ",addr)
    encryptedMessage = (c.recv(2048)).decode('utf-8')
    print("Server Received Message : ",encryptedMessage)

    mod = input("Enter Modulus")
    exp = input("Enter Private Exponent")
    originalMessage = decryptor(encryptedMessage, (mod, exp))
    print("\nThe Decrypted Message is : " + originalMessage)

    c.close()

s.close