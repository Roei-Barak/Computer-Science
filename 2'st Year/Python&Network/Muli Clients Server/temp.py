DIC = {'a':1, 'b':2}
name = list(DIC.keys())[list(DIC.values()).index(1)]
print(name)
DIC.pop(name)
print(DIC)
