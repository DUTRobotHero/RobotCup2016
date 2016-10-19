option(Supporter)
{
	float setAdjustVelocity = 1.f;
	float setTurnVelocity = pi/8;
	initial_state(start)
	{
		transition{
			goto sideright;
		}
		action{
      theHeadControlMode = HeadControl::lookForward;
    }
	}
		state(sideleft)
	{
		transition{
			if(otherTeammate.pose.translation.y()>=1000.f)
					goto sideright;
			if(libCodeRelease.timeSinceBallWasSeen() > 10000)
					goto searchForBall;
			if(libCodeRelease.timeSinceBallWasSeen() < 300 && theRobotPose.translation.x()>2000.f)
				goto turnToBall;
		}
		action{
			theHeadControlMode = HeadControl::searchForBall;
			Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,3200.f,1100.f);
			WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
                    Pose2f(libCodeRelease.angleToGoal,relatePoint.translation.x(),relatePoint.translation.y()));
		}
	}

	state(sideright)
	{	
		transition{
				//当strikerd的位置小于-50cm，supporter去左边
			if(otherTeammate.pose.translation.y()<=-1000.f)
					goto sideleft;
			if(libCodeRelease.timeSinceBallWasSeen() > 10000)
					goto searchForBall;
			if(libCodeRelease.timeSinceBallWasSeen() < 300 && theRobotPose.translation.x()>2000.f)
				goto turnToBall;
		}
		action{
			theHeadControlMode = HeadControl::searchForBall;
			Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,3200.f,-1100.f);
			WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
					Pose2f(libCodeRelease.angleToGoal,relatePoint.translation.x(),relatePoint.translation.y()));
		}
	}

  state(turnToBall)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() > 15000)
        goto searchForBall;
      if(std::abs(theBallModel.estimate.position.angle()) < 5_deg)
        goto stand;
    }
    action
    {
      theHeadControlMode = HeadControl::focusBall;
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), Pose2f(theBallModel.estimate.position.angle(), 0.f, 0.f));
    }
  }
  state(stand)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() < 300)
        goto turnToBall;
	 if(libCodeRelease.timeSinceBallWasSeen() > 15000)
        goto searchForBall;
    }
    action
    {
      theHeadControlMode = HeadControl::focusBall;
      Stand();
  }
  }
  
 state(searchForBall)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() < 300)
        goto turnToBall;
	  if(libCodeRelease.timeSinceBallWasSeen() > 60000)//若原地找球超过20秒(27000因为原先有7000的延时)，就回到中心
		  goto backToCenter;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;    
      WalkAtSpeedPercentage(Pose2f(1.f, 0.f, 0.f));
    }
  }
  state(backToCenter){
		  transition{
			 if( libCodeRelease.timeSinceBallWasSeen() < 300  || (state_time > 10 && action_done) )
					goto start;
			  }
		 action{
					ReadyState();
			 }
	  }
}