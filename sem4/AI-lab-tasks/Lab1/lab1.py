import math
print("Hello World!")

name = str(input("Enter name: "))

fruits = ["Apple", 1245, False, "Bruh"]
fruits.append(name)
fruits.append("banana")
print(fruits)

my_dic = { "long": 8 }
print(my_dic)

my_set = {1,2,3,4}
other_set = {1,2,5,6,7}

print(my_set | other_set)

addtodic = { "rest" : "small" }
my_dic.update(addtodic)
print(my_dic)

def print_dic(any_dic):
    for i,v in any_dic.items():
        print(i,v)

if my_dic["long"] > 6:
    print(my_dic["long"])
else:
    print(my_dic["rest"])

print_dic(my_dic)


def floordivide(a,b):
    count = 0
    while(a >= b):
        a -= b
        count += 1
    print(count)
print(math.floor(9/2))
floordivide(4, 4)