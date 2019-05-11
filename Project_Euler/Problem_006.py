import time
start = time.time()	

print ((sum(i for i in range(1, 100 + 1)) ** 2) - sum(i**2 for i in range(1, 100 + 1)))


end = time.time()
print(str(end - start) + " seconds elapsed")	