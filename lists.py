import msvcrt



num = 0
while num < 10:
        user_input = msvcrt.getch()
        num += 1
        print(user_input.decode())
print(num)
