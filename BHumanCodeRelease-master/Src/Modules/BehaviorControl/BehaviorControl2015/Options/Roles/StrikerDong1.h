/** A test striker option without common decision */
option(StrikerDong1)
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
	  theBehaviorStatus.role = Role::striker;
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
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), Pose2f(theBallModel.estimate.position.angle(), 0.f, 0.f));
    }
  }

  state(walkToBall)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() > 7000)
        goto searchForBall;
	  if(std::abs(theBallModel.estimate.position.angle()) > 20_deg)
        goto turnToBall;
      if(theBallModel.estimate.position.norm() < 500.f)
        goto alignToGoal;
    }
    action
    {
      theHeadControlMode = HeadControl::focusBall;
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), theBallModel.estimate.position);
    }
  }

  state(alignToGoal)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() > 7000)
        goto searchForBall;
      if(std::abs(libCodeRelease.angleToGoalForStriker) < 10_deg && std::abs(theBallModel.estimate.position.y()) < 100.f)
        goto alignBehindBall;
    }
    action
    {

      theHeadControlMode = HeadControl::lookHigh;
      WalkToTarget(Pose2f(100.f, 100.f, 100.f), Pose2f(libCodeRelease.angleToGoalForStriker, theBallModel.estimate.position.x() - 400.f, theBallModel.estimate.position.y()));
    }
  }
 state(alignBehindBall)
 {
	 transition
	 {
		  if(libCodeRelease.timeSinceBallWasSeen() > 7000)
		       goto searchForBall;
		 if(libCodeRelease.between(theBallModel.estimate.position.y(), -20.f, 20.f)
          && libCodeRelease.between(theBallModel.estimate.position.x(), 140.f, 170.f)
          && std::abs(libCodeRelease.angleToGoalForStriker) < 2_deg)
		  {
			if (theObstacleModel.obstacles.empty() )//若无障碍　则根据当前位置决定踢球方式
				{
					if (theRobotPose.translation.y()>2000.f)
						goto sideKickLeft;
					else if (theRobotPose.translation.y()<-2000.f)
						goto sideKickRight;
					else 
						goto shoot;
				}
			//else if (theObstacleModel.obstacles.size()==1 && theObstacleModel.obstacles[0].type == Obstacle::goalpost)//判断是否只有目标物一个障碍
			//	  goto kick;//此处可继续加强条件以达到射门条件　未测试
     		else //有障碍的情况
				{
					//有多个障碍，找到与目标方向偏离最小的障碍
					Obstacle nearist;
					float minDeltaAngle=100.f;//test value
					for (Obstacle o:theObstacleModel.obstacles)
					{
						float delta_angle=fabs(o.center.angle()-libCodeRelease.angleToGoalForStriker);
						if ( delta_angle < minDeltaAngle)
						{
								minDeltaAngle=delta_angle;
								nearist=o;
						}
					}
					//障碍较远时  则根据当前位置决定踢球方式
					if (nearist.center.norm() > 4000.f)
					{
						if (theRobotPose.translation.y()>2000.f)
							goto sideKickLeft;
						else if (theRobotPose.translation.y()<-2000.f)
							goto sideKickRight;
						else 
							goto kickLeft;
					}					
					//障碍较近 并在一条线的情况  向左或者向右变向
					else if ( libCodeRelease.between(libCodeRelease.angleToGoalForStriker, 
																	nearist.right.angle() -5_deg, 
																	nearist.left.angle() +5_deg) )//5_deg为拓展的角度大约5度
					{
						if (theRobotPose.translation.y()>0.f)
							goto sideKickLeft;
						else 
							goto sideKickRight;
					}
					//障碍较近  但是没有在一条线的情况  直接向前踢
					else
					{
						goto kickLeft;
//						if (theRobotPose.translation.y()>0.f)
//							goto kickLeft;
//						else 
//							goto kickRight;
					}
				}	 
			}
	}
	action
	{
		theHeadControlMode = HeadControl::focusBall;
        WalkToTarget(Pose2f(80.f, 80.f, 80.f), Pose2f(libCodeRelease.angleToGoalForStriker, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() - 0.f));
	}
}
//**Kick with left leg straight**//
state(kickLeft)
{
	transition
	{
		if( (state_time > 10 && action_done))
				goto turnToBall;
		if(libCodeRelease.timeSinceBallWasSeen() > 7000)
		       goto searchForBall;
		if( !theObstacleModel.obstacles.empty()  )
		{
				for (Obstacle o:theObstacleModel.obstacles)
					{
						if ( o.type == Obstacle::goalpost )
							goto shoot;
					}
		}
		if (theGameInfo.secondaryState == STATE2_PENALTYSHOOT)
			goto shoot;
	}
	action
	{
		theHeadControlMode = HeadControl::focusBall;
		//LeftKick(WalkRequest::sidewardsLeft);
		//ShootKick();//shoot type
		LeftKick(WalkRequest::left);
	}
}
//**Kick with left leg sidewards**//
state(sideKickLeft)
{
	transition
	{
		if((state_time > 10 && action_done))
				goto turnToBall;
		if(libCodeRelease.timeSinceBallWasSeen() > 7000)
		       goto searchForBall;
	}
	action
	{
		theHeadControlMode = HeadControl::focusBall;
		LeftKick(WalkRequest::sidewardsLeft);
	}
}
//**Kick with left leg sidewards**//
state(sideKickRight)
{
	transition
	{
		if( (state_time > 10 && action_done))
				goto turnToBall;
		if(libCodeRelease.timeSinceBallWasSeen() > 7000)
		       goto searchForBall;
	}
	action
	{
		theHeadControlMode = HeadControl::focusBall;
		RightKick(WalkRequest::sidewardsRight);
	}
}
//**Kick with right leg straight**//
state(shoot)
{
	transition
	{
		if( (state_time > 10 && action_done))
				goto turnToBall;
		if(libCodeRelease.timeSinceBallWasSeen() > 7000)
		       goto searchForBall;
	}
	action
	{
		theHeadControlMode = HeadControl::focusBall;
		ShootKick();//shoot type
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