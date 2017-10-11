import threading
from queue import Queue
import socket
import time

message_q = Queue()
s = socket.socket()
host = socket.gethostname()
port = 8080
s.connect((host, port))

class Sender(threading.Thread):
    def run(self):
        while True:
            message = input(">")
            if message == "exit":
                s.close()
                return
            #message_q.put(message)
            s.send(str.encode(message))
            print("Message Sent")

class Receive(threading.Thread):
    def run(self):
        while True:
            data = s.recv(2048)
            if not data:
                continue
            print("Got Data")
            message = (data).decode('utf-8')
            print("> Message : ", message)




sending_thread = Sender()
receiving_thread = Receive()

sending_thread.start()
receiving_thread.start()
