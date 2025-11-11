def factorial(number):
    if number == 0 or number == 1:
        return 1
    else:
        return number * factorial(number - 1)

n = int(input("Enter the number: "))
print("The factorial of the entered number is:", factorial(n))
