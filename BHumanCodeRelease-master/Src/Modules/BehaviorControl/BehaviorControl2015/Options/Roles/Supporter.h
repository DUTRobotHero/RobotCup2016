option(helpStriker)
{
	float setAdjustVelocity = 1.f/2;
	float setTurnVelocity = pi/8;
	
	/*common_transition{
		 if(otherTeammate.pose.translation.y()>=0.f)
		  goto sideleft;
		else
			goto sideright;
	}	*/
	initial_state(start)
	{
		transition{
			goto sideright;
		}
	}
	//当strikerd的位置大于50cm，supporter去右边
	state(sideleft)
	{
		transition{
			if(otherTeammate.pose.translation.y()>=500.f)
					goto sideright;
		}
		action{
			Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,otherTeammate.pose.translation.x()-400.f,
																														otherTeammate.pose.translation.y()+1000.f);
			WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
                    Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
		}
	}
	//当strikerd的位置小于-50cm，supporter去左边
	state(sideright)
	{	
		transition{
			if(otherTeammate.pose.translation.y()<=-500.f)
					goto sideleft;
		}
		action{
			Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,otherTeammate.pose.translation.x()-400.f,
																														otherTeammate.pose.translation.y()-1000.f);
			WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
                    Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
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
	  if(libCodeRelease.timeSinceBallWasSeen() > 17000)//若原地找球超过20秒(27000因为原先有7000的延时)，就回到中心
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
					goto turnToBall;
			  }
		 action{
					ReadyState();
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