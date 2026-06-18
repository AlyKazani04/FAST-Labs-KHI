def give_repeated(li : list):
    num_set = set()
    repeated = []
    for i in li:
        if i in num_set:
            if i not in repeated:
                repeated.append(i)
        num_set.add(i)
    return sorted(repeated)

li = [1,2,4,2,5,6,7,4,4,5,8,9]

print(f"Repeated letters in {li}:\n{give_repeated(li)}")