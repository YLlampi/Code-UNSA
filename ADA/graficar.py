import numpy as np
import matplotlib.pyplot as plt

def f(n):
    return n**2

def g(n):
    return n**2 - 3*n +2


values = np.arange(0, 3, 0.1)

plt.plot(f(values))
plt.plot(g(values))

plt.show()