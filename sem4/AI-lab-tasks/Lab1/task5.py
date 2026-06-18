def create_dict(text : str):
    temp = {
        "characters" : len(text),
    }
    
    vowels, consonants = 0
    
    for c in text:
        if c in ('a', 'e', 'i', 'o', 'u'):
            vowels += 1
        else:
            consonants += 1
    temp.update({ 
        "vowels" : vowels,
        "consonants" : consonants
    })
    return temp

val = str(input("Enter a string: "))
new_dict = create_dict(val)
print(new_dict)