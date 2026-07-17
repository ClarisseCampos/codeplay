def gdc(big, small):
    if big < small:
        small, big = big, small
        
    if big % small == 0:
        return small
    else:
        id = small
        while id > 0:
            if (big % id == 0) and (small % id == 0):
                return id
            id -= 1
  
n1 = int(input('Set a number: '))
n2 = int(input('Set another: '))

print(f'GCD between {n1} and {n2}: {gdc(n1,n2)}')
