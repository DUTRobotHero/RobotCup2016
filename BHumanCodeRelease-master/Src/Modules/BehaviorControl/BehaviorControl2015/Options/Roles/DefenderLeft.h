//option(Defender)
// {
//	    float  X=0;
//	   float Y= 0;
//	   double  distance=0;
//      Vector2f  center=Vector2f(0.f,0.f);
//    initial_state(start)
//         {
//				 transition
// 				  {
//					  if(state_time > 1000)
//						goto act; //后卫就位；
//
//
//				   }
//				action
//				{
//				  theHeadControlMode = HeadControl::lookForward;
//				  Stand();
//		     	}
//           }
//   state(AtThePosition)
//		{
//			transition
//					{
//						if(state_time>20000)
//						{
//							goto act;
//						}
//					}
//           action
//					{
//                        LookAround();
//                        SetHeadPanTilt(0.f,0.f,150_deg);
//                        WalkToPosition(Pose2f(50.f,20.f,20.f),Pose2f(0.f,-2500.f,0.f));
//		        	}
//		  }
//	 state(act)
//		{
//             double fieldX=0;
//			transition
//			{
//						if(theObstacleModel.obstacles.empty() == true)
//						{
//							 goto  AtThePosition;
//			            }
//						else
//						{
//							  int  VectorSize=0;
//						      VectorSize=theObstacleModel.obstacles.size();
//								for(int i=0;i<VectorSize;i++)
//								{
//										if(theObstacleModel.obstacles[i].type==Obstacle::opponent)
//											{
//												X=theObstacleModel.obstacles[i].center.x();
//                                               Y= theObstacleModel.obstacles[i].center.y();
//                                              center=Vector2f(X,Y);
//											}
//										else
//					                     continue;
//                                    fieldX=cos(theRobotPose.rotation)*X-sin(theRobotPose.rotation)*Y+theRobotPose.translation.x();
//							       }
//								distance = std::sqrt(X*X+Y*Y);
//								if(distance<=2500 && fieldX<=0) //如果defender和Opponent之间得距离小于2000mm且Opponent已经过中线；
//								  goto  defendOpponent;
//
//                        }
//             }
//        action
//                {
//	                 SetHeadPanTilt(0.f,0.f,150_deg);
//                     LookAround();
//		            Position("Opponent  Position",center);
//                    Value("Robot and Defender's Distance",distance);
//		        }
//		}
//    state(defendOpponent)
//			 {
//				 transition
//				 {
//                     if(theObstacleModel.obstacles.empty()==true)
//						{
//							goto  lookAround;
//		                }
//						else
//						{
//							  int  VectorSize=0;
//						      VectorSize=theObstacleModel.obstacles.size();
//								for(int i=0;i<VectorSize;i++)
//								{
//										if(theObstacleModel.obstacles[i].type==Obstacle::opponent)
//											{
//												X=theObstacleModel.obstacles[i].center.x()-300.f;
//                                               Y= theObstacleModel.obstacles[i].center.y();
//                                              center=Vector2f(X,Y);
//											}
//										else
//                                            continue;
//							       }
//
//			        }
//                 }
//                action
//					{
//						  SetHeadPanTilt(0.f,-0.2f,150_deg);
//                          WalkToTarget(Pose2f(50.f,50.f,50.f),Pose2f(0.f, X,Y));
//					      Position("Opponent  Position",center);
//                          Value("Robot and Defender's Distance",distance);
//					  }
//            }
//
//    state(lookAround)
//                 {
//                     transition
//                     {
//                         if(theObstacleModel.obstacles.empty()==true && state_time>=20000)
//                             {
//                                goto AtThePosition ;
//                             }
//                       else
//                          {
//                                  int  VectorSize=0;
//                                  VectorSize=theObstacleModel.obstacles.size();
//								  for(int i=0;i<VectorSize;i++)
//								    {
//										if(theObstacleModel.obstacles[i].type==Obstacle::someRobot  || theObstacleModel.obstacles[i].type==Obstacle::opponent)
//											 {
//												   goto defendOpponent;
//										   	 }
//										else
//                                            continue;
//                                    }
//
//                          }
//                       }
//
//	                  action
//                           {
//                                Position("Opponent Position",center);
//                                 Value("Robot Own rotation",theRobotPose.rotation);
//                                 LookAround();
//
//                           }
//                 }
//
//
//
//  }
//
//
//
//                 */

//每个状态必须 !IsInPenaltyArea 并且 x < -900
//if（看到球）
//直接走过去
//       if（障碍物距离较远）
//               开大脚
//       else
//               左脚踢
//else
// searchForBall（转头）
//     if ( 对方机器人很近）
//          走上去挡住 （注意控制距离 ）
//     else
//          goto start
option(DefenderLeft)
{
    initial_state(start) {
        transition {
            if( libCodeRelease.timeSinceBallWasSeen() > 7000 )
                goto searchForBall;
            Pose2f Ball2Field = BallModel2Field(theBallModel,theRobotPose);
            if( libCodeRelease.timeSinceBallWasSeen() < 300 &&  Ball2Field.translation.x() < -1000.0)
                goto walkToBall;
            if ( theRobotPose.translation.x() > -2500.0)
                goto ReturnToDefendArea;
            //Is this really neccessary？
            /*            bool RobotInPenaltyArea = IsRobotInPenaltyArea(theRobotPose);
                        if( RobotInPenaltyArea )
                            goto OutOfPenaltyArea;*/
        }
        action {
            theHeadControlMode = HeadControl::lookForward;
            Annotation("I am in initial_state");
            Pose2f Ball2Field = BallModel2Field(theBallModel,theRobotPose);
            ShowBallToField(Ball2Field);
            ShowBallToRobot(theBallModel.estimate.position);
            ShowRobotToField(theRobotPose);

            Pose2f relatePoint=AbsolutePointToRobot(theRobotPose,-2500.0,1100.0);
            WalkToTarget(Pose2f(pi/8,1.f,1.f),relatePoint);
        }
    }

    state(walkToBall) {
        transition {
            if(libCodeRelease.timeSinceBallWasSeen() > 7000)    //naive版本，不管障碍物，原地转头找球
                goto searchForBall;
            if(std::abs(theBallModel.estimate.position.angle()) > 20_deg)
                goto turnToBall;
            if(theBallModel.estimate.position.norm() < 500.f)
                goto alignBehindBall;
            if ( theRobotPose.translation.x() > -2500.0)
                goto ReturnToDefendArea;
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
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

    state(turnToBall) {
        transition {
            if(libCodeRelease.timeSinceBallWasSeen() > 7000)
                goto searchForBall;
            if(std::abs(theBallModel.estimate.position.angle()) < 5_deg)
                goto walkToBall;
            if ( theRobotPose.translation.x() > -2500.0)
                goto ReturnToDefendArea;
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            WalkToTarget(Pose2f(50.f, 50.f, 50.f), Pose2f(theBallModel.estimate.position.angle(), 0.f, 0.f));
        }
    }

    state(alignBehindBall) {
        transition {
            if(libCodeRelease.timeSinceBallWasSeen() > 7000)
                goto searchForBall;
            if(libCodeRelease.between(theBallModel.estimate.position.y(), -20.f, 20.f)
            && libCodeRelease.between(theBallModel.estimate.position.x(), 140.f, 170.f)
            && std::abs(libCodeRelease.angleToGoalForStriker) < 2_deg) {
                if (theObstacleModel.obstacles.empty() ) { //若无障碍　则根据当前位置决定踢球方式
                    if (theRobotPose.translation.y()>2000.f)
                        goto sideKickLeft;
                    else if (theRobotPose.translation.y()<-2000.f)
                        goto sideKickRight;
                    else
                        goto shoot;
                }
                //else if (theObstacleModel.obstacles.size()==1 && theObstacleModel.obstacles[0].type == Obstacle::goalpost)//判断是否只有目标物一个障碍
                //	  goto kick;//此处可继续加强条件以达到射门条件　未测试
                else { //有障碍的情况
                    //有多个障碍，找到与目标方向偏离最小的障碍
                    Obstacle nearist;
                    float minDeltaAngle=100.f;//test value
                    for (Obstacle o:theObstacleModel.obstacles) {
                        float delta_angle=fabs(o.center.angle()-libCodeRelease.angleToGoalForStriker);
                        if ( delta_angle < minDeltaAngle) {
                            minDeltaAngle=delta_angle;
                            nearist=o;
                        }
                    }
                    //障碍较远时  则根据当前位置决定踢球方式
                    if (nearist.center.norm() > 4000.f) {
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
                                                     nearist.left.angle() +5_deg) ) { //5_deg为拓展的角度大约5度
                        if (theRobotPose.translation.y()>0.f)
                            goto sideKickLeft;
                        else
                            goto sideKickRight;
                    }
                    //障碍较近  但是没有在一条线的情况  直接向前踢
                    else {
                        goto kickLeft;
//						if (theRobotPose.translation.y()>0.f)
//							goto kickLeft;
//						else
//							goto kickRight;
                    }
                }
            }
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            WalkToTarget(Pose2f(pi/8, 20.f, 20.f), Pose2f(libCodeRelease.angleToGoalForStriker, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() - 0.f));
        }
    }

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
//**Kick with left leg sidewards**//
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
//**Kick with right leg straight**//
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
            //LeftKick(WalkRequest::sidewardsLeft);
            //ShootKick();//shoot type
            LeftKick(WalkRequest::left);
        }
    }

    state(shoot) {
        transition {
            if( (state_time > 10 && action_done))
                goto turnToBall;
            if(libCodeRelease.timeSinceBallWasSeen() > 7000)
                goto searchForBall;
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            ShootKick();//shoot type
        }
    }

    state(ReturnToDefendArea) {
        transition {
            Pose2f Ball2Field = BallModel2Field(theBallModel,theRobotPose);

            if( libCodeRelease.timeSinceBallWasSeen() < 300 &&  Ball2Field.translation.x() < -1000.0)
                goto walkToBall;
            if( libCodeRelease.timeSinceBallWasSeen() > 5000 )
                goto searchForBall;
            if(state_time > 10000)
                goto start;
        }
        action {
            Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,-2500.0,theRobotPose.translation.y());
            WalkToTarget(Pose2f(30.f,30.f,30.f),relatePoint);
            theHeadControlMode = HeadControl::searchForBall;
        }
    }


    state(searchForBall) {
        transition {
            Pose2f Ball2Field = BallModel2Field(theBallModel,theRobotPose);

            if(libCodeRelease.timeSinceBallWasSeen() < 300 && Ball2Field.translation.x() < -1000.0)
                goto turnToBall;

            if(state_time>5000)
                goto start;

        }
        action {

            theHeadControlMode = HeadControl::searchForBall;
        }
    }
}
