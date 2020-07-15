from cs50 import get_float



n = get_float("Change owned: ")

if n > 0:

    cents = round(n * 100)

    result25 = int(cents / 25)
    reminder25 = cents % 25

    result10 = int(reminder25 / 10)
    reminder10 = reminder25 % 10

    result5 = int(reminder10 / 5)
    reminder5 = reminder10 % 5

    result1 = int(reminder5 / 1)

    s = result25 + result10 + result5 + result1

    print(s)
    


