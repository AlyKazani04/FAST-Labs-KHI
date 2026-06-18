
temp = {}
temp["name"] = str(input("Enter your name: "))
temp["age"] = int(input("Enter your age: "))
temp["city"] = str(input("Enter your city: "))

print(temp)

if temp["age"] >= 18:
    print("Eligible")
else:
    print("ineligible")
