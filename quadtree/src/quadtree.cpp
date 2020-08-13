#include <quadtree.h>

using namespace std;

int quadTree::quad_num = 0;

quadTree::quadTree(){

  quad_num++;

  this->topleft = point(0,0);
  this->bottomright = point(0,0);

  this->northeast = nullptr;
  this->northwest = nullptr;
  this->southeast = nullptr;
  this->southwest = nullptr;
}

quadTree::quadTree(point tl,point br){

  quad_num++;

  this->topleft = tl;
  this->bottomright = br;

  this->northeast = nullptr;
  this->northwest = nullptr;
  this->southeast = nullptr;
  this->southwest = nullptr;
}

//Insert point in the tree
void quadTree::insertNode(point *p){
  if(!inQuad(p) || p == nullptr){
	   return;
  }

  int topleft_x = this->topleft.x;
  int topleft_y = this->topleft.y;
  int bottomright_x = this->bottomright.x;
  int bottomright_y = this->bottomright.y;

  //divide quadtree till resolution is 1 unit
  if((bottomright_x - topleft_x) <= 1  && (topleft_y - bottomright_y) <= 1 ){
    //store point in this unit quadtree
    this->node = p;
    return;
  }


 //left
  if( abs(topleft_x - p->x) < abs(topleft_x - bottomright_x)/2 ){

 	  if(abs(topleft_y - p->y)  < abs(topleft_y - bottomright_y)/2) {
        northwest = new quadTree(point(topleft_x, topleft_y),
                                   point((topleft_x + bottomright_x)/2, (topleft_y + bottomright_y)/2));
        std::cout << "Northwest" << std::endl << "\n";
        northwest->insertNode(p);
	  }else{

        southwest = new quadTree(point(topleft_x,(topleft_y + bottomright_y)/2),
                                 point((topleft_x + bottomright_x)/2, bottomright_y));
        std::cout << "Southwest" << std::endl << "\n";
        southwest->insertNode(p);

    }
  //right
  }else
  {
    if(abs(topleft_y - p->y)  < abs(topleft_y - bottomright_y)/2) {
        northeast = new quadTree(point((topleft_x + bottomright_x)/2, topleft_y),
                                 point(bottomright_x,(topleft_y + bottomright_y)/2));
        std::cout << "Northeast" << std::endl << "\n";
        //put point in this new region
        northeast->insertNode(p);

     }else{
         southeast = new quadTree(point((topleft_x + bottomright_x)/2, (topleft_y + bottomright_y)/2),
                                  point(bottomright_x,bottomright_y));
         std::cout << "Southeast" << std::endl << "\n";
         southeast->insertNode(p);
     }
  }





}

//returns nearest point to a point in a tree
point quadTree::searchNearestNode(point* pt){


}

//checks if point is inside tree or not
bool quadTree::inQuad(point* pt){
  std::cout << "\nInserting Point:  x: "<< pt->x << "  y: "<<pt->y << "\n";
  std::cout << "Boundary:    " << "(" << this->topleft.x << "," << this->topleft.y <<")" << "  (" << this->bottomright.x << "," << this->bottomright.y << ")" <<"\n";

  if((pt->x <= this->bottomright.x) && (pt->x >= this->topleft.x) && (pt->y >= this->topleft.y) && (pt->y <= this->bottomright.y)){
    return true;
  }else{
    return false;
  }
}

int quadTree::getQuadNum(){
  return quad_num;
}
