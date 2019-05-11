import time
start = time.time()

import math

n = 600851475143
ans = 0

for i in range(3,int(math.sqrt(n))+1,2):
	while n % i== 0:
		ans = i
		n = n / i
print (ans)

end = time.time()
print(str(end - start) + " seconds elapsed")	