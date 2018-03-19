import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

x,y,temp = np.loadtxt('pyrene_slice.dat').T #Transposed for easier unpacking
nrows, ncols = 113, 133
grid = temp.reshape((nrows, ncols))

plt.imshow(grid, extent=(x.min(), x.max(), y.max(), y.min()),
           interpolation='nearest', vmin=-0.02, vmax=0.01, cmap=cm.gist_rainbow)
plt.show()
