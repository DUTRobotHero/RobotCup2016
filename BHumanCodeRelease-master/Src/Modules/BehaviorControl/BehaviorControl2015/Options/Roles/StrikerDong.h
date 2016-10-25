/** A striker option write by dong */
/*StrikerDong策略简介
 * StrikerDong的策略是参照bhuman给出的测试版Striker在其基础上丰富了踢球动作
 * 调用了libCodeRelease.cpp 中由Ming写的angleToGoalForStriker作为踢球方向
 * 各个state介绍：
 * turnToBall
 * walkToBall
 * alignToGoal(将身体转向球门)
 * alignBehindBall(使身体，球，球门在一条直线)(这时会根据看到的障碍决定踢球姿势)
 * alignBesideBall(当在alignBehindBall发现球在身后的时候会进入这个state先走到球的边上)
 * kickLeft 左脚直踢
 * sideKickLeft　左脚向右边踢
 * sideKickRight　右脚向左边踢
 * shoot　射门动作
 * searchForBall　找球
 * backToCenter 回到中心圆(如果长时间没找到球就会切到这个state下,依赖于Xing写的ReadyState())
 * */
option(StrikerDong)
{
	float angleRange=2_deg;
    initial_state(start) {
        transition {
            if(state_time > 1000)
                goto turnToBall;
        }
        action {
            theHeadControlMode = HeadControl::lookForward;
            theBehaviorStatus.role = Role::striker;
        }
    }

    state(turnToBall) {
        transition {
            if(libCodeRelease.timeSinceBallWasSeen() > 7000)
                goto searchForBall;
            if(std::abs(theBallModel.estimate.position.angle()) < 5_deg)
                goto walkToBall;
        }
        action {
            theHeadControlMode = HeadControl::lookForward;
            WalkToTarget(Pose2f(50.f, 50.f, 50.f), Pose2f(theBallModel.estimate.position.angle(), 0.f, 0.f));
        }
    }

    state(walkToBall) {
        transition {
            if(libCodeRelease.timeSinceBallWasSeen() > 7000)
                goto searchForBall;
            if(std::abs(theBallModel.estimate.position.angle()) > 20_deg)
                goto turnToBall;
            if(theBallModel.estimate.position.norm() < 500.f)
                goto alignToGoal;
        }
        action {
            theHeadControlMode = HeadControl::lookForward;
			//控制走向球的速度，由于步态没有调，所以走的速度过快会摔倒，这里根据距离球的距离将走路速度调低，如果能把步态调好这里可以加快速度
            Pose2f speed(0.f,0.f,0.f);
            if  ( theBallModel.estimate.position.norm() > 3500.f )
                speed=Pose2f(1.f,1.f,1.f);
            else if (theBallModel.estimate.position.norm() > 3000.f)
                speed=Pose2f(5.f,5.f,5.f);
            else if (theBallModel.estimate.position.norm() > 2500.f)
                speed=Pose2f(8.f, 8.f, 8.f);
            else if (theBallModel.estimate.position.norm() > 2000.f)
                speed=Pose2f(10.f,10.f,10.f);
            else if (theBallModel.estimate.position.norm() > 1500.f)
                speed=Pose2f(12.f, 12.f, 12.f);
            else if (theBallModel.estimate.position.norm() > 1000.f)
                speed=Pose2f(15.f, 15.f, 15.f);
            else if (theBallModel.estimate.position.norm() > 700.f)
                speed=Pose2f(18.f, 18.f, 18.f);
            else
                speed=Pose2f(20.f, 20.f, 20.f);
            WalkToTarget(speed, theBallModel.estimate.position);
        }
    }
  state(alignToGoal)
  {
    transition
    {
      if(libCodeRelease.timeSinceBallWasSeen() > 7000)
        goto searchForBall;
	  if (theBallModel.estimate.position.x() < 0)
			 goto alignBesideBall; 
      if(std::abs(libCodeRelease.angleToGoalForStriker) < 10_deg && std::abs(theBallModel.estimate.position.y()) < 100.f)
        goto alignBehindBall;
    }
    action
    {
            theHeadControlMode = HeadControl::lookHigh;
            WalkToTarget(Pose2f(60.f, 60.f, 60.f), Pose2f(libCodeRelease.angleToGoalForStriker, theBallModel.estimate.position.x() - 400.f, theBallModel.estimate.position.y()));
        }
    }

 state(alignBehindBall)
 {
	 transition
	 {
		 if (theRobotPose.translation.x()>3800.f && theRobotPose.translation.y()<750.f &&theRobotPose.translation.y() >-750.f )
			 angleRange=5_deg;
		else
			angleRange=2_deg;
		  if(libCodeRelease.timeSinceBallWasSeen() > 7000)
		       goto searchForBall;
		 if (theBallModel.estimate.position.x() < 0)
			 goto alignBesideBall;
		 if(libCodeRelease.between(theBallModel.estimate.position.y(), -20.f, 20.f)
          && libCodeRelease.between(theBallModel.estimate.position.x(), 140.f, 170.f)
          && std::abs(libCodeRelease.angleToGoalForStriker) < angleRange)
		  {
			if (libCodeRelease.theObstacleModel.obstacles.empty() )//若无障碍　则根据当前位置决定踢球方式
				{
					/*if (theRobotPose.translation.y()>2000.f)
						goto sideKickLeft;
					else if (theRobotPose.translation.y()<-2000.f)
						goto sideKickRight;
					else*/ 
						goto shoot;
				}
     		else //有障碍的情况
				{
					//有多个障碍，找到与目标方向偏离最小的障碍
					Obstacle nearist;
					float minDeltaAngle=100.f;//test value
					for (Obstacle o:libCodeRelease.filterdObstacles)
					{
						float delta_angle=fabs(o.center.angle()-libCodeRelease.angleToGoalForStriker);
						if ( delta_angle < minDeltaAngle)
						{
								minDeltaAngle=delta_angle;
								nearist=o;
						}
					}
					//障碍较远时  则根据当前位置决定踢球方式
					if (nearist.center.norm() > 2000.f)
					{
						/*if (theRobotPose.translation.y()>2000.f)
							goto sideKickLeft;
						else if (theRobotPose.translation.y()<-2000.f)
							goto sideKickRight;
						else*/ 
							goto shoot;
					}					
					//障碍较近 并在一条线的情况  向左或者向右变向
					else if ( libCodeRelease.between(libCodeRelease.angleToGoalForStriker, 
																	nearist.right.angle() - 5_deg, 
																	nearist.left.angle() + 5_deg) )//5_deg为拓展的角度大约5度
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
					}
				}	 
			}
	}
	action
	{
		theHeadControlMode = HeadControl::focusBall;
        WalkToTarget(Pose2f(pi/8, 20.f, 20.f), Pose2f(libCodeRelease.angleToGoalForStriker, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y()));
	}
}
/* When the ball is behind robot ,this state make robot walk beside the ball first*/
state(alignBesideBall)
{
	transition
	{
		if(libCodeRelease.timeSinceBallWasSeen() > 7000)
		       goto searchForBall;
		if (theBallModel.estimate.position.x() > 40.f)
			   goto alignBehindBall;
	}
	action
	{
		theHeadControlMode = HeadControl::focusBall;
		if (theBallModel.estimate.position.y() > 0){
			WalkToTarget(Pose2f(pi/8, 20.f, 20.f), Pose2f(libCodeRelease.angleToGoalForStriker, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() - 120.f));
			}
		else {
			WalkToTarget(Pose2f(pi/8, 20.f, 20.f), Pose2f(libCodeRelease.angleToGoalForStriker, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() + 120.f));
			}
	}
}

//Kick with left leg straight
    state(kickLeft) {
        transition {
            if( (state_time > 10 && action_done))
                goto turnToBall;
            if(libCodeRelease.timeSinceBallWasSeen() > 7000)
                goto searchForBall;
            if( !theObstacleModel.obstacles.empty()  ) {
                for (Obstacle o:theObstacleModel.obstacles) {
                    if ( o.type == Obstacle::goalpost )
                        goto shoot;
                }
            }
            if (theGameInfo.secondaryState == STATE2_PENALTYSHOOT)
                goto shoot;
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            LeftKick(WalkRequest::left);
        }
    }
//Kick with left leg sidewards
    state(sideKickLeft) {
        transition {
            if((state_time > 10 && action_done))
                goto turnToBall;
            if(libCodeRelease.timeSinceBallWasSeen() > 7000)
                goto searchForBall;
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            LeftKick(WalkRequest::sidewardsLeft);
        }
    }
//Kick with left leg sidewards
    state(sideKickRight) {
        transition {
            if( (state_time > 10 && action_done))
                goto turnToBall;
            if(libCodeRelease.timeSinceBallWasSeen() > 7000)
                goto searchForBall;
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            RightKick(WalkRequest::sidewardsRight);
        }
    }
//Kick with right leg straight
    state(shoot) {
        transition {
            if (libCodeRelease.firstKick==true ) {
                libCodeRelease.firstKick=false;
                goto firstKick;
            }
            if( (state_time > 10 && action_done))
                goto turnToBall;
            if(libCodeRelease.timeSinceBallWasSeen() > 7000)
                goto searchForBall;
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            ShootKick();
        }
    }
    state(firstKick) {
        transition {
            if( (state_time > 10 && action_done))
                goto turnToBall;
            if(libCodeRelease.timeSinceBallWasSeen() > 7000)
                goto searchForBall;
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            LeftKick(WalkRequest::sidewardsLeft);
        }
    }
    state(searchForBall) {
        transition {
            if(libCodeRelease.timeSinceBallWasSeen() < 300)
                goto turnToBall;
            if(libCodeRelease.timeSinceBallWasSeen() > 17000)//若原地找球超过20秒(27000因为原先有7000的延时)，就回到中心
                goto backToCenter;
        }
        action {
            theHeadControlMode = HeadControl::lookForward;
            WalkAtSpeedPercentage(Pose2f(1.f/2, 0.f, 0.f));
        }
    }
    state(backToCenter) {
        transition {
            if( libCodeRelease.timeSinceBallWasSeen() < 300  || (state_time > 10 && action_done) )
                goto turnToBall;
        }
        action {
            ReadyState();
        }
    }
}
