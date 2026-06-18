num = int(input("Enter number of numbers to enter: "))

li = []
for i in range(num):
    li.append(int(input(f"Enter element {i}: ")))

print(li)
sum = 0
min = li[0]
max = li[0]
for i in li:
    sum += i
    if i <= min:
        min = i
    if i >= max:
        max = i
print(f"Sum: {sum}")
print(f"Min: {min}")
print(f"Max: {max}")
index = int(input(f"Enter index to update(0 - {num - 1}): "))
val = int(input(f"Enter updated value: "))
li[index] = val
print(li)