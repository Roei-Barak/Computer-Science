import sys
import os

PATH = 1
PARM_ONE = 1
PARM_TWO = 2
operator = ["+", "-", "*", "/"]


def exe_check(line):
    """
    :param line: the line in the file which we check the exe
    :return: true if is valid templent x + y
    """
    line_split = line.split()
    if len(line_split) == 3:
        return True
    return False


def valid_operator(line):
    """
    :param line: line from the file of the exe
    :return: true if the operator is valid + , - * , /
    """
    line_split = line.split()
    if line_split[1] in operator:
        return True
    return False


def zero_div(line):
    """

    :param line: the line in the file which we check the zero dividing
    :return: true if it dosen`t contain
    """
    line_split = line.split()
    if line_split[1] == '/':
        if line_split[2] == '0':
            return False
    return True


def number_check(line):
    """

    :param line: the line in the file which we check the zero dividing
    :return: True if the first and last charthers is number
    """
    line_split = line.split()
    if (line_split[0].isdigit()) and (line_split[-1].isdigit()):
        return True
    return False


def total_check(line):
    """
    :param line: Total check for the line
    :return: True if the line is corect exe
    """
    if exe_check(line) is False:
        return False
    if valid_operator(line) is False:
        return False
    if zero_div(line) is False:
        return False
    if number_check(line) is False:
        return False
    if space_check(line) is False:
        return False
    return True


def space_check(line):
    """

    :param line: the line in the file which we check the zero dividing
    :return:true if it wiht the templet of num 'space' operator 'space' number
    """
    count = 0
    for i in line:
        if i == " ":
            count += 1
    if count == 2:
        return True
    return False


def assert_fun():
    try:
        assert exe_check("a v b") is False
        assert exe_check("a") is False
        assert exe_check("") is False
        assert exe_check("1+2") is False
        assert exe_check("1+ 2") is False
        assert exe_check("roei + barak") is True
        assert valid_operator("3 / 2") is True
        assert valid_operator("3 = 2") is False
        assert valid_operator("3 1 2") is False
        assert zero_div("0 / 0") is False
        assert zero_div("0 / 2") is True
        assert number_check("1 3 2") is True
        assert number_check("1 3 v") is False
        assert number_check("1 + v") is False
        assert number_check("z + v") is False
        assert total_check("1 + 2") is True
        assert total_check("1 +2") is False
        assert total_check("a + 2") is False
        assert total_check(" ") is False
        assert total_check(" ") is False
        assert space_check("  ") is True
        assert space_check("2- 1") is False
        assert space_check("2-1") is False
    except AssertionError:
        print("ERROR")


def main():
    if not len(sys.argv) == 3:
        return "Not found competable num of arguments"
    if os.path.isfile(sys.argv[PARM_ONE]) is False:
        return "First arguments not valid"
    if os.path.isfile(sys.argv[PARM_TWO]) is False:
        return "Second arguments not valid"
    homework = open(sys.argv[PARM_ONE], 'r')
    solution = open(sys.argv[PARM_TWO], 'a')
    with homework as input_file, solution as output_file:
        for line in input_file:
            if (total_check(line)) is True:
                solution.write(line[:-1] + " = " + str(eval(line)) + '\n')
            else:
                solution.write("non-valid exercise\n")


if __name__ == "__main__":
    main()

"""
directory = input()
print(os.path.exists(directory))
print(os.path.exists("C:\\use"))
print(os.listdir(directory))
print(dir(os.path))
"""
