LEN_OF_STRING = 5


def print_digits(s):
    """
    :param s: string
    prints digits of a string number
    """
    print("The digits of this number are: ", end="")
    for index, c in enumerate(s):
        my_end = ","
        if index == len(s) - 1:
            my_end = "\n"
        print(c, end=my_end)


def str_to_sum(s):
    """
    :param s: string
    :return: sum of digits in s
    """
    my_sum = 0
    for index, c in enumerate(s):
        my_sum += int(c)
    return my_sum


def input_5d_number():
    """
    :return: an input string composed of 5 digits
    """
    my_string = ''
    while not check_5d_in_string(my_string):
        my_string = input("Please enter a 5 digits number: \n")
    return my_string


def check_5d_in_string(s):
    """
    :param s: string
    :return: is s composed of 5 digits
    """
    if len(s) != LEN_OF_STRING:
        return False
    for c in s:
        if not c.isdigit():
            return False
    return True


def main():
    # tests:
    tests()

    my_string = input_5d_number()
    print("You entered the number: " + my_string)
    print_digits(my_string)
    my_sum = str_to_sum(my_string)
    print("The sum of the digits is: " + str(my_sum))


def tests():
    assert (check_5d_in_string('tghgbj6677')) == False
    assert (check_5d_in_string('222')) == False
    assert (check_5d_in_string('hh2662')) == False
    assert (check_5d_in_string('hhy')) == False
    assert (check_5d_in_string('12345')) == True


if __name__ == '__main__':
    main()
