#include "Juan.h"
#include <ctgmath>
#include <iostream>

Transformation Juan::getRotationMatrix(float d){
  Transformation t(cos(d),-1*sin(d),sin(d),cos(d),1);
  return t;
}

Transformation Juan::getScaleMatrix(float sx , float sy){
  Transformation t(sx,0,0,sy,1);
  return t;
}

Transformation Juan::getTranslationMatrix( float tx , float ty){
  Transformation t(1,0,tx,0,1,ty,1);
  return t;
}

std::vector<Point_2> Juan::generateRandomPoints( int n , Ellipse e){
  std::random_device device;
  std::mt19937 mt(device());
  std::uniform_real_distribution<double> rDist(0.0, 1.0);
  std::uniform_real_distribution<double> thetaDist(0.0, 2.0);
  std::vector<Point_2> dots;
  for (size_t i = 0; i < n; i++) {
    float r = rDist(mt);
    Point_2 p(r,0);
    float theta = thetaDist(mt)*M_PI;
    Transformation randomRotation = getRotationMatrix(theta);
    p = randomRotation(p);
    dots.push_back(p);
  }
  Transformation scale = getScaleMatrix(e.r1 , e.r2);
  Transformation rotate = getRotationMatrix(e.angle*M_PI);
  Transformation translate = getTranslationMatrix(e.center.x() , e.center.y());
  for( auto& dot : dots ){
    dot = translate(rotate(scale(dot)));
  }
  return dots;
}

bool Juan::comparator( Point_2 a , Point_2 b ){
  return a.x() < b.x();
}

bool Juan::reverseComparator( Point_2 a , Point_2 b ){
  return a.x() > b.x();
}

Cloud Juan::sortByX( Cloud dots ){
  std::sort( dots.begin() , dots.end() , Juan::comparator );
  return dots;
}

Cloud Juan::reverseSortByX( Cloud dots ){
  std::sort( dots.begin() , dots.end() , Juan::reverseComparator );
  return dots;
}
