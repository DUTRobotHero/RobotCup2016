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
      float x =  theGoalPost.positionOnField.x();
    if(GoalPost::Position()== GoalPost::IS_UNKNOWN || theRobotPose.translation.y() < 4000.f)
    {
        angleToGoal = (theRobotPose.inverse() * Vector2f(theFieldDimensions.xPosOpponentGroundline, 0.f)).angle();
    }
    else if(theRobotPose.translation.y() >= 4000.f)
         angleToGoal = (theRobotPose.inverse() * Vector2f(theFieldDimensions.xPosOpponentGroundline, 0.f)).angle();
    
    
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
}