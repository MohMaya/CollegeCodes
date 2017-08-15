#Demo for Hill Cipher By Shivanshu Chaudhary aka MOHMAYA


def valueOfAlphabet(alphabet):
    value = ord(alphabet.upper())-ord('A')
    return value




def alphabetOfValue(valueList):
    text = ""

    for i in valueList:
        text += chr(ord('A') + i)

    return text




def determinant(matrix,order):
    determinantValue = 20
    if(order == 2):
        pass
    elif(order == 3):
                        # detA = a11a22a33  + a21a32a13 + a31a12a23 - a11a32a23 - a31a22a13 - a21a12a33
        determinantValue = (matrix[0][0]*matrix[1][1]*matrix[2][2]) + (matrix[1][0]*matrix[2][1]*matrix[0][2]) + (matrix[2][0]*matrix[0][1]*matrix[1][2]) - (matrix[0][0]*matrix[2][1]*matrix[1][2]) - (matrix[2][0]*matrix[1][1]*matrix[0][2]) - (matrix[1][0]*matrix[0][1]*matrix[2][2])
    else:
        #for order 4
        pass
    return determinantValue




def prepareAdjoint(matrix,order,modDeterminant):
    if order == 3:
        adjointMatrix = [[0 for i in range(3)] for j in range(3)]

        adjointMatrix[0][0] = (((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]))*modDeterminant)%26
        adjointMatrix[0][1] = (((matrix[0][2] * matrix[2][1]) - (matrix[0][1] * matrix[2][2]))*modDeterminant)%26
        adjointMatrix[0][2] = (((matrix[0][1] * matrix[1][2]) - (matrix[0][2] * matrix[1][1]))*modDeterminant)%26

        adjointMatrix[1][0] = (((matrix[1][2] * matrix[2][0]) - (matrix[1][0] * matrix[2][2]))*modDeterminant)%26
        adjointMatrix[1][1] = (((matrix[0][0] * matrix[2][2]) - (matrix[0][2] * matrix[2][0]))*modDeterminant)%26
        adjointMatrix[1][2] = (((matrix[0][2] * matrix[1][0]) - (matrix[0][0] * matrix[1][2]))*modDeterminant)%26

        adjointMatrix[2][0] = (((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]))*modDeterminant)%26
        adjointMatrix[2][1] = (((matrix[0][1] * matrix[2][0]) - (matrix[0][0] * matrix[2][1]))*modDeterminant)%26
        adjointMatrix[2][2] = (((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]))*modDeterminant)%26

        return adjointMatrix
    return [0,0]




def invertMatrix(matrixToBeInverted, n):

    normalDeterminant = determinant(matrixToBeInverted, n)

    modDeterminant = 0

    while True:
        if((modDeterminant*normalDeterminant)%26 == 1):
            break
        modDeterminant += 1

    invertedMatrix = prepareAdjoint(matrixToBeInverted, n, modDeterminant)

    return invertedMatrix




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





def encryptor(originalMessage, key, n):        #Function for encrypting the originalMessage

    keyValueList = prepareTextValueList(key)

    invertibleMatrix = prepareInvertibleMatrix(keyValueList, n)

    messageVectorList = prepareMessageVectorList(originalMessage, n)

    encodedVector = prepareCodedVectorList(invertibleMatrix, messageVectorList, n)

    encryptedMessage = vectorToMessage(encodedVector)

    return encryptedMessage




def decryptor(encryptedMessage, key, n):        #Function for decrypting the encryptedMessage
    #logic for decrypting

    encryptedKeyValueList = prepareTextValueList(key)

    invertibleMatrix = prepareInvertibleMatrix(encryptedKeyValueList, n)

    invertedMatrix = invertMatrix(invertibleMatrix,n)

    messageVectorList = prepareMessageVectorList(encryptedMessage, n)

    decodedVector = prepareCodedVectorList(invertedMatrix, messageVectorList, n)

    decryptedMessage = vectorToMessage(decodedVector)

    return decryptedMessage




n = 3

while True:
    key = input("Please Enter The Key \t\t: ")
    key = key.upper()
    if(len(key)!=9):
        print("Invlaid Choice Of Key. Re-Enter..")
        continue

    if(determinant(prepareInvertibleMatrix(prepareTextValueList(key),3),3) != 0):
        break
    else:
        print("Invlaid Choice Of Key. Re-Enter..")


message = input("Kindly Enter The Message \t: ")
message = message.upper()
if(len(message)%3 == 1):
    message = message+"XX"
elif(len(message)%3 == 2):
    message = message + "X"
else:
    pass




encryptedMessage = encryptor(message, key, n)
print("Encrypted Message : ",encryptedMessage)



decryptedMessage = decryptor(encryptedMessage, key, n)
print("Decrypted Message : ",decryptedMessage)