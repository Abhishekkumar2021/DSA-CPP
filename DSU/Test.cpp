#include "DSU.h"

int main(){
    DSU d(10);
    d.unionSet(1, 2);
    d.drawGraph("graph1");
    d.unionSet(2, 3);
    d.drawGraph("graph2");
    d.unionSet(4, 5);
    d.drawGraph("graph3");
    d.unionSet(5, 6);
    d.drawGraph("graph4");
    d.unionSet(3, 6);
    d.drawGraph("graph5");
    d.unionSet(7, 8);
    d.drawGraph("graph6");
    d.unionSet(8, 9);
    d.drawGraph("graph7");
    d.unionSet(9, 7);
    d.drawGraph("graph8");
    d.unionSet(1, 7);
    d.drawGraph("graph9");
    return 0;
}
