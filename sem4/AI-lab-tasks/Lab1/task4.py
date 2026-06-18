def waive_discount(amount):
    if amount < 1000:
        discount = .05
    elif amount < 5000:
        discount = .1
    else:
        discount = 0.15
    return amount * discount

amount = float(input("Enter purchase amount: "))
print(f"Payable Amount: {waive_discount(amount)}")