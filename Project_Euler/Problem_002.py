import time
start = time.time()	

import numpy as np

answer = 0
data = [1,2]
sum = 0
i = 2
while data[i-1] + data[i-2] < 4000000 :
	data.append(data[i-1] + data[i-2])
	sum = data[i]
	i += 1

np_data = np.array(data)
temp = np_data % 2 == 0
np_even = np_data[temp]
print(np.sum(np_even))

end = time.time()
print(str(end - start) + " seconds elapsed")	