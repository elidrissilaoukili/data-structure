  number = int(input("number = "))
    for number in range(1, number + 1):
        for num in range(1, number + 1):
            result = number * num
            print(result, end=' ')
        print('\t\t')