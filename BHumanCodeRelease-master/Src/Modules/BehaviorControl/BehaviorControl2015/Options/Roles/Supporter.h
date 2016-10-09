option(helpStriker)
{
	float setAdjustVelocity = 1.f/2;
	
	common_transition{
		 if(otherTeammate.pose.translation.y()>=0.f)
		  goto sideleft;
		else
			goto sideright;
	}	
	initial_state(start);
	state(sideleft)
	{
		action{
			Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,otherTeammate.pose.translation.x()-400.f,
																														otherTeammate.pose.translation.y()-1000.f);
			WalkToTarget(Pose2f( 0,setAdjustVelocity,setAdjustVelocity),
                    Pose2f(0,relatePoint.translation.x(),relatePoint.translation.y()));
		}
	}
	state(sideright)
	{
		action{
			Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,otherTeammate.pose.translation.x()-400.f,
																														otherTeammate.pose.translation.y()+1000.f);
			WalkToTarget(Pose2f( 0,setAdjustVelocity,setAdjustVelocity),
                    Pose2f(0,relatePoint.translation.x(),relatePoint.translation.y()));
		}
	}
}

option(Supporter)
{
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
      if(libCodeRelease.timeSinceBallWasSeen() > 7000)
        goto searchForBall;
      if(std::abs(theBallModel.estimate.position.angle()) < 5_deg)
        goto helpStriker;
    }
    action
    {
      theHeadControlMode = HeadControl::focusBall;
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), Pose2f(theBallModel.estimate.position.angle(), 0.f, 0.f));
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
  state(helpStriker)
  {
	  transition
	  {
		   if(libCodeRelease.timeSinceBallWasSeen() > 7000)
				goto searchForBall; ;
	  }
	  action
	  {
		  theHeadControlMode = HeadControl::focusBall;
		  helpStriker();
	  }
  }
}