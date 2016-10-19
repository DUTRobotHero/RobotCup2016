option(Keeper)
{
    initial_state(start) {
        transition {
            if(libCodeRelease.timeSinceBallWasSeen() > 500)
                goto searchForBall;

            //判断球在不同的区域，进行相应的防守动作
            int area = GetAreaNumber(theBallModel,theRobotPose);
            if(area == 2)
                goto WalkToMiddlePoint;
            else if(area == 1)
                goto WalkToVerticalPoint;
            else if(area == 4)
                goto turnToBall;
        }
        action {
            theHeadControlMode = HeadControl::lookForward;
            Annotation("I am in initial_state");
            Pose2f Ball2Field = BallModel2Field(theBallModel,theRobotPose);
            ShowBallToField(Ball2Field);
            ShowBallToRobot(theBallModel.estimate.position);
            ShowRobotToField(theRobotPose);
            int area = GetAreaNumber(theBallModel,theRobotPose);
            ShowArea(area);
            Pose2f relatePoint=AbsolutePointToRobot(theRobotPose,-4200.0,0.0);
            WalkToTarget(Pose2f(pi/8,20.f,20.f),relatePoint);
        }
    }

    state(WalkToVerticalPoint) {
        transition {
            //如果在防守区域内，则跳转到WalkToMiddlePoint
            int area = GetAreaNumber(theBallModel,theRobotPose);
            if (area == 2)
                goto WalkToMiddlePoint;
            if( area == 4)
                goto turnToBall;
            bool RobotInPenaltyArea = IsRobotInPenaltyArea(theRobotPose);
            if( !RobotInPenaltyArea )
                goto ReturnToPenaltyArea;
            if(std::abs(theBallModel.estimate.position.angle()) > 60_deg)    //这个角度不要太小
                goto turnToBall;
            if ( std::abs(theBallModel.estimate.position.angle()) < 15_deg && theBallModel.estimate.position.norm() < 230.f)
                goto kick;
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            Pose2f Ball2Field = BallModel2Field(theBallModel,theRobotPose);
            ShowBallToField(Ball2Field);
            ShowBallToRobot(theBallModel.estimate.position);
            ShowRobotToField(theRobotPose);
            int area = GetAreaNumber(theBallModel,theRobotPose);
            ShowArea(area);
            //too slow
       /*    WalkToTargetAbsolute(Pose2f(theRobotPose.rotation - Ball2Field.rotation > 0 ? -pi / 8 : pi / 8,
            theRobotPose.translation.x()+3900 > 0? -30.f: 30.f,
            theRobotPose.translation.y()-Ball2Field.translation.y() > 0? -30.f: 30.f),Pose2f(0.0,-4000.0,Ball2Field.translation.y()));*/
            //先转身再垂直距离走过去
            float aim_x = -3950.0;
        //    float aim_y = 550* Ball2Field.translation.y()/(Ball2Field.translation.x()+4500.0);
            float aim_y = Ball2Field.translation.y();
            //转化为相对于机器人的坐标
            Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,aim_x,aim_y);
            WalkToTarget(Pose2f(50.f,40.f,40.f),Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
            ShowSomething(theBallModel.estimate.position.norm());

        }
    }

    state(WalkToMiddlePoint) {
        transition {
            bool RobotInPenaltyArea = IsRobotInPenaltyArea(theRobotPose);
            if( !RobotInPenaltyArea)
                goto ReturnToPenaltyArea;
            int area = GetAreaNumber(theBallModel,theRobotPose);
            if (area == 1)
                goto WalkToVerticalPoint;
            else if( area == 4)
                goto turnToBall;
            else if ( std::abs(theBallModel.estimate.position.angle()) < 15_deg && theBallModel.estimate.position.norm() < 230.f)
                goto kick;
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            Pose2f Ball2Field = BallModel2Field(theBallModel,theRobotPose);
            int area = GetAreaNumber(theBallModel,theRobotPose);

           Vector2f mid = RobotMidPosition(theBallModel,theRobotPose,710.0); //场地绝对坐标
     //       WalkToTarget(Pose2f(50.f,40.f,40.f),Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
         WalkToTargetAbsolute(Pose2f(theRobotPose.rotation - Ball2Field.rotation > 0 ? -pi / 32 : pi / 32,
            theRobotPose.translation.x()-mid.x() > 0? -20.f: 20.f,
            theRobotPose.translation.y()-mid.y() > 0? -20.f: 20.f),Pose2f(Ball2Field.rotation,mid.x(),mid.y()));

          /*  float aim_x = -3950.0;
            float aim_y = 550* Ball2Field.translation.y()/(Ball2Field.translation.x()+4500.0);
            //转化为相对于机器人的坐标
            Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,aim_x,aim_y);
            WalkToTarget(Pose2f(50.f,40.f,40.f),Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));*/
            
            ShowRobotToField(theRobotPose);
            ShowBallToField(Ball2Field);
            ShowBallToRobot(theBallModel.estimate.position);
            ShowArea(area);
            ShowSomething(theBallModel.estimate.position.norm());

        }
    }

    state(ReturnToPenaltyArea) {
        transition {
            if(libCodeRelease.timeSinceBallWasSeen() > 500)
                goto searchForBall;
            int area = GetAreaNumber(theBallModel,theRobotPose);
            bool RobotInPenaltyArea = IsRobotInPenaltyArea(theRobotPose);
            if( RobotInPenaltyArea ) {
                if(area == 1)
                    goto WalkToVerticalPoint;
                else if(area == 2)
                    goto WalkToMiddlePoint;
                else if( area == 4)
                    goto turnToBall;
            }
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            Pose2f Ball2Field = BallModel2Field(theBallModel,theRobotPose);
            ShowBallToField(Ball2Field);
            ShowBallToRobot(theBallModel.estimate.position);
            ShowRobotToField(theRobotPose);
            int area = GetAreaNumber(theBallModel,theRobotPose);
            ShowArea(area);
            if ( theRobotPose.translation.x() >= -3900 ) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,-4200.0,0.0);
                WalkToTarget(Pose2f(50.f,80.f,80.f),relatePoint);
                ShowRobotToField(relatePoint);
            }
            if (  theRobotPose.translation.x() < -4400) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,-4200.0,0.0);
                WalkToTarget(Pose2f(50.f,80.f,80.f),relatePoint);
                ShowRobotToField(relatePoint);

            }
            ShowSomething(theBallModel.estimate.position.norm());

        }
    }

    state(turnToBall) {
        transition {
            if(libCodeRelease.timeSinceBallWasSeen() > 500)
                goto searchForBall;
            /*       if(std::abs(theBallModel.estimate.position.angle()) < 15_deg )    //原来是5_deg
                       goto WalkToVerticalPoint;*/
            int area = GetAreaNumber(theBallModel,theRobotPose);
            if( area == 4)
                goto WalkToBall;
            else if( area == 2)
                goto WalkToMiddlePoint;
            else if( area == 1) {
                if(std::abs(theBallModel.estimate.position.angle()) >= 15_deg ||  theBallModel.estimate.position.norm() >= 230.f )
                    goto WalkToVerticalPoint;
                else if(std::abs(theBallModel.estimate.position.angle()) < 5_deg && theBallModel.estimate.position.norm() < 230.f )
                    goto kick;
            }

        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            WalkToTarget(Pose2f(50.f, 50.f, 50.f), Pose2f(theBallModel.estimate.position.angle(), 0.f, 0.f));
            int area = GetAreaNumber(theBallModel,theRobotPose);
            ShowArea(area);
            ShowBallToRobot(theBallModel.estimate.position);
            ShowSomething(theBallModel.estimate.position.norm());

        }
    }

    state(WalkToBall) {
        transition {
            if(libCodeRelease.timeSinceBallWasSeen() > 500)
                goto searchForBall;

            if(theBallModel.estimate.position.norm() < 500.f)
                goto alignBehindBall;
            int area = GetAreaNumber(theBallModel,theRobotPose);
            if( area == 2 )
                goto WalkToMiddlePoint;
            else if( area == 1)
                goto WalkToVerticalPoint;
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            WalkToTarget(Pose2f(50.f, 50.f, 50.f), theBallModel.estimate.position);
            int area = GetAreaNumber(theBallModel,theRobotPose);
            ShowArea(area);
            ShowSomething(theBallModel.estimate.position.norm());
            ShowBallToRobot(theBallModel.estimate.position);

        }
    }

    state(alignBehindBall) {
        transition {
            if(libCodeRelease.timeSinceBallWasSeen() > 500)
                goto searchForBall;
            if(libCodeRelease.between(theBallModel.estimate.position.y(), 20.f, 50.f)
            && libCodeRelease.between(theBallModel.estimate.position.x(), 140.f, 170.f)
            && std::abs(libCodeRelease.angleToGoal) < 2_deg)
                goto kick;
            int area = GetAreaNumber(theBallModel,theRobotPose);
            if( area == 4)
                goto turnToBall;
            else if( area == 2)
                goto WalkToMiddlePoint;
            else if( area == 1)
                goto WalkToVerticalPoint;
        }
        action {
            theHeadControlMode = HeadControl::focusBall;
            WalkToTarget(Pose2f(80.f, 80.f, 80.f), Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() - 30.f));
            int area = GetAreaNumber(theBallModel,theRobotPose);
            ShowArea(area);
            ShowSomething(theBallModel.estimate.position.norm());

        }
    }

    state(kick) {
        transition {
            if(state_time > 3000 || (state_time > 10 && action_done))
                goto start;
            int area = GetAreaNumber(theBallModel,theRobotPose);    //防止球在被踢的中途出去，快速复位
            if( area == 4)
                goto turnToBall;
            else if( area == 2)
                goto WalkToMiddlePoint;
            else if( area == 1)
                goto WalkToVerticalPoint;
        }
        action {
            Annotation("Alive and Kickin'");
            theHeadControlMode = HeadControl::focusBall;
            //判断障碍物的距离
            InWalkKick(WalkRequest::left, Pose2f(libCodeRelease.angleToGoal, theBallModel.estimate.position.x() - 160.f, theBallModel.estimate.position.y() - 55.f));
            int area = GetAreaNumber(theBallModel,theRobotPose);
            ShowArea(area);
            ShowSomething(theBallModel.estimate.position.norm());

        }
    }

    state(searchForBall) {
        transition {
            int area = GetAreaNumber(theBallModel,theRobotPose);
            if(libCodeRelease.timeSinceBallWasSeen() < 300) {
                int area = GetAreaNumber(theBallModel,theRobotPose);
                if( area == 4)
                    goto turnToBall;
                else if( area == 2)
                    goto WalkToMiddlePoint;
                else if( area == 1)
                    goto WalkToVerticalPoint;
            }

            if(state_time>5000)
                goto start;

        }
        action {
            theHeadControlMode = HeadControl::searchForBall;
            //  WalkAtSpeedPercentage(Pose2f(1.f, 0.f, 0.f));
            int area = GetAreaNumber(theBallModel,theRobotPose);
            ShowArea(area);
            ShowSomething(theBallModel.estimate.position.norm());
        }
    }

}
