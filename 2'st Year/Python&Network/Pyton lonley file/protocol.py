"""EX 2.6 protocol implementation
   Author:
   Date:
   Possible client commands:
   NUMBER - server should reply with a random number, 0-99
   HELLO - server should reply with the server's name, anything you want
   TIME - server should reply with time and date
   EXIT - server should send acknowledge and quit
"""

COMMANDS = ["TIME", "WHORU", "RAND", "EXIT", "NUMBER", "HELLO"]

LENGTH_FIELD_SIZE = 2
PORT = 8820
   

def create_msg(data):

   length = (len(data))
   if length > 99:
      message = "The message is to long"
      return f"{str(len(message))}{message}"
   if length < 11:
      zfill_length = str(length).zfill(2)
      message = zfill_length + data
   
   """Create a valid protocol message, with length field"""
   return f"{message}"


def get_msg(my_socket):

   length = my_socket.recv(2)
   message = my_socket.recv(int(length)).decode()
   """Extract message from protocol, without the length field
    If length field does not include a number, returns False, "Error" """
   return True, message
