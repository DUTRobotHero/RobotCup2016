/**
* @file LibCodeRelease.cpp
*/

#include "../LibraryBase.h"

namespace Behavior2015
{
  #include "LibCodeRelease.h"
  
  LibCodeRelease::LibCodeRelease():
    angleToGoal(0.f)
  {}
  
  void LibCodeRelease::preProcess()
  {

      if ( theBehaviorStatus.role == Role::striker ) {
	  float y = 0.0;
	  if ( theRobotPose.translation.x () > 2500.f ) {

	      std::vector<Obstacle> p = theObstacleModel.obstacles;
	      std::vector<float> angles;
	      if ( p.size () == 0 ) 
            {
            y = 0.0;
            } 
          else if ( p.size () == 1 ) 
            {
            y = p[0].left.y () + 50.f;
            } 
          else if ( p.size () > 1 ) 
            {
                for ( unsigned int i = 0; i < p.size () - 1; i++ ) 
                {
                    angles.push_back ( LibCodeRelease::getAngle ( p[i].right, p[i + 1].left ) );
                }
            for ( unsigned int k = 0; k < angles.size (); k++ )
            {
		      float temp = 0.0;
		      int numOfObstacel = 0;
		      if ( angles[k] > temp ) 
              {
                  temp = angles[k];
                  numOfObstacel = k;
		      }
		      y = ( p[numOfObstacel].left.y () + p[numOfObstacel].right.y () ) / 2.000;
		  }
	      }

	      angleToGoal
	          = ( theRobotPose.inverse () * Vector2f ( theFieldDimensions.xPosOpponentGroundline, y ) ).angle ();
	      printf ( "the info of Goal-after: %f\n", angleToGoal * 180 / 3.1415926 );
        } 
    
        else 
        {
	      y = 0.0f;
	      angleToGoal
	          = ( theRobotPose.inverse () * Vector2f ( theFieldDimensions.xPosOpponentGroundline, y ) ).angle ();
	      printf ( "the info of Goal-before: %f\n", angleToGoal * 180 / 3.1515926 );
        }
      }
      else
	  angleToGoal= ( theRobotPose.inverse () * Vector2f ( theFieldDimensions.xPosOpponentGroundline, 0.0f ) ).angle ();
  }

  void LibCodeRelease::postProcess()
  {
  }
  
  int LibCodeRelease::timeSinceBallWasSeen()
  {
    return theFrameInfo.getTimeSince(theBallModel.timeWhenLastSeen);
  }
  
  bool LibCodeRelease::between(float value, float min, float max)
  {
    return value >= min && value <= max;
  }  

  float LibCodeRelease::getAngle(const Vector2f& vector1, const Vector2f& vector2)
  {
	float angles = 0.0;
	float length[2] = {0.0};
	length[0] = std::sqrt(vector1.x()*vector1.x() + vector1.y()*vector1.y());
	length[1] = std::sqrt(vector2.x()*vector2.x() + vector2.y()*vector2.y());
	angles = std::acos((vector1.x() * vector2.x() + vector1.y() * vector2.y())/(length[0]*length[1]));
	return angles;
  }
}