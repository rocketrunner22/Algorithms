import time
start = time.time()	

print (max(i * j for i in range(100, 1000) for j in range(100, 1000) if str(i * j) == str(i * j)[ : : -1]))
end = time.time()
print(str(end - start) + " seconds elapsed")	