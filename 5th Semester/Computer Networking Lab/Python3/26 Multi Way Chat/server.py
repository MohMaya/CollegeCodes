import socket

s = socket.socket()
host = socket.gethostname()
port = 8080

s.bind((host,port))

s.listen(5)

while True:
    c,addr = s.accept()
    print("Got Connection From : ",addr)
    encryptedMessage = (c.recv(2048)).decode('utf-8')
    print("Server Received Message : ",encryptedMessage)

    key = "PLAYFAIR EXAMPLE"
    keyMatrix = prepareKeyMatrix(key)

    encryptedDigramList = breakIntoDigram(encryptedMessage)

    decryptedList = decryptor(encryptedDigramList, keyMatrix)
    originalMessage = joinDigrams(decryptedList)

    print("\nThe Decrypted Message is : " + originalMessage)
    c.close()

s.close