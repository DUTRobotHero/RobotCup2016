/** behavior for the ready state */
option(ReadyState)
{
    float distance;
    float setDistance = 2000.0;
    float setVelocity = 20.f;
    float setAdjustVelocity = 20.f;
    int STRIKER_NUMBER = 2;
    int KEEPER_NUMBER = 1;
    int SUPPORTER_NUMBER = 4;
    float ATTACK_STRIKER_X = -250.0;
    float ATTACK_STRIKER_Y = 0.0;
    float DEFEND_STRIKER_X = -900.0;
    float DEFEND_STRIKER_Y = 0.0;
    float SUPPORTER_X = -250.0;
    float SUPPORTER_Y = 900.0;
    float KEEPER_X = -4000.0;
    float KEEPER_Y = 0.0;
    initial_state(stand) {
        transition {
            if (theGameInfo.kickOffTeam == theOwnTeamInfo.teamNumber)
                goto attacking;
            else
                goto defending;
        }

        action {
            theHeadControlMode = HeadControl::leftAndRight;
            ShowRobotToField(theRobotPose);
            //     theHeadControlMode = HeadControl::lookForward;
            //Stand();
        }
    }


    state(attacking) {
        transition {
            if (state_time > 10000)
                goto AdjustPositionStriker;
        }
        //striker站在圆里面(-100,0)  supporter(-100, 800)
        //defender (-2800,0)   keeper(-3800,0)
        action {
            Annotation("I am attacking");
            theHeadControlMode = HeadControl::leftAndRight;
            if ( theRobotInfo.number == SUPPORTER_NUMBER) {       //Hawkeye
                WalkToTarget(Pose2f(0.f,setVelocity,0.f),Pose2f(0.0,setDistance,0.0));
                ShowRobotToField(theRobotPose);
            } else if ( theRobotInfo.number == KEEPER_NUMBER) {    //Flash
                WalkToTarget(Pose2f(0.f,setVelocity,0.f),Pose2f(0.0,setDistance,0.0));
                ShowRobotToField(theRobotPose);
            }

            else if ( theRobotInfo.number == STRIKER_NUMBER) { //Thor
                WalkToTarget(Pose2f(0.f,setVelocity,0.f),Pose2f(0.0,setDistance,0.0));
                ShowRobotToField(theRobotPose);
            }
        }
    }

    state(defending) {
        //striker站在圆外面(-800,0)  supporter(-800, 800)
        //defender (-2800,0)   keeper(-3800,0)
        transition {
            if (state_time > 10000)
                goto AdjustPositionDefender;
        }
        action {
            Annotation("I am defending");
            theHeadControlMode = HeadControl::leftAndRight;

            if ( theRobotInfo.number == SUPPORTER_NUMBER) {       //Hawkeye
                WalkToTarget(Pose2f(0.f,setVelocity,0.f),Pose2f(0.0,setDistance,0.0));
                ShowRobotToField(theRobotPose);
            } else if ( theRobotInfo.number == KEEPER_NUMBER) { //Flash
                WalkToTarget(Pose2f(0.f,setVelocity,0.f),Pose2f(0.0,setDistance,0.0));
                ShowRobotToField(theRobotPose);
            }
            else if ( theRobotInfo.number == STRIKER_NUMBER) { //Thor
                WalkToTarget(Pose2f(0.f,setVelocity,0.f),Pose2f(0.0,setDistance,0.0));
                ShowRobotToField(theRobotPose);
            }
        }
    }

//TODO FIXIT  (反解出绝对坐标系坐标点相对于机器人的坐标）
    state(AdjustPositionStriker) { //默认自定位已完成
        transition {
            if ( theRobotInfo.number == SUPPORTER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X,SUPPORTER_Y);
                distance = relatePoint.translation.norm();

                if ( distance < 10.0 )
                    goto AlignToGoal;
            } else if ( theRobotInfo.number == KEEPER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X,KEEPER_Y);
                distance = relatePoint.translation.norm();

                if ( distance < 10.0 )
                    goto AlignToGoal;
            }

            else if (theRobotInfo.number == STRIKER_NUMBER ) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,ATTACK_STRIKER_X,ATTACK_STRIKER_Y);
                distance = relatePoint.translation.norm();
                if ( distance < 10.0 )
                    goto AlignToGoal;
            }
        }
    
    action {
        Annotation("I am adjusting position");

        if ( theRobotInfo.number == SUPPORTER_NUMBER) {        //Hawkeye
            Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X,SUPPORTER_Y);
            WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
            Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
            //    distance = (theRobotPose.translation.x() +100.0) * (theRobotPose.translation.x() +100.0)  + (theRobotPose.translation.y() - 800.0) * (theRobotPose.translation.y() - 800.0);
            distance = relatePoint.translation.norm();
            ShowReadyPosition(relatePoint);
        }

        else if ( theRobotInfo.number == KEEPER_NUMBER)  //Flash
            //     WalkToTargetAbsolute(Pose2f(0.f,50.f,0.f),Pose2f(0.0,-3800.0,0.0));
        {
            Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X,KEEPER_Y);
            WalkToTarget(Pose2f( pi/64,20.f,20.f),
            Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
            // distance = (theRobotPose.translation.x() +3800.0) * (theRobotPose.translation.x() +3800.0)  + (theRobotPose.translation.y() ) * (theRobotPose.translation.y());
            distance = relatePoint.translation.norm();
            ShowReadyPosition(relatePoint);
        }


        else if ( theRobotInfo.number == STRIKER_NUMBER) { //Thor
            Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,ATTACK_STRIKER_X,ATTACK_STRIKER_Y);
            WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
            Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
            //distance = (theRobotPose.translation.x() +100.0) * (theRobotPose.translation.x() +100.0)  + (theRobotPose.translation.y() ) * (theRobotPose.translation.y() );
            distance = relatePoint.translation.norm();
            ShowSomething(distance);
            ShowReadyPosition(relatePoint);
        }
        ShowRobotToField(theRobotPose);
    }
    }
    state(AdjustPositionDefender) { //默认自定位已完成
        transition {
            if ( theRobotInfo.number == SUPPORTER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X,SUPPORTER_Y);
                distance = relatePoint.translation.norm();

                if ( distance < 10.0 )
                    goto AlignToGoal;
            } else if ( theRobotInfo.number == KEEPER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X,KEEPER_Y);
                distance = relatePoint.translation.norm();

                if ( distance < 10.0 )
                    goto AlignToGoal;
            } else if (theRobotInfo.number == STRIKER_NUMBER ) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFEND_STRIKER_X,DEFEND_STRIKER_Y);
                distance = relatePoint.translation.norm();
                if ( distance < 10.0 )
                    goto AlignToGoal;
            }
        }
        action {
            Annotation("I am adjusting position");

            if ( theRobotInfo.number == SUPPORTER_NUMBER) {        //Hawkeye
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X,SUPPORTER_Y);
                WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
                //    distance = (theRobotPose.translation.x() +100.0) * (theRobotPose.translation.x() +100.0)  + (theRobotPose.translation.y() - 800.0) * (theRobotPose.translation.y() - 800.0);
                distance = relatePoint.translation.norm();
                ShowReadyPosition(relatePoint);
            }

            else if ( theRobotInfo.number == KEEPER_NUMBER)  //Flash
                //     WalkToTargetAbsolute(Pose2f(0.f,50.f,0.f),Pose2f(0.0,-3800.0,0.0));
            {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X,KEEPER_Y);
                WalkToTarget(Pose2f( pi/64,20.f,20.f),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
                // distance = (theRobotPose.translation.x() +3800.0) * (theRobotPose.translation.x() +3800.0)  + (theRobotPose.translation.y() ) * (theRobotPose.translation.y());
                distance = relatePoint.translation.norm();
                ShowReadyPosition(relatePoint);
            }
            else if ( theRobotInfo.number == STRIKER_NUMBER) { //Thor
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFEND_STRIKER_X,DEFEND_STRIKER_Y);
                WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
                //distance = (theRobotPose.translation.x() +100.0) * (theRobotPose.translation.x() +100.0)  + (theRobotPose.translation.y() ) * (theRobotPose.translation.y() );
                distance = relatePoint.translation.norm();
                ShowSomething(distance);
                ShowReadyPosition(relatePoint);
            }
            ShowRobotToField(theRobotPose);
        }
    }


    state(AlignToGoal) {
        action {
            WalkToTarget(Pose2f(20.f,0.f,0.f),Pose2f(-theRobotPose.rotation,0.0,0.0));
        }
    }
}
