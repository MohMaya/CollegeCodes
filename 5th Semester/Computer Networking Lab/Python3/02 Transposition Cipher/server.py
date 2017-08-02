# to run, enter the following in terminal
#python server.py & python client.py

import socket

s = socket.socket()
host = socket.gethostname()
port = 8080

s.bind((host,port))

s.listen(5)

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


while True:
    c,addr = s.accept()
    print("Got Connection From : ",addr)
    encryptedMessage = (c.recv(2048)).decode('utf-8')
    print("Server Received Message : ")
    for char in encryptedMessage:
        if char == "$":
            continue
        print(char, end='')
    print('')
    numberOfRails = 3
    originalMessage = decryptor(encryptedMessage, numberOfRails)
    print("\nThe Decrypted Message is : " + originalMessage)
    c.close()

s.close