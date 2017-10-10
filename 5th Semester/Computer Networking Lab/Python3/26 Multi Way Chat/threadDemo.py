import threading
from queue import Queue
import time

#Message Queue Management[To Happen On server side]

q = Queue()
#Inserting a message:
message1 = "Hello"
message2 = "Lajlu"
q.put(message1)
q.put(message2)

#Dequeueing a message
print(q.get(message1))
print(q.get(message2))
print(q.empty())


'''

#Thread Management System

class Sender(threading.Thread):
    def run(self):
        for _ in range(10):
            time.sleep(0.2)
            print("Sending")

class Receive(threading.Thread):
    def run(self):
        for _ in range(10):
            time.sleep(0.3)
            print("Receiving")

sending_thread = Sender()
receiving_thread = Receive()

sending_thread.start()
receiving_thread.start()

'''
