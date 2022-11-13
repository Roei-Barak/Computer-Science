"""
Roei Barak
318419611
"""
def main():
    num = input("Please enter 5 digit number\n")
    print(f"You entered the number:{num}")
    print(f"The digit of this number are:{num[0]},{num[1]},{num[2]},{num[3]},{num[4]}")
    sum_dig = 0
    for i in range(5):
        sum_dig += int(num[i])
    print(f"The sum of digits is:{sum_dig}")




# Standard boilerplate to call the main() function.
if __name__ == '__main__':
    main()