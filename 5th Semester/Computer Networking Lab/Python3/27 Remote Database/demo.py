#  MYSQL Demo code

import pymysql

connection = pymysql.connect(host='localhost',
                             user='shivanshu',
                             password='12345',
                             db='pythontest',
                             charset='utf8mb4',
                             cursorclass=pymysql.cursors.DictCursor,
                             port=8889)

try:
    with connection.cursor() as cursor:
        # Create a new record
        sql = "INSERT INTO `USERS` (`EMAIL`, `PASSWORD`, `AGE`, `SEX`, `NAME`) VALUES ('webmaster@python.org', 'very-secret', 23, 'M', 'Testcase1')"
        cursor.execute(sql)

    # connection is not autocommit by default. So you must commit to save
    # your changes.
    connection.commit()

    with connection.cursor() as cursor:
        # Read a single record
        sql = "SELECT `email`, `password` FROM `users` WHERE `NAME`='Testcase1'"
        cursor.execute(sql)
        result = cursor.fetchone()
        print(result)
finally:
    connection.close()
