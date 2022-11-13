"""
Roei Barak
318419611
"""
LEN_OF_STRING = 5


def is_valid(num):
    number = str(num)
    if len(str(number)) != LEN_OF_STRING:
        return False
    for d in number:
        if not d.isdigit():
            return False
    return True


def sep(num):
    # separate all digit
    i = 0
    digit_sep = ""
    for i in range(LEN_OF_STRING - 1):
        digit_sep += str(num[i]) + ","
    return digit_sep + num[i + 1]


def sum_of_digit(num):
    sum_dig = 0
    for i in range(LEN_OF_STRING):
        sum_dig += int(num[i])
    return sum_dig


def my_assert():
    try:
        assert sum_of_digit("12345") == 15
        assert sum_of_digit("54321") == 15
        assert sep("12345") == "1,2,3,4,5"
        assert is_valid(99999) is True
        assert is_valid('10000') is True
        assert is_valid(9999) is False
        assert is_valid('100000') is False
        assert is_valid('hi') is False
        assert is_valid('1234a') is False
        assert is_valid('1+234') is False
        assert is_valid(1234) is False
        assert is_valid(1234 + 2) is False
    except AssertionError:
        print("wrong")


def main():
    my_assert()
    user_number = input("Please insert a 5 digit number: ")
    while not is_valid(user_number):
        user_number = input("Please insert a 5 digit number:")
    # print the number
    print(f"You entered the number: {user_number}")
    # print each digit separate with ,
    print("The digits of the number are: ", end="")
    print(sep(user_number))
    # print sum of digit
    print(f"The sum of digits is: {sum_of_digit(user_number)}")


# Standard boilerplate to call the main() function.
if __name__ == '__main__':
    main()

"""
Please insert a 5 digit number: op
Please insert a 5 digit number:afs	`12
Please insert a 5 digit number:1235o9asf
Please insert a 5 digit number:as
Please insert a 5 digit number:dsf
Please insert a 5 digit number:aa
Please insert a 5 digit number:`
Please insert a 5 digit number:123{!2
Please insert a 5 digit number:P{
Please insert a 5 digit number:12324
You entered the number: 12324
The digits of the number are: 1,2,3,2,4
"""
