import bisect

v = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

target = int(input('Set a target: '))
print(bisect.bisect_left(v, target))