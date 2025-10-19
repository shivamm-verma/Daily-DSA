function minCostToCut(costVer, costHor) {
    // sort in descending order
    costVer.sort((a, b) => b - a);
    costHor.sort((a, b) => b - a);

    let h = 0, v = 0, hp = 1, vp = 1;
    let cost = 0;

    while (h < costHor.length && v < costVer.length) {
        if (costHor[h] >= costVer[v]) {
            cost += costHor[h] * vp;
            h++; hp++;
        } else {
            cost += costVer[v] * hp;
            v++; vp++;
        }
    }

    while (h < costHor.length) cost += costHor[h++] * vp;
    while (v < costVer.length) cost += costVer[v++] * hp;

    return cost;
}

const costVer = [2, 1, 3, 1, 4];    // vertical cuts
const costHor = [4, 1, 2];    // horizontal cuts

console.log("Total minimum cost:", minCostToCut(costVer, costHor));
