#Demo for Hill Cipher By Shivanshu Chaudhary aka MOHMAYA

from sympy import *


def valueOfAlphabet(alphabet):
    value = ord(alphabet.upper())-ord('A')
    return value


def alphabetOfValue(valueList):
    text = ""

    for i in valueList:
        text += chr(ord('A') + i)

    return text



def encryptor(originalMessage, key, n):        #Function for encrypting the originalMessage

    keyValueList = prepareTextValueList(key)

    invertibleMatrix = prepareInvertibleMatrix(keyValueList, n)

    messageVectorList = prepareMessageVectorList(originalMessage, n)

    encodedVector = prepareCodedVectorList(invertibleMatrix, messageVectorList, n)

    encryptedMessage = vectorToMessage(encodedVector)

    return encryptedMessage



def invertMatrix(matrixToBeInverted, n):
    print(matrixToBeInverted)
    matrixToBeInverted = Matrix(matrixToBeInverted)
    print(matrixToBeInverted)
    invertedMatrix = matrixToBeInverted ** -1   # inverting the matrix using sympy library
    print(invertedMatrix)
    invertedMatrix = invertedMatrix.nullspace()


    for i in range(len(invertedMatrix)):
        invertedMatrix[i]%=26
    print(invertedMatrix)
    return invertedMatrix




def decryptor(encryptedMessage, key, n):        #Function for decrypting the encryptedMessage
    #logic for decrypting

    keyValueList = prepareTextValueList(key)

    invertibleMatrix = prepareInvertibleMatrix(keyValueList, n)

    invertedMatrix = invertMatrix(invertibleMatrix, n)

    encryptedMessageVectorList = prepareMessageVectorList(encryptedMessage, n)

    decodedVector = prepareCodedVectorList(invertedMatrix, encryptedMessageVectorList, n)

    decryptedMessage = vectorToMessage(decodedVector)

    return decryptedMessage


def prepareTextValueList(text):
    textValueList = []
    for character in text:
        textValueList.append(valueOfAlphabet(character))

    return textValueList



def prepareInvertibleMatrix(keyValueList,n):
    if len(keyValueList) != pow(n,2):
        print("Invalid Key Length for given N")
        return False

    invertibleMatrix = [[0 for x in range(n)] for y in range(n)]

    for i in range(n):
        for j in range(n):
            invertibleMatrix[i][j] = keyValueList[(n*i)+j]

    return invertibleMatrix



def prepareMessageVectorList(message,n):

    if len(message)%n != 0:
        #add Padding
        paddingLength = n - (len(message) %n)
        for i in range(paddingLength):
            message+="X"

    vectorList =[]

    for i in range(0,len(message),n):
        tempString = message[i:i+n]
        tempVector = []
        for character in tempString:
            tempVector.append(valueOfAlphabet(character))
        vectorList.append(tempVector)

    return vectorList




def matrixMultiply(matA, matB, order):
    productMatrix = [0 for i in range(order)]

    for i in range(order):
        product = 0
        for j in range(order):
            product += (matB[j] * matA[i][j])
        productMatrix[i] = product%26


    return productMatrix



def prepareCodedVectorList(invertibleMatrix, keyValueList, n):
    encodedVectorList = []

    for eachKeyValueList in keyValueList:
        encodedValueList = matrixMultiply(invertibleMatrix, eachKeyValueList, n)
        encodedVectorList.append(encodedValueList)

    return encodedVectorList



def vectorToMessage(vector):
    newMessage = ""
    for eachVector in vector:
        newMessage += alphabetOfValue(eachVector)
    return newMessage




key = "GYBNQKURP"

message = "ACTIFY"

n = 3

encryptedMessage = encryptor(message, key, n)

print("Encrypted Message : ",encryptedMessage)



decryptedMessage = decryptor(encryptedMessage, key, n)

print("Decrypted Message : ",decryptedMessage)

#userInput = input("\nPlease Enter Your Desired Message : ")
#encryptedMesasge = encryptor(userInput)

#print("\nThe Encypted Message is  : "+encryptedMesasge)

#originalMessage = decryptor(encryptedMesasge)
#print("\nThe Decrypted Message is : "+originalMessage)