list = []
for i in range(101):
    list.append(True)
list[0] = list[1] = False


for i in range(2,len(list)):
    if list[i]==True:
        for j in range(2*i, len(list),i):
            list[j]=False

for idx, e in  enumerate(list):
    if e:
        print(idx, " is a prime number.")