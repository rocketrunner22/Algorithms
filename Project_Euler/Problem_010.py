import time
start = time.time()	

sieve = [True] * 2000000

def mark(sieve, x):
	for i in range(x + x, len(sieve), x):
		sieve[i] = False

for i in range(2, int(len(sieve) ** 0.5)):
	if sieve[i]: mark(sieve, i)
	
print (sum(i for i in range(2, len(sieve)) if sieve[i]))

end = time.time()
print(str(end - start) + " seconds elapsed")	

