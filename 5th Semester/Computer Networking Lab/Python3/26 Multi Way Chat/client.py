# DUMMY CODE FOR CLIENT
import socket

s = socket.socket()
host = socket.gethostname()
port = 8080

userInput = input("\nPlease Enter Your Desired Message [All Caps Only]: ")
s.connect((host, port))
s.send(str.encode(userInput))
print("Client Sent Message : ",userInput)

s.close