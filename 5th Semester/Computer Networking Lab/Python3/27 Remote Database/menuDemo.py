#ISSUE: Reading multiple records

import pymysql
connection = pymysql.connect(host='localhost',
                             user='shivanshu',
                             password='12345',
                             db='pythontest',
                             charset='utf8mb4',
                             cursorclass=pymysql.cursors.DictCursor,
                             port=8889)


def parser(stringToParse):
    flag = 0
    flago = 0
    if stringToParse.isnumeric():
        parsedString = int(stringToParse)
        flag =1
    else:#parsing Decimal nos.
        if stringToParse.count('.')==1:
            numList = stringToParse.split('.')
            for j in numList:
                if not j.isnumeric():
                    flago = 1
            if flago == 0:
                parsedString = float(stringToParse)
                flag = 1

    if flag == 0:
        parsedString = "\'"+stringToParse+"\'"

    return parsedString




def createTable():
    tableName = input("Enter The Tablename : ").upper()
    command = "CREATE TABLE "+tableName + "( "
    noOfCols = int(input("Enter The Number of Columns in the Table : "))
    for i in range(noOfCols):
        colName = input("Enter The Name of Column     : ").upper()
        colType = input("Enter The DataType Of Column[INT DOUBLE STRING] : ").upper()
        colSize = int(input("Enter The Size Of The Column : "))
        command += colName+" "+colType+"("+str(colSize)+") ,"
    command = command[:-2]
    command += ")"
    return command

def insertData():
    tableName = input("Enter The Tablename : ").upper()
    dataValues = input("Enter The Data Values (Split by Space) :").split()
    command = "INSERT INTO `"+tableName+"` VALUES("
    for d in dataValues:
        prsedValue = parser(d)
        command += str(prsedValue)+", "
    command = command[:-2]
    command += ")"
    print(command)
    return command

def readData():
    tableName = input("Enter The Tablename : ").upper()
    command = "SELECT * FROM "+tableName
    return command

def readDataConditional():
    tableName = input("Enter The Tablename : ").upper()
    conditionOn = input("Enter The Column On which Condition is to be Put : ").upper()
    print("Choose Condition : \n1. =\n2. >\n3. >=\n4. <=\n5. <\n6. LIKE [for string like data]")
    condition = int(input("What Condition to apply? : "))
    if condition == 1:
        condition = "="
    elif condition == 2:
        condition = ">"
    elif condition == 3:
        condition = ">="
    elif condition == 4:
        condition = "<="
    elif condition == 5:
        condition = "<"
    elif condition == 6:
        condition = "LIKE"
    conditionValue = input("Enter The Conditional Value : ").upper()
    command = "SELECT * FROM "+tableName+" WHERE "+conditionOn+" "+condition+" \'"+conditionValue+"\'"
    return command

def deleteTable():
    tableName = input("Enter The Tablename to Delete : ").upper()
    confirmTableName = input("Re-Enter the Tablename to confirm deletion : ").upper()
    if tableName == confirmTableName:
        command = "DROP TABLE "+tableName
    else:
        print("Deletion Can' be confirmed.")
        return
    return command

def deleteRowConditional():
    tableName = input("Enter The Tablename : ").upper()
    conditionOn = input("Enter The Column On which Condition is to be Put : ").upper()
    print("Choose Condition : \n1. =\n2. >\n3. >=\n4. <=\n5. <\n6. LIKE [for string like data]")
    condition = int(input("What Condition to apply? : "))
    if condition == 1:
        condition = "="
    elif condition == 2:
        condition = ">"
    elif condition == 3:
        condition = ">="
    elif condition == 4:
        condition = "<="
    elif condition == 5:
        condition = "<"
    elif condition == 6:
        condition = "LIKE"
    conditionValue = input("Enter The Conditional Value : ").upper()
    command = "DELETE FROM " + tableName + " WHERE " + conditionOn + " " + condition + " \'" + conditionValue + "\'"
    return command

def arithmeticOperation():
    tableName = input("Enter The Tablename : ").upper()
    conditionOn = input("Enter The Column On which Operation is to be performed[* for all] : ").upper()
    print("Choose Operation : \n1. AVERAGE\n2. MIN\n3. MAX\n4. SUM")
    condition = int(input("What Operation to apply? : "))
    command = "SELECT "
    if condition == 1:
        command += "AVG("+conditionOn+")"
    elif condition == 2:
        command += "MIN(" + conditionOn + ")"
    elif condition == 3:
        command += "MAX(" + conditionOn + ")"
    elif condition == 4:
        command += "SUM(" + conditionOn + ")"
    command += " FROM " + tableName
    print(command)
    return command

def arithmeticOperationConditional():
    tableName = input("Enter The Tablename : ").upper()
    conditionOn = input("Enter The Column On which Operation is to be performed[* for all] : ").upper()
    print("Choose Operation : \n1. AVERAGE\n2. MIN\n3. MAX\n4. SUM")
    condition = int(input("What Operation to apply? : "))
    command = "SELECT "
    if condition == 1:
        command += "AVG(" + conditionOn + ")"
    elif condition == 2:
        command += "MIN(" + conditionOn + ")"
    elif condition == 3:
        command += "MAX(" + conditionOn + ")"
    elif condition == 4:
        command += "SUM(" + conditionOn + ")"
    command += " FROM " + tableName
    conditionOn = input("Enter The Column On which Condition is to be Put : ").upper()
    print("Choose Condition : \n1. =\n2. >\n3. >=\n4. <=\n5. <\n6. LIKE [for string like data]")
    condition = int(input("What Condition to apply? : "))
    if condition == 1:
        condition = "="
    elif condition == 2:
        condition = ">"
    elif condition == 3:
        condition = ">="
    elif condition == 4:
        condition = "<="
    elif condition == 5:
        condition = "<"
    elif condition == 6:
        condition = "LIKE"
    conditionValue = input("Enter The Conditional Value : ").upper()
    command += " WHERE " + conditionOn + " " + condition + " \'" + conditionValue + "\'"
    return command

def update():
    tablename = input("Enter The Tablename : ").upper()
    command = "UPDATE "+tablename+" SET "
    columnName = input("Enter The Column Name To Update : ")
    command += columnName + " = "
    updatedValue = input("Enter The New Value : ")
    columnName = input("Enter The Column On Which Condition Is To Be Applied : ")
    oldValue = input("Enter The Conditional Value : ")
    oldValue = parser(oldValue)
    updatedValue = parser(updatedValue)
    command += updatedValue + " WHERE " + columnName + " = " + oldValue
    print(command)
    return command

def advancedUser():
    advancedCommand = input("Enter The Exact SQL query : ").upper()
    return advancedCommand

while(True):
    print("**********************MENU**********************")
    print("01. Create Table[Experimental]\n02. Insert\n03. Read Data\n04. Read Data [Conditional]\n05. Delete Table\n06. Delete a Row [Conditional]",
          "\n07. Arithmetic Operation\n08. Arithmetic Operation[Conditional]\n09. Update\n10. ADVANCED USER[Custom Command]\n11. EXIT")
    choice = int(input("Enter Your Choice : "))
    flag_out = 0


    if choice==1:
        comm = createTable()
        flag_out = 1
    elif choice==2:
        comm = insertData()
        flag_out = 1
    elif choice==3:
        comm = readData()
        flag_out = 2
    elif choice==4:
        comm = readDataConditional()
        flag_out = 2
    elif choice==5:
        comm = deleteTable()
        flag_out = 1
    elif choice==6:
        comm = deleteRowConditional()
        flag_out = 1
    elif choice==7:
        comm = arithmeticOperation()
        flag_out = 2
    elif choice==8:
        comm = arithmeticOperationConditional()
        flag_out = 2
    elif choice==9:
        comm = update()
        flag_out = 1
    elif choice==10:
        comm = advancedUser()
        flag_out = 1
    elif choice == 11:
        connection.close()
        exit()
    else:
        print("!! ERROR  :  Invalid Command Code")

    if flag_out == 1:
        try:
            with connection.cursor() as cursor:
                # Create a new record
                sql = comm
                cursor.execute(sql)

            # connection is not autocommit by default. So you must commit to save
            # your changes.
            connection.commit()
        except:
            print("OOPS Some Error")

    elif flag_out == 2:
        try:
            with connection.cursor() as cursor:
                # Read a single record
                sql = comm
                cursor.execute(sql)
                result = cursor.fetchall()
                for r in result:
                    print(r)
        except:
            print("OOPS Some Error")

