import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
x=[ i for i in range(0,100)]
x=[ i for i in range(0,100)]
y=[ 3*i for i in range(0,100)]
fig=plt.figure()
ax=fig.add_subplot(1,1,1)
ax.plot(x,y, color="blue", linewidth=3)
plt.savefig("hello.png")
