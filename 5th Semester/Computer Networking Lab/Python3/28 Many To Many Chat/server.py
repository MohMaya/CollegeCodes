import threading
import socket
import time

message_q = []
client_list = []
s = socket.socket()
host = socket.gethostname()
port = 8080
s.bind((host, port))
s.listen(5)


class Receive(threading.Thread):
    def run(self):
        while True:
            time.sleep(0.5)
            global message_q
            sock = client_list[-1]
            data = sock.recv(1024)
            message = (data).decode('utf-8')
            message_q.append(message)
            print(message)



class Client_manager(threading.Thread):
    def run(self):
        while True:
            c, addr = s.accept()
            client_list.append(c)
            rcv_thread = Receive()
            rcv_thread.start()
            #print(c)

class Sender(threading.Thread):
    def run(self):
        global message_q
        while True:
            if(len(message_q)!=0):
                message = ''
                for i in message_q:
                    message += (i + "$")
                for c in client_list:
                    #print(c)
                    c.send(str.encode(message))
                message_q = []




sending_thread = Sender()
port_scanner = Client_manager()


port_scanner.start()
sending_thread.start()