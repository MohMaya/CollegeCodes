import threading
from queue import Queue
import socket
import time

message_q = Queue()
s = socket.socket()
host = socket.gethostname()
port = 8080
s.bind((host, port))
s.listen(5)
c,addr = s.accept()

class Sender(threading.Thread):
    def run(self):
        while True:
            print("Snding")
            message = input(">")
            c.send(str.encode(message))



class Receive(threading.Thread):
    def run(self):
        while True:
            print("Rcving")
            print("Connection Accepted")
            data = c.recv(2048)
            if not data:
                continue
            print("Data Got")
            message = (data).decode('utf-8')
            print("> Message : ", message)





sending_thread = Sender()
receiving_thread = Receive()

sending_thread.start()
receiving_thread.start()
