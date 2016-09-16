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
      if(theBallModel.estimate.position.norm() < 500.f)
        goto alignToGoal;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(50.f, 50.f, 50.f), theBallModel.estimate.position);
    }
  }

  state(alignToGoal)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() > 7000)
        goto searchForBall;
      if(std::abs(libCodeRelease.angleToGoal) < 10_deg && std::abs(theBallModel.estimate.position.y()) < 100.f)
        goto alignBehindBall;
    }
    action
    {

      theHeadControlMode = HeadControl::lookForward;
      WalkToTarget(Pose2f(100.f, 100.f, 100.f), Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 400.f, theBallModel.estimate.position.y()));
    }
  }

//  state(alignBehindBall)
//  {
//    transition
//    {
//      if(libCodeRelease.timeSinceBallWasSeen() > 7000)
//        goto searchForBall;
//      if(libCodeRelease.between(theBallModel.estimate.position.y(), 20.f, 50.f)
//          && libCodeRelease.between(theBallModel.estimate.position.x(), 140.f, 170.f)
//          && std::abs(libCodeRelease.angleToGoal) < 2_deg)
//		  {
//			if (theObstacleModel.obstacles.empty() )//判断有无障碍
//					goto kick;
//			//else if (theObstacleModel.obstacles.size()==1 && theObstacleModel.obstacles[0].type == Obstacle::goalpost)//判断是否只有目标物一个障碍
//			//	  goto kick;//此处可继续加强条件以达到射门条件
//     		else
//				{
//					//有多个障碍，找到与目标方向偏离最小的障碍
//					Obstacle nearist;
//					float minDeltaAngle=100.f;//test value
//					for (Obstacle o:theObstacleModel.obstacles)
//					{
//						float DeltaAngle=fabs(o.center.angle()-libCodeRelease.angleToGoal);
//						if ( DeltaAngle < minDeltaAngle)
//						{
//								minDeltaAngle=DeltaAngle;
//								nearist=o;
//						}
//					}
//					//判断该障碍物是否挡在机器人和球门之间
//					//0.17为拓展的角度大约十度
//					if ( nearist.left.angle()+0.24>libCodeRelease.angleToGoal && nearist.right.angle()-0.24<libCodeRelease.angleToGoal )//在一条线的情况
//					{
//						goto sidekick;
//						//距离较远时
////						if (nearist.center.norm() > 5000.f)
////							goto kick;
////						else 
////							goto sidekick;
//					}
//					else
//					{
//							goto kick;
//					}
//				}	
//			}
//	
//    }
//    action
//    {
//
//      theHeadControlMode = HeadControl::lookForward;
//      WalkToTarget(Pose2f(80.f, 80.f, 80.f), Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() - 30.f));
//    }
//  }
//
//  state(kick)
//  {
//    transition
//    {
//      if(state_time > 3000 || (state_time > 10 && action_done))
//        goto start;
//    }
//    action
//    {
//
//      Annotation("Alive and Kickin'");
//      theHeadControlMode = HeadControl::lookForward;
//      InWalkKick(WalkRequest::left, Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 160.f, theBallModel.estimate.position.y() - 55.f));
//    }
//  }
//  state(sidekick)
//  {
//
//    transition
//    {
//      if(state_time > 3000 || (state_time > 10 && action_done))
//        goto start;
//    }
//    action
//    {
//
//      Annotation(" SideKick'");
//      theHeadControlMode = HeadControl::lookForward;
//      InWalkKick(WalkRequest::sidewardsLeft, Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() -160.f, theBallModel.estimate.position.y() - 55.f));
//    }
//  }
// 
//****************************************
 state(alignBehindBall)
 {
	 transition
	 {
		  if(libCodeRelease.timeSinceBallWasSeen() > 7000)
		       goto searchForBall;
		 if(libCodeRelease.between(theBallModel.estimate.position.y(), -30.f, 30.f)
          && libCodeRelease.between(theBallModel.estimate.position.x(), 140.f, 170.f)
          && std::abs(libCodeRelease.angleToGoal) < 2_deg)
				goto kick;
	}
	action
	{
		theHeadControlMode = HeadControl::lookForward;
        WalkToTarget(Pose2f(80.f, 80.f, 80.f), Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() - 0.f));
	}
}
state(kick)
{
	transition
	{
		if(state_time > 3000 || (state_time > 10 && action_done))
				goto start;
		if(libCodeRelease.timeSinceBallWasSeen() > 7000)
		       goto searchForBall;
	}
	action
	{
		LeftKick(WalkRequest::sidewardsLeft);
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