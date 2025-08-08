t = int(input())
for _ in range(t):
    g = {}
    p = {}

    for _ in range(12):
        h, gh, tmp, ga, a = input().split()
        gh = int(gh)
        ga = int(ga)

        if h in g:
            g[h] += (gh - ga)
            if gh > ga:
                p[h] += 3
            elif gh == ga:
                p[h] += 1
        else:
            g[h] = (gh - ga)
            p[h] = 3 if gh > ga else 1 if gh == ga else 0

        if a in g:
            g[a] += (ga - gh)
            if ga > gh:
                p[a] += 3
            elif ga == gh:
                p[a] += 1
        else:
            g[a] = (ga - gh)
            p[a] = 3 if ga > gh else 1 if ga == gh else 0

    for _ in range(2):
        w = next(iter(p))
        for team in p:
            if p[w] < p[team]:
                w = team
            elif p[w] == p[team]:
                if g[w] < g[team]:
                    w = team

        print(w, end=" ")
        del p[w]
    
    print()
    