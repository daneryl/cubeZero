#
#   Hello World client in Python
#   Connects REQ socket to tcp://localhost:5555
#   Sends "Hello" to server, expects "World" back
#

import zmq
# import random
import time
import json

moves = ["l", "l'", "r", "r'", "b", "b'", "t", "t'", "f", "f'", "d", "d'"]

context = zmq.Context()

#  Socket to talk to server
print("Connecting to hello world server…")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

ePerm = ["r'", "d'", "r", "u'", "r'", "d", "r", "u", "r'", "d'",
         "r", "u", "u", "r'", "d", "r", "u'", "r'", "d'", "r",
         "u", "r'", "d", "r", "u", "u"]

for member in ePerm:
    socket.send_string(member)
    message = socket.recv_json()
    # print(message.decode("utf-8"))
    print(json.dumps(message, indent=4, sort_keys=True))
    time.sleep(0.1)
