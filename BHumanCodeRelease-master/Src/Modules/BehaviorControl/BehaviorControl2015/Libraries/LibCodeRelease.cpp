
/**
* @file LibCodeRelease.cpp
*/

#include "../LibraryBase.h"

namespace Behavior2015
{
  #include "LibCodeRelease.h"
  
  LibCodeRelease::LibCodeRelease():
    angleToGoal(0.f),
	angleToGoalForStriker(0.f),
	returnFormPenalty(false),
    firstKick(true)
  {filterdObstacles.clear();}
  
  void LibCodeRelease::preProcess()
  {
	  std::vector<Obstacle> o = theObstacleModel.obstacles;
      int num = theObstacleModel.obstacles.size();
      filterdObstacles.clear();
      for(int i = 0; i < num; i++)
      {
          int k = 0;
          if(o[i].type != Obstacle::unknown)
          {
              filterdObstacles.push_back(o[i]);
              k++;
          }
              
      }
      angleToGoal = (theRobotPose.inverse() * Vector2f(theFieldDimensions.xPosOpponentGroundline, 0.f)).angle();
      float y = 0.f;
      std::vector<Obstacle> b = filterdObstacles;
      std::vector<GoalPost> g = theGoalPercept.goalPosts;
      std::vector<float> angles;
      int numb = b.size();
      int numg = g.size();
      //OUTPUT_TEXT("numb = " << numb);
      
      if(theRobotPose.translation.x() < 2200.f)
          y = 0.f;
      else 
      {
          if(std::abs(theRobotPose.translation.y()) > 750.f)
          {
              if(theRobotPose.translation.y() > 0.f && numg > 0)
                  y = 550.f;
              else if(theRobotPose.translation.y() > 0.f && numg == 0)
                  y = 300.f;
              else if(theRobotPose.translation.y() < 0.f && numg > 0)
                  y = -550.f;
              else if(theRobotPose.translation.y() < 0.f && numg == 0)
                  y = -300.f;
          }
          else
          {
               if(numb == 0)
                {
                    y = theRobotPose.translation.y();
                }
                else if(numb == 1)
                {
                    
                    if(b[0].center.y() > 0.f)
                        y = LibCodeRelease::turnCoordnate(b[0].right).y() - 100.f;
                    else
                        y = LibCodeRelease::turnCoordnate(b[0].left).y() + 100.f;
                }
                
                else
                {
                    int numOfObstacel = 0;
                    for(int i = 0; i < numb - 1; i++)
                    {
                        angles.push_back(LibCodeRelease::getAngle(b[i].right,b[i+1].left));
                    }
                    for(unsigned int k = 0; k < angles.size(); k++)
                    {
                        float temp = 0.0;
                        if(angles[k] > temp)
                        {
                            temp = angles[k];
                            numOfObstacel = k;
                        }
                    }
                    y = (LibCodeRelease::turnCoordnate(b[numOfObstacel].left).y() + LibCodeRelease::turnCoordnate(b[numOfObstacel +1].right).y())/2.f;
                }
          }
              
      }
      
      if(std::abs(y) > 750.f)
      {
          if(y > 0.f)
              y = 600.f;
          else
              y = -600.f;
      }
      //OUTPUT_TEXT("Y = " << y);
      angleToGoalForStriker = (theRobotPose.inverse() * Vector2f(theFieldDimensions.xPosOpponentGroundline, y)).angle();
      //OUTPUT_TEXT("angleToGoalForStriker" << angleToGoalForStriker * 180.f / 3.141592654);
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
	length[0]  = vector1.norm();
	length[1] =  vector2.norm();
	angles = std::acos((vector1.x() * vector2.x() + vector1.y() * vector2.y())/(length[0]*length[1]));
	return angles;
  }
  
    Vector2f LibCodeRelease::turnCoordnate(const Vector2f& vect)
    {
        float angleToRC = std::atan(vect.y()/vect.x());//矢量相对于机器人坐标系的夹角
        float angleToFC = angleToRC - theRobotPose.rotation;//矢量相对于场地坐标系的夹角
        Vector2f vectorToField = {0.f,0.f};
        vectorToField.x() = vect.x()*std::cos(angleToFC) + theRobotPose.translation.x();
        vectorToField.y() = vect.y()*std::sin(angleToFC) + theRobotPose.translation.y();
        return vectorToField;
    }
}