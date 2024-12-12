import os

f = open("coordinates.txt", "w+")

for i in range(3,50):
    for j in range(50):
        f.write(str(i) + "," + str(j) + "\n")

f.close()