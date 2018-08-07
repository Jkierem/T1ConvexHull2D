#include "./Core.h"

Hull Core::naiveConvexHull( Cloud dots ){}

Hull Core::jarvisConvexHull( Cloud dots ){
  dots = Juan::sortByX(dots);
  Hull upperHull = jarvisHelper(dots);
  dots = Juan::reverseSortByX(dots);
  Hull lowerHull = jarvisHelper(dots);
  Hull convexHull;
  for( auto d : upperHull ){
    convexHull.push_back(d);
  }
  for( auto d : lowerHull ){
    convexHull.push_back(d);
  }
  return convexHull;
}

Hull Core::jarvisHelper( Cloud dots ){
  Hull convexHull;
  convexHull.push_back( Segment_2( dots[0] , dots[1] ) );
  for (size_t i = 2; i < dots.size(); i++) {
    Point_2 src = convexHull.back().source();
    Point_2 tar = convexHull.back().target();
    Point_2 next = dots[i];
    auto orientation = CGAL::orientation( src , tar , next );
    if( orientation == CGAL::RIGHT_TURN ){
      convexHull.push_back( Segment_2( tar , next ) );
    }else{
      while ( orientation != CGAL::RIGHT_TURN && !convexHull.empty() ) {
        convexHull.pop_back();
        if( !convexHull.empty() ){
          src = convexHull.back().source();
          tar = convexHull.back().target();
          orientation = CGAL::orientation( src , tar , next );
        }
      }
      if( convexHull.empty() ){
        convexHull.push_back( Segment_2( src , next ) );
      }else{
        convexHull.push_back( Segment_2( tar , next ) );
      }
    }
  }
  return convexHull;
}

Hull Core::divideAndConquerConvexHull( Cloud dots ){}
