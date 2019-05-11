import time
start = time.time()	

print (sum(map(int, str(2 ** 1000))))

end = time.time()
print(str(end - start) + " seconds elapsed")	