""" This program has been adapted for use by GVAHIM
       - the main revisions regard pep8 compliance and use of variable names
Copyright 2010 Google Inc.
Licensed under the Apache License, Version 2.0
http://www.apache.org/licenses/LICENSE-2.0
Google's Python Class
http://code.google.com/edu/languages/google-python-class/
Basic list exercises
Fill in the code for the functions below. main() is already set up
to call the functions with a few different inputs,
printing 'OK' when each function is correct.
The starter code for each function includes a 'return'
which is just a placeholder for your code.
It's ok if you do not complete all the functions, and there
are some additional functions to try in list2.py. """


# A. match_ends
# Given a list of strings, return the count of the number of
# strings where the string length is 2 or more and the first
# and last chars of the string are the same.
# Note: python does not have a ++ operator, but += works.
def match_ends(words):
    counter = 0
    for word in words:
        if (len(word) >= 2) and (word[0] == word[-1]):
            counter += 1
    return counter


# B. front_x
# Given a list of strings, return a list with the strings
# in sorted order, except group all the strings that begin with 'x' first.
# e.g. ['mix', 'xyz', 'apple', 'xanadu', 'aardvark'] yields
# ['xanadu', 'xyz', 'aardvark', 'apple', 'mix']
# Hint: this can be done by making 2 lists and sorting each of them
# before combining them.
def front_x(words):
    list_start_with_x = []
    list_alph_bet = []
    for word in words:
        if word[0] == 'x':
            list_start_with_x.append(word)
        else:
            list_alph_bet.append(word)
    list_alph_bet.sort()
    list_start_with_x.sort()
    sorted_list = list_start_with_x + list_alph_bet

    return sorted_list


# C. sort_last
# Given a list of non-empty tuples, return a list sorted in increasing
# order by the last element in each tuple.
# e.g. [(1, 7), (1, 3), (3, 4, 5), (2, 2)] yields
# [(2, 2), (1, 3), (3, 4, 5), (1, 7)]
# Hint: use a custom key= function to extract the last element form each tuple.
def sort_last(tuples):
    sorted_list = []
    for t in tuples:
        sorted_list.append(t)
    return sorted(sorted_list, key=lambda tu: tu[1])


# D. Given a list of numbers, return a list where
# all adjacent == elements have been reduced to a single element,
# so [1, 2, 2, 3] returns [1, 2, 3]. You may create a new list or
# modify the passed in list.
def remove_adjacent(nums):
    list_sorted = []
    for num in nums:
        if len(list_sorted) == 0:
            list_sorted.append(num)
        if num is not list_sorted[-1]:
            list_sorted.append(num)

    """  +++your code here+++ """
    return list_sorted


# E. Given two lists sorted in increasing order, create and return a merged
# list of all the elements in sorted order. You may modify the passed in lists.
# Ideally, the solution should work in "linear" time, making a single
# pass of both lists.
#
# NOTE - DO NOT use return sorted(sorted1 + sorted2) - that's too easy :-)
#
def linear_merge(sorted1, sorted2):
    merge_sorted = []
    k = j = 0
    for i in range(len(sorted1) + len(sorted2)):
        if j == len(sorted1):
            return merge_sorted + sorted2[k:]
        if k == len(sorted2):
            return merge_sorted + sorted1[j:]
        if sorted1[j] <= sorted2[k]:
            merge_sorted.append(sorted1[j])
            j = j + 1
        elif sorted1[j] > sorted2[k]:
            merge_sorted.append(sorted2[k])
            k = k + 1

    """  +++your code here+++ """
    return merge_sorted


def test(got, expected):
    """ simple test() function used in main() to print
        what each function returns vs. what it's supposed to return. """

    if got == expected:
        prefix = ' OK '
    else:
        prefix = '  X '
    print('%s got: %s expected: %s' % (prefix, repr(got), repr(expected)))


def main():
    """ main() calls the above functions with interesting inputs,
        using test() to check if each result is correct or not. """

    print('\nmatch_ends')
    test(match_ends(['aba', 'xyz', 'aa', 'x', 'bbb']), 3)
    test(match_ends(['', 'x', 'xy', 'xyx', 'xx']), 2)
    test(match_ends(['aaa', 'be', 'abc', 'hello']), 1)

    print('\nfront_x')
    test(front_x(['bbb', 'ccc', 'axx', 'xzz', 'xaa']),
         ['xaa', 'xzz', 'axx', 'bbb', 'ccc'])
    test(front_x(['ccc', 'bbb', 'aaa', 'xcc', 'xaa']),
         ['xaa', 'xcc', 'aaa', 'bbb', 'ccc'])
    test(front_x(['mix', 'xyz', 'apple', 'xanadu', 'aardvark']),
         ['xanadu', 'xyz', 'aardvark', 'apple', 'mix'])

    print('\nsort_last')
    test(sort_last([(1, 3), (3, 2), (2, 1)]),
         [(2, 1), (3, 2), (1, 3)])
    test(sort_last([(2, 3), (1, 2), (3, 1)]),
         [(3, 1), (1, 2), (2, 3)])
    test(sort_last([(1, 7), (1, 3), (3, 4, 5), (2, 2)]),
         [(2, 2), (1, 3), (3, 4, 5), (1, 7)])

    print('\nremove_adjacent')
    test(remove_adjacent([1, 2, 2, 3]), [1, 2, 3])
    test(remove_adjacent([1, 3, 3, 2, 2, 3]), [1, 3, 2, 3])
    test(remove_adjacent([2, 2, 3, 3, 3]), [2, 3])
    test(remove_adjacent([]), [])

    print('\nlinear_merge')
    test(linear_merge(['aa', 'xx', 'zz'], ['bb', 'cc']),
         ['aa', 'bb', 'cc', 'xx', 'zz'])
    test(linear_merge(['aa', 'xx'], ['bb', 'cc', 'zz']),
         ['aa', 'bb', 'cc', 'xx', 'zz'])
    test(linear_merge(['aa', 'aa'], ['aa', 'bb', 'bb']),
         ['aa', 'aa', 'aa', 'bb', 'bb'])


if __name__ == '__main__':
    main()
