

def Right(nt,production):
    pro = []
    for i in production:
        if i.find(nt) != -1:
            if i.split("->")[1].find(nt) == -1:
                pro.append(i.split("->")[1])

    return pro


def First(i,production):

    first = set()
    pro = Right(i, production)
    for i in pro:
        flag = 0
        for j in i:
            if j.isupper():
                x = Right(j, production)
                if any("x" in s for s in x):
                    x.remove("x")
                else:
                    flag = 1
                    for j in x:
                        first.add(j)
                    break
                for k in x:
                    first.add(k)

        if flag == 0:
            first.add(i)

    return first

def FollowTab(NT,T,production):
    follow = []
    flag =0
    #print(follow)
    if NT != T :
        for i in range(len(T)):
            if T[i].isupper():
                first = First(T[i],production)
                if any("x" in s for s in first) :
                    first.remove("x")
                    for x in first:
                        follow.append(x)
                    if  i+1 != len(T) :
                        if T[i+1].isupper():
                            FollowTab(T[i+1],T[i+1:],production)
                else:
                    flag = 1
                    for x in first:
                        follow.append(x)
                    break
            else:
                follow.append(T[i])

    if flag ==0:
        follow.append("$")
    return follow




def Follow(production):
    NT = set()
    T = []
    for i in production :
        NT.add(i.split("->")[0])
    for i in production :
        T.append(i.split("->")[1])
    #print(T)
    print(NT)
    for i in NT:
        #print(i)
        if i != "S":
            for x in T:
                for y in range(len(x)):
                    if i == x[y] :
                        print(i + " :",end=" ")
                        if y+1 != len(x) :
                            print(FollowTab(x[y],x[y+1 :],production))

                        else:
                            print("$")

        elif i=="S" :
            print(i + " : $")




def main():
    production = []
    t = int(input(" Enter the no of Production :== "))
    print(" <<<== Enter the Productions :==>> ")
    for i in range(t) :
        production.append(input())
    Follow(production)

if __name__ == "__main__" :
    main()

