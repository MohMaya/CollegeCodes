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
        parsedString = stringToParse

    return parsedString


testCase = ["Shivanshu", "23", "13.45", "shivanshu@97.22"]
for i in testCase:
    parser(i)