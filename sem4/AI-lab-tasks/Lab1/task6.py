text = str(input("Enter a string: "))


substrs = []
for i in range(len(text)):
    substr = ""
    for j in range(i, len(text)):
        if text[j] in substr:
            substrs.append(substr)
            break
        else:
            substr += text[j]

longest = substrs[0]
for subs in substrs:
    if len(subs) > len(longest):
        longest = subs

print(f"Longest substring: {longest}")