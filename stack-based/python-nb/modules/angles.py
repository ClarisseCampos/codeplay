import math

alpha = math.radians(int(input('Set an angle: ')))

alpha_sin = math.sin(alpha)
alpha_cos = math.cos(alpha)
alpha_tan = math.tan(alpha)

print('Main')

print(f'Sin = {alpha_sin:.2f}\nCos = {alpha_cos:.2f}\nTan = {alpha_tan:.2f}\n')

print('Inverse')
print(f'Csc = {1/alpha_sin:.2f}\nSec = {1/alpha_cos:.2f}\nCtg = {1/alpha_tan:.2f}\n')