import socket

s = socket.socket()
host = socket.gethostname()
port = 8080


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


numberOfRails = 3

userInput = input("\nPlease Enter Your Desired Message : ")
encryptedMessage = encryptor(userInput,numberOfRails)


s.connect((host, port))
s.send(str.encode(encryptedMessage))
print("Client Sent Message : ")
for char in encryptedMessage:
    if char == "$":
        continue
    print(char,end='')
print('')
s.close