#
#   Hello World client in Python
#   Connects REQ socket to tcp://localhost:5555
#   Sends "Hello" to server, expects "World" back
#

import zmq
# import random
import time
import json

moves = ['l', 'r', 'b', 't', 'f', 'd']

context = zmq.Context()

#  Socket to talk to server
print("Connecting to hello world server…")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

# tPerm = ["r'", "u'", "f'", "r", "u", "r'", "u'", "r'", "f", "r",
#          "r", "u'", "u'", "r", "u'", "r'"]

# fPerm = ["r'", "u'", "f'", "r", "u", "r'", "u'", "r'",
#          "f", "r", "r", "u'", "r'", "u'", "r", "u", "r'", "u", "r"]

ePerm = ["r'", "d'", "r", "u'", "r'", "d", "r", "u", "r'", "d'",
         "r", "u", "u", "r'", "d", "r", "u'", "r'", "d'", "r",
         "u", "r'", "d", "r", "u", "u"]

# aPermB = ["r", "b'", "r", "f", "f", "r'", "b", "r", "f", "f", "r", "r"]

for member in ePerm:
    socket.send_string(member)
    message = socket.recv_json()
    # print(message.decode("utf-8"))
    print(json.dumps(message, indent=4, sort_keys=True))
    time.sleep(0.1)

# for member in aPermB:
#     socket.send_string(member)
#     message = socket.recv()
#     time.sleep(0.1)

# for member in aPermB:
#     socket.send_string(member)
#     message = socket.recv()
#     time.sleep(0.1)

# for member in fPerm:
#     socket.send_string(member)
#     message = socket.recv()
#     time.sleep(0.1)

# for member in fPerm:
#     socket.send_string(member)
#     message = socket.recv()
#     time.sleep(0.1)

# for member in aPermB:
#     socket.send_string(member)
#     message = socket.recv()
#     time.sleep(0.1)

# for member in aPermB:
#     socket.send_string(member)
#     message = socket.recv()
#     time.sleep(0.1)

# for member in aPermB:
#     socket.send_string(member)
#     message = socket.recv()
#     time.sleep(0.1)
