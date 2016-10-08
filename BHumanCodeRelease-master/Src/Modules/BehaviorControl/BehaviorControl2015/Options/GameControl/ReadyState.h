/** behavior for the ready state */
option(ReadyState)
{
    float distance;
    float setTime = 15000;
    float setDistance = 2000.0;
    float setVelocity =1.f/2;
    float setAdjustVelocity = 1.f/2;
    float deltaDistance = 20.0;
    int STRIKER_NUMBER = 2;
    int KEEPER_NUMBER = 1;
    int SUPPORTER_NUMBER = 3;


    float ATTACK_STRIKER_X1 = theRobotPose.translation.x();
    float ATTACK_STRIKER_Y1 = 0.0;
    float DEFEND_STRIKER_X1 = theRobotPose.translation.x();
    float DEFEND_STRIKER_Y1 = 0.0;
    float SUPPORTER_X1 = theRobotPose.translation.x();
    float SUPPORTER_Y1 = 900.0;
    float KEEPER_X1 = theRobotPose.translation.x();
    float KEEPER_Y1 = 0.0;

    float ATTACK_STRIKER_X2 = -250.0;
    float ATTACK_STRIKER_Y2 = 0.0;
    float DEFEND_STRIKER_X2 = -900.0;
    float DEFEND_STRIKER_Y2 = 0.0;
    float SUPPORTER_X2 = -250.0;
    float SUPPORTER_Y2 = 900.0;
    float KEEPER_X2 = -4000.0;
    float KEEPER_Y2 = 0.0;

    initial_state(stand) {
        transition {
            if(state_time > 15000) {
                if (theGameInfo.kickOffTeam == theOwnTeamInfo.teamNumber)
                    goto attacking;
                else
                    goto defending;
            }
        }
        action {
            theHeadControlMode = HeadControl::leftAndRight;
            ShowRobotToField(theRobotPose);
            WalkToTarget(Pose2f(0.f,setVelocity,0.f),Pose2f(0.0,setDistance,0.0));
        }

    }

    state(attacking) {
        transition {
            if ( theRobotInfo.number == SUPPORTER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X1,SUPPORTER_Y1);
                distance = relatePoint.translation.norm();

                if ( distance < deltaDistance )
                    goto alignToGoal;
            } else if ( theRobotInfo.number == KEEPER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X1,KEEPER_Y1);
                distance = relatePoint.translation.norm();

                if ( distance < deltaDistance )
                    goto alignToGoal;
            }

            else if (theRobotInfo.number == STRIKER_NUMBER ) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,ATTACK_STRIKER_X1,ATTACK_STRIKER_Y1);
                distance = relatePoint.translation.norm();
                if ( distance < deltaDistance )
                    goto alignToGoal;
            }

            action {
                theHeadControlMode = HeadControl::leftAndRight;
                if ( theRobotInfo.number == SUPPORTER_NUMBER) {        //Hawkeye
                    Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X1,SUPPORTER_Y1);
                    distance = relatePoint.translation.norm();
                    WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                    Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));

                    ShowReadyPosition(relatePoint);
                }

                else if ( theRobotInfo.number == KEEPER_NUMBER) { //Flash
                    Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X1,KEEPER_Y1);
                    distance = relatePoint.translation.norm();
                    WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                    Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));

                    ShowReadyPosition(relatePoint);
                }

                else if ( theRobotInfo.number == STRIKER_NUMBER) { //Thor
                    Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,ATTACK_STRIKER_X1,ATTACK_STRIKER_Y1);
                    distance = relatePoint.translation.norm();

                    WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                    Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
                    ShowSomething(distance);
                    ShowReadyPosition(relatePoint);
                }
                ShowRobotToField(theRobotPose);
                ShowSomething(libCodeRelease.angleToGoal );
            }
        }
    }

    state(defending) {
        transition {
            if ( theRobotInfo.number == SUPPORTER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X1,SUPPORTER_Y1);
                distance = relatePoint.translation.norm();

                if ( distance < deltaDistance )
                    goto alignToGoal;
            } else if ( theRobotInfo.number == KEEPER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X1,KEEPER_Y1);
                distance = relatePoint.translation.norm();

                if ( distance < deltaDistance )
                    goto alignToGoal;
            }

            else if (theRobotInfo.number == STRIKER_NUMBER ) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFEND_STRIKER_X1,DEFEND_STRIKER_Y1);
                distance = relatePoint.translation.norm();
                if ( distance < deltaDistance )
                    goto alignToGoal;
            }

            action {
                theHeadControlMode = HeadControl::leftAndRight;
                if ( theRobotInfo.number == SUPPORTER_NUMBER) {        //Hawkeye
                    Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X1,SUPPORTER_Y1);
                    WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                    Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
                    distance = relatePoint.translation.norm();
                    ShowReadyPosition(relatePoint);
                }

                else if ( theRobotInfo.number == KEEPER_NUMBER) { //Flash
                    Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X1,KEEPER_Y1);
                    WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                    Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
                    distance = relatePoint.translation.norm();
                    ShowReadyPosition(relatePoint);
                }

                else if ( theRobotInfo.number == STRIKER_NUMBER) { //Thor
                    Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFEND_STRIKER_X1,DEFEND_STRIKER_Y1);
                    WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                    Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
                    distance = relatePoint.translation.norm();
                    ShowSomething(distance);
                    ShowReadyPosition(relatePoint);
                }
                ShowRobotToField(theRobotPose);
            }
        }
    }

//TODO FIXIT  (反解出绝对坐标系坐标点相对于机器人的坐标）
    state(AdjustPositionStriker) { //默认自定位已完成
        transition {
            if ( theRobotInfo.number == SUPPORTER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X2,SUPPORTER_Y2);
                distance = relatePoint.translation.norm();

                if ( distance < deltaDistance )
                    goto AlignToGoal;
            } else if ( theRobotInfo.number == KEEPER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X2,KEEPER_Y2);
                distance = relatePoint.translation.norm();

                if ( distance < deltaDistance )
                    goto AlignToGoal;
            } else if (theRobotInfo.number == STRIKER_NUMBER ) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,ATTACK_STRIKER_X2,ATTACK_STRIKER_Y2);
                distance = relatePoint.translation.norm();
                if ( distance < deltaDistance )
                    goto AlignToGoal;
            }

        }

        action {
            Annotation("I am adjusting position");
            theHeadControlMode = HeadControl::lookForward;
            if ( theRobotInfo.number == SUPPORTER_NUMBER) {        //Hawkeye
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X2,SUPPORTER_Y2);
                WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
                distance = relatePoint.translation.norm();
                ShowReadyPosition(relatePoint);
                ShowSomething(distance);
            }

            else if ( theRobotInfo.number == KEEPER_NUMBER) {       //Flash
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X2,KEEPER_Y2);
                WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
                distance = relatePoint.translation.norm();
                ShowReadyPosition(relatePoint);
                ShowSomething(distance);

            }

            else if ( theRobotInfo.number == STRIKER_NUMBER) {      //Thor
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,ATTACK_STRIKER_X2,ATTACK_STRIKER_Y2);
                WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
                distance = relatePoint.translation.norm();
                ShowSomething(distance);
                ShowReadyPosition(relatePoint);
                ShowSomething(distance);

            }
            ShowRobotToField(theRobotPose);
            ShowSomething(libCodeRelease.angleToGoal );

        }
    }


    state(AdjustPositionDefender) { //默认自定位已完成
        transition {
            if ( theRobotInfo.number == SUPPORTER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X2,SUPPORTER_Y2);
                distance = relatePoint.translation.norm();

                if ( distance < deltaDistance )
                    goto AlignToGoal;
            } else if ( theRobotInfo.number == KEEPER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X2,KEEPER_Y2);
                distance = relatePoint.translation.norm();

                if ( distance < deltaDistance )
                    goto AlignToGoal;
            } else if (theRobotInfo.number == STRIKER_NUMBER ) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFEND_STRIKER_X2,DEFEND_STRIKER_Y2);
                distance = relatePoint.translation.norm();
                if ( distance < deltaDistance )
                    goto AlignToGoal;
            }
        }
        action {
            Annotation("I am adjusting position");
            theHeadControlMode = HeadControl::lookForward;

            if ( theRobotInfo.number == SUPPORTER_NUMBER) {        //Hawkeye
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X2,SUPPORTER_Y2);
                WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
                distance = relatePoint.translation.norm();
                ShowReadyPosition(relatePoint);
            }

            else if ( theRobotInfo.number == KEEPER_NUMBER) { //Flash
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X2,KEEPER_Y2);
                WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
                distance = relatePoint.translation.norm();
                ShowReadyPosition(relatePoint);
            } else if ( theRobotInfo.number == STRIKER_NUMBER) { //Thor
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFEND_STRIKER_X2,DEFEND_STRIKER_Y2);
                WalkToTarget(Pose2f( pi/64,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));
                distance = relatePoint.translation.norm();
                ShowSomething(distance);
                ShowReadyPosition(relatePoint);
            }
            ShowRobotToField(theRobotPose);
        }
    }

    state(alignToGoal) {
        transition {
            if( std::abs( libCodeRelease.angleToGoal ) < 2_deg  && (theRobotInfo.number == STRIKER_NUMBER || theRobotInfo.number == KEEPER_NUMBER)) {
                if( theGameInfo.kickOffTeam == theOwnTeamInfo.teamNumber )
                    goto AdjustPositionStriker;
                else
                    goto AdjustPositionDefender;
            } else if(std::abs( libCodeRelease.angleToGoal ) < 10_deg && theRobotInfo.number == SUPPORTER_NUMBER) {
                if( theGameInfo.kickOffTeam == theOwnTeamInfo.teamNumber )
                    goto AdjustPositionStriker;
                else
                    goto AdjustPositionDefender;
            }
        }
        action {
            WalkToTarget(Pose2f(10.f,0.f,0.f),Pose2f(-theRobotPose.rotation,0.0,0.0));
            ShowSomething( std::abs( libCodeRelease.angleToGoal ));
        }
    }
    state(AlignToGoal) {
        action {
            WalkToTarget(Pose2f(10.f,0.f,0.f),Pose2f(-theRobotPose.rotation,0.0,0.0));
        }
    }
}
