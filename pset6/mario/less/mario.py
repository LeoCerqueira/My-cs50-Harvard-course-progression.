from cs50 import get_int



n = get_int("Positive Number (btween 1 and 8):")



while(n < 1 or n > 8):
    print("That is an invalid input")
    n = get_int("Positive Number (btween 1 and 8):")
    
    
k = 1
j = n

if 0 < n < 9:
    for i in range(n):
            print(" " * (j - 1), end="")
            j = j - 1 
            print("#" * k)
            k = k + 1



