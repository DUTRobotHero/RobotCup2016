/** A test StrikerMing option without common decision */
#include <stdio.h>
option(StrikerMing)
{
  std::vector<Obstacle> avoidthings = theObstacleModel.obstacles;
  int frontObstacle = 0;
  int behindObstacle =0;
  int obstacleOnLine = 0;
  int ballAndObstacle_mixed = 0;
  for(int i = 0; i < avoidthings.size(); i++)
  {
      printf("center_x: %f \n",avoidthings[i].center.x() );
  }
  if(!avoidthings.empty())//判断各个位置的障碍物数量。
  {
    for(int i = 0; i < avoidthings.size(); i++)
    {
        if(avoidthings[i].center.x() + 100.f < theBallModel.estimate.position.x())
            frontObstacle++;
        else if(avoidthings[i].center.x() - 100.f > theBallModel.estimate.position.x())
            behindObstacle++;
        else
            ballAndObstacle_mixed++;
        if(std::tan(libCodeRelease.angleToGoal) > avoidthings[i].right.x() / avoidthings[i].right.y()
        && std::tan(libCodeRelease.angleToGoal) < avoidthings[i].left.x() / avoidthings[i].left.y())
            obstacleOnLine++;
    } 
  }
  printf("front: %d \n", frontObstacle);
  printf("behind: %d \n", behindObstacle);
  printf("on line: %d \n", obstacleOnLine);
  initial_state(start)
  {
    transition
    {
      
      if(state_time > 1000)
      {
        if(frontObstacle > 0)
            goto avoidObstacle;
        else  
            goto turnToBall;
      }
        
    }
    action
    {
      
      /*for(Obstacle o:theObstacleModel.obstacles)
          ShowObstacle(o.center);*/
        KeyFrameLeftArm(ArmKeyFrameRequest::back, true);
        KeyFrameRightArm(ArmKeyFrameRequest::back, true);
        theHeadControlMode = HeadControl::lookForward;
        Stand();
    }
  }

  state(turnToBall)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() > 7000)
        goto searchForBall;
      if(std::abs(theBallModel.estimate.position.angle()) < 5_deg)
        goto walkToBall;
    }
    action
    {
        KeyFrameLeftArm(ArmKeyFrameRequest::back, true);
        KeyFrameRightArm(ArmKeyFrameRequest::back, true);

        theHeadControlMode = HeadControl::lookForward;
        WalkToTarget(Pose2f(50.f,50.f,50.f), Pose2f(theBallModel.estimate.position.angle(), 0.f, 0.f));
    }
  }

  state(walkToBall)
  {
    transition
    {
        if(libCodeRelease.timeSinceBallWasSeen() > 7000)
            goto searchForBall;
        if(theBallModel.estimate.position.norm() < 500.f)
            goto alignToGoal;
    }
    action
    {
        
        KeyFrameLeftArm(ArmKeyFrameRequest::back, true);
        KeyFrameRightArm(ArmKeyFrameRequest::back, true);
       
        theHeadControlMode = HeadControl::lookForward;
      
        WalkToTarget(Pose2f(50.f, 50.f, 50.f), theBallModel.estimate.position);
     
    }
  }
  
  state(avoidObstacle)
  {
    transition
    {
      if(obstacleOnLine == 0)
          goto walkToBall;
        
    }
    action
    {
        for(int i = 0; i < avoidthings.size(); i++)
        {
            if(std::abs(std::tan(libCodeRelease.angleToGoal) - avoidthings[i].right.x() / avoidthings[i].right.y()) < 
            std::abs(std::tan(libCodeRelease.angleToGoal) - avoidthings[i].left.x() / avoidthings[i].left.y()))
                WalkToTarget(Pose2f(60.f,60.f,60.f),Pose2f(theBallModel.estimate.position.angle(),
                avoidthings[i].right.x(), avoidthings[i].right.y() - 100.f)); 
            else
                WalkToTarget(Pose2f(60.f,60.f,60.f),Pose2f(theBallModel.estimate.position.angle(),
                avoidthings[i].left.x(), avoidthings[i].left.y() + 100.f));
        }
        
    }
  }

  state(alignToGoal)
  {
    transition
    {
        
        if(libCodeRelease.timeSinceBallWasSeen() > 7000)
            goto searchForBall;
        if(std::abs(libCodeRelease.angleToGoal) < 13_deg && std::abs(theBallModel.estimate.position.y()) < 100.f && theRobotPose.translation.y() > 50.f)
            goto alignBehindBallLeft;
        else if(std::abs(libCodeRelease.angleToGoal) < 13_deg && std::abs(theBallModel.estimate.position.y()) < 100.f && theRobotPose.translation.y() < -50.f)
            goto alignBehindBallRight;
        else
            goto alignBehindBallRight;
    }
    action
    {
        theHeadControlMode = HeadControl::lookForward;
        WalkToTarget(Pose2f(100.f,100.f,100.f), Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 200.f, theBallModel.estimate.position.y()));
    }
  }

  state(alignBehindBallLeft)
  {
    transition
    {
        if(libCodeRelease.timeSinceBallWasSeen() > 7000)
            goto searchForBall;
        if((behindObstacle >= 1 || ballAndObstacle_mixed > 0) && libCodeRelease.between(theBallModel.estimate.position.y(), 20.f, 50.f)
            && libCodeRelease.between(theBallModel.estimate.position.x(), 140.f, 170.f)
            && std::abs(libCodeRelease.angleToGoal) < 8_deg)
                goto kickLeftSide;
        else if(libCodeRelease.between(theBallModel.estimate.position.y(), 20.f, 50.f)
            && libCodeRelease.between(theBallModel.estimate.position.x(), 140.f, 170.f)
            && std::abs(libCodeRelease.angleToGoal) < 8_deg)
                goto kickLeft;
    }
    action
    {
        theHeadControlMode = HeadControl::lookForward;
        WalkToTarget(Pose2f(100.f,100.f,100.f), Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() - 35.f));
    }
  }
  
  state(alignBehindBallRight)
  {
        transition
        {
            if(libCodeRelease.timeSinceBallWasSeen() > 7000)
                goto searchForBall;
            if((behindObstacle >= 1 || ballAndObstacle_mixed > 0) && libCodeRelease.between(theBallModel.estimate.position.y(), -50.f, -20.f)
            && libCodeRelease.between(theBallModel.estimate.position.x(), 140.f, 170.f)
            && std::abs(libCodeRelease.angleToGoal) < 8_deg)
                goto kickRightSide;
            else if(libCodeRelease.between(theBallModel.estimate.position.y(), -50.f, -20.f)
            && libCodeRelease.between(theBallModel.estimate.position.x(), 140.f, 170.f)
            && std::abs(libCodeRelease.angleToGoal) < 8_deg)
                goto kickRight;
        }
        
        action
        {
            theHeadControlMode = HeadControl::lookForward;
            WalkToTarget(Pose2f(100.f,100.f,100.f), Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() + 30.f));
        }
  }

  state(kickLeft)
  {
    transition
    {
      if(state_time > 3000 || (state_time > 10 && action_done))
        goto searchForBall;
    }
    action
    {
      Annotation("Alive and Kickin'");
      theHeadControlMode = HeadControl::lookForward;
      InWalkKick(WalkRequest::left, Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 160.f, theBallModel.estimate.position.y() - 55.f));
    }
  }
  
  
  state(kickRight)
  {
    transition
    {
      if(state_time > 3000 || (state_time > 10 && action_done))
        goto searchForBall;
    }
    action
    {
      Annotation("Alive and Kickin'");
      theHeadControlMode = HeadControl::lookForward;
      InWalkKick(WalkRequest::left, Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() + 55.f));
    }
  }
  
  
  state(kickLeftSide)
  {
    transition
    {
      if(state_time > 3000 || (state_time > 10 && action_done))
        goto searchForBall;
    }
    action
    {
      Annotation("Alive and Kickin'");
      theHeadControlMode = HeadControl::lookForward;
      InWalkKick(WalkRequest::sidewardsLeft, Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 160.f, theBallModel.estimate.position.y() - 55.f));
    }
  }
    state(kickRightSide)
  {
    transition
    {
      if(state_time > 3000 || (state_time > 10 && action_done))
        goto searchForBall;
    }
    action
    {
      Annotation("Alive and Kickin'");
      theHeadControlMode = HeadControl::lookForward;
      InWalkKick(WalkRequest::sidewardsRight, Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() + 55.f));
    }
  }
  
  state(searchForBall)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() < 300)
        goto turnToBall;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;    
      WalkAtSpeedPercentage(Pose2f(1.f, 0.f, 0.f));
    }
  }
}