option(PenaltyStriker)
{
  //int numOfObstacles = theObstacleModel.obstacles.size();
  initial_state(start)
  {
    transition
    {
      if(state_time > 1000)
        goto turnToBall;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      Stand();
    }
  }
  
    state(turnToBall)
  {
    transition
    {
      if(std::abs(theBallModel.estimate.position.angle()) < 5_deg)
        goto walkToBall;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(5.f, 5.f, 5.f), Pose2f(theBallModel.estimate.position.angle(), 0.f, 0.f));
    }
  }
  
  state(walkToBall)
  {
    transition
    {
      if(theBallModel.estimate.position.norm() < 500.f)
        goto alignToGoal;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(5.f, 5.f, 5.f), theBallModel.estimate.position);
    }
  }
  
  state(alignToGoal)
  {
    transition
    {
    
      if(std::abs(libCodeRelease.angleForPenaltyStriker) < 10_deg && std::abs(theBallModel.estimate.position.y()) < 100.f)
        goto alignBehindBall;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(5.f, 5.f, 5.f), Pose2f(libCodeRelease.angleForPenaltyStriker, theBallModel.estimate.position.x() - 400.f, theBallModel.estimate.position.y()));
    }
  }
  
  state(alignBehindBall)
  {
    transition
    {
      if(libCodeRelease.between(theBallModel.estimate.position.y(), -20.f, 20.f)
          && libCodeRelease.between(theBallModel.estimate.position.x(), 140.f, 170.f)
          && std::abs(libCodeRelease.angleForPenaltyStriker) < 2_deg)
        goto shoot;
    }
    action
    {
      theHeadControlMode = HeadControl::focusBall;
      WalkToTarget(Pose2f(5.f, 5.f, 5.f), Pose2f(libCodeRelease.angleForPenaltyStriker, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() ));
    }
  }
  
  //**Kick with right leg straight**//
    state(shoot)
    {
        transition
        {
            if( (state_time > 10 && action_done))
                    goto turnToBall;
        }
        action
        {
            theHeadControlMode = HeadControl::lookForward;
            ShootKickForPenalty();//shoot type
        }
    }
      
}