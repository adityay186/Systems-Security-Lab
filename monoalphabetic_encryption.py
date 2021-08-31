# program demonstrating monoalphabetic encrytion
# Author : Aditya Kamlesh Yadav
# PRN : 20190802060
# Subject : Systems Security Lab 01

def getChar(c):
    dictionary = { #initialise a dictionary in python for storing key and value pairs of characters to be encrypted
    'a': 'D',
    'b': 'K',
    'c': 'V',
    'd': 'Q',
    'e': 'F',
    'f': 'I',
    'g': 'B',
    'h': 'J',
    'i': 'W',
    'j': 'P',
    'k': 'E',
    'l': 'S',
    'm': 'C',
    'n': 'X',
    'o': 'H',
    'p': 'T',
    'q': 'M',
    'r': 'Y',
    's': 'A',
    't': 'U',
    'u': 'O',
    'v': 'L',
    'w': 'R',
    'x': 'G',
    'y': 'Z',
    'z': 'N',
    ' ': ' '
    }

    return dictionary[c] #returning associated encrypted character

def encrypt(s): #function to encrypt
    res = "" #empty string
    for i in s: #running loop through the whole text
        res += getChar(i.lower())

    return res

inp = input("Enter text to encrypt : ") #taking text as input
ans = encrypt(inp) #storing result in the variable
print() #ommiting a line for better viewing
print("Encrypted Text is : ", ans) #printing the result
