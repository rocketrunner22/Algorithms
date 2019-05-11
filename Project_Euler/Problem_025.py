import time
start = time.time()

import numpy as np
import sys

data = [1,2]
i = 2
while data[i-1] + data[i-2]:
	data.append(data[i-1] + data[i-2])
	if len(str(abs(data[i]))) == 2000:
		print(i+2)
		sys.exit()
	i += 1
	
end = time.time()
print(str(end - start) + " seconds elapsed")	