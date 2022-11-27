# """
# Roei Barak
# 318419611
# """
# LEN_OF_STRING = 5
#
#
# def main():
#     num = input("Please enter 5 digit number\n")
#     print(f"You entered the number:{num}")
#     print(f"The digit of this number are:{num[0]},{num[1]},{num[2]},{num[3]},{num[4]}")
#     sum_dig = 0
#     for i in range(LEN_OF_STRING):
#         sum_dig += int(num[i])
#     print(f"The sum of digits is:{sum_dig}")
#
#
# # Standard boilerplate to call the main() function.
# if __name__ == '__main__':
#     main()
cmd = "MSGat est"
DIC = {'a' : 1,'b': 2 }
print(' '.join(DIC.keys()))
cmd_parsed = cmd.split(' ')
cmd_name = cmd_parsed[0]
recipient_name = cmd_parsed[1]
msg = ' '.join(cmd_parsed[2:])

print(cmd_name)
print(recipient_name)

print(msg)
