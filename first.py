print("Hello World")

# I installed two modules- 1.flask and 2.Pyjokes but i dont know how to use flask
# I am using pyjokes to get a random joke

#another module PYTTSX3 - which is used to convert text to speech, i installed it 

"""

import pyjokes
joke = pyjokes.get_joke()
print(joke)

"""

"""
#i can write multiple line in a single print stateent using single quotes typing 3 times , also remember typing 3 double quotes represents comments.

print('''Twinkle, twinkle, little star,
How I wonder what you are!
Up above the world so high,
Like a diamond in the sky.

When the blazing sun is gone,
When he nothing shines upon,
Then you show your little light,
Twinkle, twinkle, all the night.

Then the traveler in the dark
Thanks you for your tiny spark;
He could not see which way to go,
If you did not twinkle so.

In the dark blue sky you keep,
And often through my curtains peep,
For you never shut your eye
Till the sun is in the sky.

As your bright and tiny spark
Lights the traveler in the dark,
Though I know not what you are,
Twinkle, twinkle, little star.
''')
"""

"""
# using PYTTSX3 - text to speech

import pyttsx3
engine = pyttsx3.init()
engine.say("Hi Himangshu! ki khobor tumar?")
engine.runAndWait()
"""



# #Handbook
# #Problem 5: Write a python program to print the contents of a directory using the os module. Search online for the function which does that. 

# import os

# # Specify the directory path; using '.' denotes the current directory
# path = r'C:\Users\pc\OneDrive\Desktop\vs Code\Programs\c++'

# try:
#     # Retrieve the list of entries in the directory
#     entries = os.listdir(path)

#     print(f"\nContents of directory '{path}':")
#     for entry in entries:
#         print(entry)
# except FileNotFoundError:
#     print(f"The directory '{path}' does not exist.")
# except PermissionError:
#     print(f"Permission denied to access '{path}'.")


"""   
# variables and data types:

a=1     #it is an integer
b=2    

c="Himangshu"      # double quotes " " defines a STRING

d=3.14          # float

e= True         # boolean variables 
f= False

g= None        # None is a special type in python, it is used to define a null value

_sameer= 12    #we can write variable names starting with UNDERSCORE or ALPHABETS, but not with numbers and other special characters

#  @sameer= 12    not valid due to @
# 1. 1sameer= 12   not valid due to 1 


 #Arithmatic operators
 
a=10
b=20
c= a+b
print(c)  # addition
"""

"""
#assignment operators   

a=4-2  #assign 4-2 to a
print(a)  # a=2

b=6
b +=3   #increment the value of b by 3 and then assign it to b
print(b)  # b=9
b-=2    #decrement the value of b by 2 and then assign it to b
print(b)  # b=7 
# this is same for / ,* ,% , //, **, & , | , ^ , << , >>
"""

"""
#comparison operators
#comparison operator always returns a boolean value - eithr True or False
d=10<20
print(d)  # True

e=10>20
print(e)  # False   

f=5>=5
print(f)  # True    

g=5!=7
print(g)  # True

h= 5==5
print(h)  # True
i= 5==6
print(i)  # False
"""

"""
#logical operators
e= True or False 
print(e)  # True

f= True and False
print(f)  # False

#Truth 
print("\nTruth Table for OR operator:")
print("True or False =  ", True or False)
print("True or True = ", True or True)
print("False or True = ", False or True)
print("False or False = ", False or False)

print("\nTruth Table for AND operator:")
print("True and False =  ", True and False)
print("True and True = ", True and True)
print("False and True = ", False and True)
print("False and False = ", False and False)

print("\nTruth Table for NOT operator: ")
print("not True = ", not True)
print("not False = ", not False)
print(not(True)) 
print(not(False))    
"""

"""
#Type Function and Type Casting
a = 31  
t=type(a)
print(t)  # <class 'int'>
 
b = 31.5 
s=type (b) 
print(s)  # <class 'float'>

c="31,Himangshu"
u=type(c)
print(u)  # <class 'str'>

#converting a data type to another datatype
a= 31
d= float(a)  # converting int to float
v=type(d)
print(v)  # <class 'float'>
print(d)  # 31.0
"""

"""
#input function

#string input
a= input("Enter number 1: ")
b= input("Enter number 2: ")
print("Number a is: ",a)
print("Number b is: ",b)
print("Sum of a and b is: ",a+b)  # it will concatenate the two strings
print("\n")

c= input("Enter your name: ")
d= input("Enter your title: ")
print("your name is : ",c)
print("your title is : ",d)
print("Your name and title merged together: ",c+d)   #it will merge the two stings and display together.
print("\n")

#int input
e= int(input("Enter the first number: "))
f= int(input("Enter the second number: "))
print("Number first is: ",e)
print("Number second is: ",f) 
print("Sum of first and second is: ",e+f)  # it will add the two numbers , same for multiplication, division, subtraction etc for all type of inputs 

"""