try:
    a = int(input('Numerador: '))
    b = int(input('Denominador: '))
    r = a/b

except ZeroDivisionError: 
    print('Nao eh possivel dividir um numero por zero')
except Exception as erro:
    print(f'ERRO! Problema foi {erro.__class__}')
    print(f'Causado por {erro.__cause__}')

else:
    print(f'Resultado: {r}')

finally:
    print('Volte sempre')