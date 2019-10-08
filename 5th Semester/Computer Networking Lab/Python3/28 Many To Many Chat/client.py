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
        name = input("Client name Please : ")
        while True:
            message = input("> ")
            if message == "exit":
                s.close()
                return
            message = name + " Says :" + message
            s.send(str.encode(message))
            print("Message Sent")

class Receive(threading.Thread):
    def run(self):
        while True:
            data = s.recv(1024)
            if not data:
                continue
            message = (data).decode('utf-8')
            message = message.split('$')
            for i in message:
                print("> ", i)






sending_thread = Sender()
receiving_thread = Receive()

sending_thread.start()
receiving_thread.start()