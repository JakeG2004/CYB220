myFile = open("file.txt", "r")

for line in myFile:
    if "the" in line:
        print("Yes")