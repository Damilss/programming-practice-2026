""" 
count_digits used a while loop to count and return the
number of digits in a positive integer.

@param: int n, 
@return: int the number of positive integers

"""
def count_digits(n: int)->int:
    count = 0
    while n >= 10**count:
        count += 1
    return count
 
