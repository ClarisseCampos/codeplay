def atm(pascal):
    return pascal*9.86923e-6
def bar(pascal):
    return pascal*1e-5
def psi(pascal):
    return pascal*1.45038e-4

pascal = float(input("Set a value: "))
print(f'{pascal} pascal is equal to {atm(pascal):.4e} atm')
print(f'{pascal} pascal is equal to {bar(pascal):.4e} bar')
print(f'{pascal} pascal is equal to {psi(pascal):.4e} psi')