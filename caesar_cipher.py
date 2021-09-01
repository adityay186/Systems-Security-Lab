#program demonstrating caesar cypher encryption
#Author : Aditya Kamlesh Yadav
#PRN : 20190802060
#Subject : Systems Security Lab 01

def encrypt(txt, sft):
    res = "" #creating initial empty string

    for i in txt:
        if (i.isupper()): #converter for upper case
            res += chr((ord(i) + sft-65) % 26 + 65) #we need to subtract 65 because in ASCII Upper Case Letters start from 65
        elif(i == " "): #for space ( " ")
            res += " "
        else: #for lower case
            res += chr((ord(i) + sft-97) % 26 + 97) #we need to subtract 97 because in ASCII Lower Case Letters start from 97

    return res


txt = input("Enter text to encrypt : ") #taking input text
sft = int(input("Enter shift : ")) #taking shift as input
res = encrypt(txt, sft) #storing result in the res variable
print() #omitting a line for better view
print(res) #printing the result
