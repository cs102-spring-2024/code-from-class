
## Goal: Write a Python program that prints the integers from 0 to 1000,
## all on one line separated by spaces (it's fine if they're on multiple lines).

### First working program:
# count = 0
# string = ""

# while count < 1001:
#     string += str(count) + " "
#     count += 1

# print(string)

### Second attempt

def main():
    for i in range(1001):
        print(i, end = " ")

    print()

if __name__ == "__main__":
    main()
