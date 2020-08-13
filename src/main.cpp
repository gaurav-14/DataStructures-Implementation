#include <iostream>
#include <quadtree.h>

#include <visualize.h>

using namespace std;

int main(){

quadTree *tree = new quadTree(point(0,0),point(30,30));


point *pt1 = new point(1,1);
//std::cout << "Point:\n" << "x: "<< pt1->x << "  y: " << pt1->y << '\n';
tree->insertNode(pt1);

pt1 = new point(19,19);
//std::cout << "Point:\n" << "x: "<< pt1->x << "  y: " << pt1->y << '\n';
tree->insertNode(pt1);

pt1 = new point(20,10);
//std::cout << "Point:\n" << "x: "<< pt1->x << "  y: " << pt1->y << '\n';
tree->insertNode(pt1);

std::cout << "\ntotal quads: " << tree->getQuadNum()<< '\n';


quadviz viz(300,400);
viz.createbackgrd();
viz.showquad();


return 0;
}
