"""
Author`s name : Roei Barak
Id:318419611
"""

STRING_LEN = 5
sum_digit = 0
number = input("Please enter a 5 digit number :\n")
while not len(number) == 5 or not number.isdigit():
    number = input('Invalid input.\nPlease enter a 5-digit number: ')

my_number = int(number)
print("You entered the number: {}".format(number))
print("The digits of this number are: ", end="")
sum_digit = 0
for digit in number[:-1]:
    z = int(digit)
    sum_digit = sum_digit + z
    print(digit, end=",")
print(number[-1])

print("The sum of the digits is: {}".format(sum_digit + int(number[-1])))
"""
Please enter a 5 digit number :
20461
You entered the number: 20461
The digits of this number are: 2,0,4,6,1
The sum of the digits is: 13
"""