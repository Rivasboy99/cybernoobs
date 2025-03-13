#Calcular el promedio

print("El programa calculara el promedio de 1 alumno\n")

Alumno1=input("Escribe tu nomre:\n")
mate=float(input("Escribe tu nota: "))
fisi=float(input("Escribe tu nota: "))
comu=float(input("Escribe tu nota: "))
promedio=(mate+fisi+comu)/3
if promedio<11.5:

    print(F"{Alumno1} tu promedio es: {round(promedio,2)} REPROBASTE") ##Es para imprimir los datos dentro de las palabras de salida 
else:
    print(F"{Alumno1} tu promedio es: {round(promedio,2)} APROBASTE") ##Es para imprimir los datos dentro de las palabras de salida 