# %%
import os
# Run if you are on Google Colab to install the Python bindings
os.system('bash compile.sh')
import numpy as np
import matplotlib.pyplot as plt
from example import HelperClass, function1

n = 2

helper = HelperClass(n)

print(helper.show())

A = np.zeros((n,n))

function1(A)

print(A)