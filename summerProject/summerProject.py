import numpy as np
import matplotlib.pylab as plt
import matplotlib.ticker as ticker

#Подынтегральное выражение
def f(X, t):
    return t**2 * (np.sin(X*t))**2

def simpsonIntegral(a, b, N):
    h = (b-a)/N
    k1 = 0
    k2 = 0
    for i in range (1, N, 2):
        k1 += f(X, a + i*h)
        k2 += f(X, a + (i+1)*h)
    return h/3*(f(X, a) + 4*k1 + 2*k2)

a = float (eval(input("Введите a (нижний предел интегрирования): "), {'pi': np.pi}))
b = float (eval(input("Введите b (верхний предел интегрирования): "), {'pi': np.pi}))
c = float (eval(input("Введите c: "), {'pi': np.pi})) # x∈[c,d]
d = float (eval(input("Введите d: "), {'pi': np.pi})) # x∈[c,d]
N = int (eval(input("Введите N (значение разбиения интервала интегрирования): "), {'pi': np.pi}))
p = 21                                                # Колличество значений на промежутке
h = (b-a)/N                                           # Шаг разбиения
max_discr = 0.0                                       # Максимальное невязка
X = []
Y = []

#Генерируем список значений x
for i in range (p):
    X.append(c + i*(d-c)/20)
    if X[i] == 0:
        X[i] = 0.0000001
#Если X[i] == 0, то график строиться некорректно (деление на 0), соотвественно используем значение, приближеннное к нулю

X = np.array(X)

#Генерируем список значений Y аналитическим путем
for i in range (p):
    Y.append(-((6 * X[i]**2 - 3) * np.sin(2*X[i]) + 6 * X[i] * np.cos(2*X[i]) - 4 * X[i]**3)/(24 * X[i]**3))

#Генерируем список значений Y методом Симпсона
aY = simpsonIntegral(a, b, N)

#находим максимальную невязку (расхождение)
for i in range(p):
    if abs(Y[i] - aY[i]) > max_discr:
        max_discr = abs(Y[i] - aY[i])

print("Максимальная невязка = ", max_discr)

#Графическое оформление
plt.plot(X, aY, color = "red", label="Приближенное")
plt.plot(X, Y, color = "blue", label="Точное")
plt.title("Графики определенного интеграла\n Значение разбиения интервала интегрирования = {}".format(N))
plt.ylabel("Значение определенного интеграла")
plt.xlabel("Значение t")
plt.grid(which='major', color='k')
plt.minorticks_on()
plt.grid(which='minor', color='gray', linestyle=':')
plt.legend()
plt.show()
