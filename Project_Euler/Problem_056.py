import time
start = time.time()	

answer = 0
for a in range (1,100):
	for b in range (1,100):
		len = sum(map(int, str(a ** b)))
		if len > answer:
			answer = len
print (answer)
end = time.time()
print(str(end - start) + " seconds elapsed")	
