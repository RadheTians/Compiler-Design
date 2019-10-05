

def Right(nt,production):
    pro = []
    for i in production:
        if i.find(nt) != -1:
            if i.split("->")[1].find(nt) == -1:
                pro.append(i.split("->")[1])

    return pro




def First():
    production = []
    NT = set()
    t =int(input("Enter the no of Production :== "))
    print("<<== The productions ==>>")
    for i in range(t) :
        production.append(input())
    for i in production :
        NT.add(i.split("->")[0])
    for i in NT :
        print(i+" :==>>" ,end=" ")
        first = set()

        pro = Right(i,production)
        for i in pro :
            flag = 0
            for j in i :
                if j.isupper() :
                     x = Right(j,production)
                     if any("x" in s for s in x):
                         x.remove("x")
                     else:
                        flag =1
                        for j in x:
                            first.add(j)
                        break
                     for k in x :
                        first.add(k)


            if flag == 0 :
                first.add(i)

        print(first)




if __name__ == "__main__" :
    First()



