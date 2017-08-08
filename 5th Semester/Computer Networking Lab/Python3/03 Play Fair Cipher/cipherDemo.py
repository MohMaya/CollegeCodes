#Demo for Play Fair Cipher By Shivanshu Chaudhary aka MOHMAYA


def encryptor(originalDigramSet,keyMatrix):        #Function for encrypting each digram
    encryptedDigramList = []
    #logic for encryption

    for digram in originalDigramSet:
        originalFirstCharacter = digram[0]
        originalSecondCharacter = digram[1]
        encodedFirstCharacter = ''
        encodedSecondCharacter = ''

        rowNumberForOriginalFirstCharacter = 0
        columnNumberForOriginalFirstCharacter = 0

        rowNumberForOriginalSecondCharacter = 0
        columnNumberForOriginalSecondCharacter = 0

        rowNumberForEncodedFirstCharacter = 0
        columnNumberForEncodedFirstCharacter = 0

        rowNumberForEncodedSecondCharacter = 0
        columnNumberForEncodedSecondCharacter = 0


        for i in range(5):
            for j in range(5):
                if keyMatrix[i][j] == originalFirstCharacter:
                    rowNumberForOriginalFirstCharacter = i
                    columnNumberForOriginalFirstCharacter = j
                elif keyMatrix[i][j] == originalSecondCharacter:
                    rowNumberForOriginalSecondCharacter = i
                    columnNumberForOriginalSecondCharacter = j


        if rowNumberForOriginalFirstCharacter == rowNumberForOriginalSecondCharacter:
            # In Same Rows - Move to the Right, Wrapping Around the edge
            rowNumberForEncodedFirstCharacter = rowNumberForOriginalFirstCharacter
            rowNumberForEncodedSecondCharacter = rowNumberForOriginalSecondCharacter
            columnNumberForEncodedFirstCharacter = (columnNumberForOriginalFirstCharacter+1)%5
            columnNumberForEncodedSecondCharacter = (columnNumberForOriginalSecondCharacter+1)%5
        elif columnNumberForOriginalFirstCharacter == columnNumberForOriginalSecondCharacter:
            # In Same Columns - Move Downwards, Wrapping Around the edge
            rowNumberForEncodedFirstCharacter = (rowNumberForOriginalFirstCharacter+1)%5
            rowNumberForEncodedSecondCharacter = (rowNumberForOriginalSecondCharacter+1)%5
            columnNumberForEncodedFirstCharacter = columnNumberForOriginalFirstCharacter
            columnNumberForEncodedSecondCharacter = columnNumberForOriginalSecondCharacter
        else:
            #Different Rows And Columns
            rowNumberForEncodedFirstCharacter = rowNumberForOriginalFirstCharacter
            rowNumberForEncodedSecondCharacter = rowNumberForOriginalSecondCharacter
            columnNumberForEncodedFirstCharacter = columnNumberForOriginalSecondCharacter
            columnNumberForEncodedSecondCharacter = columnNumberForOriginalFirstCharacter

        #Create A new digram
        encodedFirstCharacter = keyMatrix[rowNumberForEncodedFirstCharacter][columnNumberForEncodedFirstCharacter]
        encodedSecondCharacter = keyMatrix[rowNumberForEncodedSecondCharacter][columnNumberForEncodedSecondCharacter]
        encodedDigram = encodedFirstCharacter + encodedSecondCharacter

        #Add The New Digram to encryptedDigramList
        encryptedDigramList.append(encodedDigram)



    return encryptedDigramList


def decryptor(encryptedDigramList,keyMatrix):        #Function for decrypting the encryptedMessage
    decryptedDigramList = []
    #logic for decrypting
    for digram in encryptedDigramList:
        encodedFirstCharacter = digram[0]
        encodedSecondCharacter = digram[1]
        decodedFirstCharacter = ""
        decodedSecondCharacter = ""


        rowNumberForOriginalFirstCharacter = 0
        columnNumberForOriginalFirstCharacter = 0

        rowNumberForOriginalSecondCharacter = 0
        columnNumberForOriginalSecondCharacter = 0

        rowNumberForEncodedFirstCharacter = 0
        columnNumberForEncodedFirstCharacter = 0

        rowNumberForEncodedSecondCharacter = 0
        columnNumberForEncodedSecondCharacter = 0


        for i in range(5):
            for j in range(5):
                if keyMatrix[i][j] == encodedFirstCharacter:
                    rowNumberForEncodedFirstCharacter = i
                    columnNumberForEncodedFirstCharacter = j
                elif keyMatrix[i][j] == encodedSecondCharacter:
                    rowNumberForEncodedSecondCharacter = i
                    columnNumberForEncodedSecondCharacter = j

        if rowNumberForEncodedFirstCharacter == rowNumberForEncodedSecondCharacter:
            columnNumberForOriginalFirstCharacter = (columnNumberForEncodedFirstCharacter - 1)%5
            columnNumberForOriginalSecondCharacter = (columnNumberForEncodedSecondCharacter - 1)%5
            rowNumberForOriginalFirstCharacter = rowNumberForEncodedFirstCharacter
            rowNumberForOriginalSecondCharacter = rowNumberForEncodedSecondCharacter
        elif columnNumberForEncodedFirstCharacter == columnNumberForEncodedSecondCharacter:
            columnNumberForOriginalFirstCharacter = columnNumberForEncodedFirstCharacter
            columnNumberForOriginalSecondCharacter = columnNumberForEncodedSecondCharacter
            rowNumberForOriginalFirstCharacter = (rowNumberForEncodedFirstCharacter - 1)%5
            rowNumberForOriginalSecondCharacter = (rowNumberForEncodedSecondCharacter - 1)%5
        else:
            columnNumberForOriginalFirstCharacter = columnNumberForEncodedSecondCharacter
            columnNumberForOriginalSecondCharacter = columnNumberForEncodedFirstCharacter
            rowNumberForOriginalFirstCharacter = rowNumberForEncodedFirstCharacter
            rowNumberForOriginalSecondCharacter = rowNumberForEncodedSecondCharacter

        decodedFirstCharacter = keyMatrix[rowNumberForOriginalFirstCharacter][columnNumberForOriginalFirstCharacter]
        decodedSecondCharacter = keyMatrix[rowNumberForOriginalSecondCharacter][columnNumberForOriginalSecondCharacter]

        decodedDigram = decodedFirstCharacter + decodedSecondCharacter

        decryptedDigramList.append(decodedDigram)

    return decryptedDigramList


def prepareKeyMatrix(keyString):
    keyMatrix = [[0 for x in range(5)] for y in range(5)]
    tempKeyMatrix = []

    #logic to create the 2D key Matrix
    for i in range(len(keyString)):
        character = keyString[i]
        if character == " ":
            continue
        if character in tempKeyMatrix:
            continue
        tempKeyMatrix.append(character)

    if len(tempKeyMatrix) < 25: #we would not be able to make a  5 x 5 table
        alphabets = "ABCDEFGHIKLMNOPQRSTUVWXYZ" # J and Q are omitted. I and J are Equivalent. Q is less Frequent
        for alphabet in alphabets:
            if alphabet not in tempKeyMatrix:
                tempKeyMatrix.append(alphabet)
            if len(tempKeyMatrix) == 25:
                break

    for i in range(5):
        for j in range(5):
            keyMatrix[i][j] = tempKeyMatrix[(5*i)+j]

    return keyMatrix


def breakIntoDigram(originalMessage):
    digramList = []
    #logic to create Digrams
    i = 0
    while i < len(originalMessage)-1:
        if originalMessage[i] == " ":
            i+=1
            continue
        if originalMessage[i] == originalMessage[i+1]:
            tempString = originalMessage[i] + "X"
            i+=1
        elif originalMessage[i+1] == " ":
            tempString = originalMessage[i]+originalMessage[i+2]
            i+=3
        else:
            tempString = originalMessage[i] + originalMessage[i+1]
            i+=2
        digramList.append(tempString)

    if digramList[-1][-1] != originalMessage[-1]:
        tempString = originalMessage[-1] + "X"
        digramList.append(tempString)
    return  digramList


def joinDigrams(decryptedDigramList):
    originalMessage = ""
    #logic to change Digrams into message
    for digram in decryptedDigramList:
        if digram[1] == "X":
            originalMessage += digram[0]
        else:
            originalMessage += digram
    return originalMessage


##Encryption
key = "PLAYFAIR EXAMPLE"
keyMatrix = prepareKeyMatrix(key)
print(keyMatrix)

userInput = input("\nPlease Enter Your Desired Message : ")
digramList = breakIntoDigram(userInput)
print(digramList)


encryptedDigramList = encryptor(digramList,keyMatrix)
print(encryptedDigramList)

#print("\nThe Encypted Message is  : "+encryptedList)


##Decryption
decryptedList = decryptor(encryptedDigramList,keyMatrix)
print(decryptedList)

originalMessage = joinDigrams(decryptedList)
print("\nThe Decrypted Message is : "+originalMessage)
