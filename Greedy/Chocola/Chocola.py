def min_cost_to_cut(cost_ver, cost_hor):
    # sort in descending order
    cost_ver.sort(reverse=True)
    cost_hor.sort(reverse=True)

    h = v = 0      
    hp = vp = 1     
    cost = 0

    while h < len(cost_hor) and v < len(cost_ver):
        if cost_hor[h] >= cost_ver[v]:
            cost += cost_hor[h] * vp
            h += 1
            hp += 1
        else:
            cost += cost_ver[v] * hp
            v += 1
            vp += 1

    while h < len(cost_hor):
        cost += cost_hor[h] * vp
        h += 1
        hp += 1

    while v < len(cost_ver):
        cost += cost_ver[v] * hp
        v += 1
        vp += 1

    return cost


# example 
cost_ver = [2, 1, 3, 1, 4]   # vertical cuts
cost_hor = [4, 1, 2]   # horizontal cuts

print("Total minimum cost:", min_cost_to_cut(cost_ver, cost_hor))
