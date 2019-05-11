import time
import sys 

start = time.time()

for i in range(1,999999999):
	for x in range(2, 21):
		if i % x != 0:
			break
		elif x == 20:
			print (i)
			end = time.time()
			print(str(end - start) + " seconds elapsed")	
			sys.exit()	

