#include <node.h>

class quadTree
{
  //boundary of quad
  point topleft;
  point bottomright;

  //four regions
  quadTree *northwest;
  quadTree *northeast;
  quadTree *southwest;
  quadTree *southeast;

  //data that quad holds
  point *node;

public:

  //number of regions
  static int quad_num;

  quadTree();
  quadTree(point,point);

  //helper functions for quadTree
  void insertNode(point*);
  point searchNearestNode(point*);
  bool inQuad(point*);
  int getQuadNum();

};
