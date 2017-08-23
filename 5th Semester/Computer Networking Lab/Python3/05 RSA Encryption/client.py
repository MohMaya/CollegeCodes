import socket

s = socket.socket()
host = socket.gethostname()
port = 8080


from math import sqrt


def encryptor(originalMessage,publicKey):        #Function for encrypting the originalMessage
    encryptedMessage = pow(originalMessage,publicKey[1]) % publicKey[0]
    #logic for encryption
    return encryptedMessage


def decryptor(encryptedMessage,privateKey):        #Function for decrypting the encryptedMessage
    originalMessage = pow(encryptedmessage,privateKey[1]) % privateKey[0]
    #logic for decrypting
    return originalMessage


def isPrime(n):
    for i in range(2,int(sqrt(n))):
        if n%i == 0:
            return False
    return True


def isCoprime(e,fi):
    if e < fi:
        for i in range(2,e+1):
            if(fi%i == 0) and (e%i == 0):
                return False
    elif e>fi:
        for i in range(2,fi+1):
            if(e%i == 0) and (fi%i == 0):
                return False
    else:
        return False
    return True


def dCalculator(e,fi):
    k=0
    d=0
    while True:
        if (1+(k*fi))%e == 0:
            d = (1+(k*fi))//e
            return d
        k+=1
    return 0


while True:
    primeNumber1 = int(input("Enter First Prime Number : "))
    if isPrime(primeNumber1):
        break
    print("Not A Prime Number")


while True:
    primeNumber2 = int(input("Enter The Second Prime Number : "))
    if isPrime(primeNumber2):
        break
    print("Not A Prime Number")


modulus = primeNumber1 * primeNumber2

totient = (primeNumber1 - 1) * (primeNumber2 - 1)

while True:
        publicKeyExponent = int(input("Enter The Public Key Exponent Of Your Message : "))
        if isCoprime(publicKeyExponent,totient):
            break
        print("Invalid Key!!!")


privateKeyExponent = dCalculator(publicKeyExponent,totient)


publicKey = (modulus,publicKeyExponent)
privateKey = (modulus,privateKeyExponent)
print("Public Key : ",publicKey)
print("Private Key : ",privateKey)




userInput = int(input("\nPlease Enter Your Desired Numerical Message : "))

encryptedmessage = encryptor(userInput,publicKey)
print("\nThe Encypted Message is  : "+str(encryptedmessage))

s.connect((host, port))
s.send(str.encode(encryptedmessage))
print("Client Sent Message : ",encryptedmessage)

s.close