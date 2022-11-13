"""
Roei Barak
318419611
"""

def is_valid(num):
    # first check - if the num is number
    if isinstance(num, int):
        if num > 99999 or num < 10000:
            return False
        else:
            return True
    if not num.isnumeric():
        return False
    if int(num) > 99999 or int(num) < 10000:
        return False
    return True


def separet(num):
    # separate all digit
    list_of_digit = []
    for i in range(len(num)):
        list_of_digit.append(num[i])
    return list_of_digit


def my_assert():
    try:
        assert separet("12345") == ['1','2','3','4','5']
        assert separet("") == []
        assert separet("abc") == ['a','b','c']
        assert separet(['a',1,3]) == ['a', 1, 3]

        assert is_valid(99999) is True
        assert is_valid('10000') is True
        assert is_valid(9999) is False
        assert is_valid('100000') is False
        assert is_valid('hi') is False
        assert is_valid('1234a') is False
        assert is_valid('1+234') is False
        assert is_valid(1234) is False
        assert is_valid(1234+2) is False
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
    for i in range(len(user_number) - 1):
        # separate all except from the last one with ','
        print(separet(user_number)[i], end=',')
    print(separet(user_number)[-1])


# Standard boilerplate to call the main() function.
if __name__ == '__main__':
    main()


"""
Please insert a 5 digit number: opasd
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