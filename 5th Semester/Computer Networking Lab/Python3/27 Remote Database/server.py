# to run, enter the following in terminal
#python server.py & python client.py

import socket
import threading
import pymysql


connection = pymysql.connect(host='localhost',
                             user='shivanshu',
                             password='12345',
                             db='pythontest',
                             charset='utf8mb4',
                             cursorclass=pymysql.cursors.DictCursor,
                             port=8889)





s = socket.socket()
host = socket.gethostname()
port = 8080
s.bind((host, port))
s.listen(5)

query_list = []
client_list = []

class Receive(threading.Thread):
    def run(self):
        global query_list
        sock = client_list[-1]
        while True:
            data = sock.recv(1024)
            message = (data).decode('utf-8')
            message = message.split("$")
            query = message[0]
            flag_out = message[1]
            if query == "EXIT":
                print(sock," Logged Out")
                sock.close()
                break
            print("Sock Query : ",query)
            print("Sock Flag  : ",flag_out)
            flag_out = int(flag_out)
            if flag_out == 1:
                try:
                    with connection.cursor() as cursor:
                        sql = query
                        cursor.execute(sql)
                    connection.commit()
                    sock.send(str.encode("Operation Successful"))
                except:
                    sock.send(str.encode("OOPS Some Error Occured"))
            elif flag_out == 2:
                try:
                    with connection.cursor() as cursor:
                        sql = query
                        cursor.execute(sql)
                        result = cursor.fetchall()
                        data = ""
                        for r in result:
                            for x in r.keys():
                                data += x+" : "+str(r[x])+"\n"
                            data+="$"
                        sock.send(str.encode(data))
                except:
                    sock.send(str.encode("OOPS Some Error Occured"))



class Client_manager(threading.Thread):
    def run(self):
        while True:
            c, addr = s.accept()
            client_list.append(c)
            rcv_thread = Receive()
            rcv_thread.start()
            print(c," Joined ")

port_scanner = Client_manager()


port_scanner.start()
