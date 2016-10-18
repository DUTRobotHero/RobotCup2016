/** behavior for the ready state */
option(ReadyState)
{
    float setAdjustVelocity = 1.f/2;
    float setTurnVelocity = pi/8;
    float deltaDistance = 10.0;
    float distance;

    int KEEPER_NUMBER = 1;
    int STRIKER_NUMBER = 2;
    int SUPPORTER_NUMBER = 3;
    int DEFENDER_NUMBER1 = 4;
    int DEFENDER_NUMBER2= 5;

    float ATTACK_STRIKER_X = -250.0;
    float ATTACK_STRIKER_Y = 0.0;
    float DEFEND_STRIKER_X = -900.0;
    float DEFEND_STRIKER_Y = 0.0;

    float SUPPORTER_X = -250.0;
    float SUPPORTER_Y = -1100.0;
    float DEFEND_SUPPORTER_X = -900.0;
    float DEFEND_SUPPORTER_Y = -1100.0;
    float KEEPER_X = -4000.0;
    float KEEPER_Y = 0.0;
    float DEFENDER_X1 = -3000.0;
    float DEFENDER_Y1 = 1000.0;
    float DEFENDER_X2 = -3000.0;
    float DEFENDER_Y2 = -1000.0;

    initial_state(TurnToPosition) {
        transition {
            if( theRobotInfo.number == SUPPORTER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X,SUPPORTER_Y);
                if(std::abs(relatePoint.rotation) < 2_deg) {
                    if (theGameInfo.kickOffTeam == theOwnTeamInfo.teamNumber)
                        goto WalkToPosition_Attack;
                    else
                        goto WalkToPosition_Defend;
                }
            }
            if( theRobotInfo.number == STRIKER_NUMBER) {
                if (theGameInfo.kickOffTeam == theOwnTeamInfo.teamNumber) {
                    Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,ATTACK_STRIKER_X,ATTACK_STRIKER_Y);
                    if(std::abs(relatePoint.rotation) < 2_deg) {
                        goto WalkToPosition_Attack;
                    }
                } else {
                    Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFEND_STRIKER_X,DEFEND_STRIKER_Y);
                    if(std::abs(relatePoint.rotation) < 2_deg)
                        goto WalkToPosition_Defend;
                }
            }
            if( theRobotInfo.number == KEEPER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X,KEEPER_Y);
                if(std::abs(relatePoint.rotation) < 2_deg) {
                    if (theGameInfo.kickOffTeam == theOwnTeamInfo.teamNumber)
                        goto WalkToPosition_Attack;
                    else
                        goto WalkToPosition_Defend;
                }
            }
            if( theRobotInfo.number == DEFENDER_NUMBER1) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFENDER_X1,DEFENDER_Y1);
                if(std::abs(relatePoint.rotation) < 2_deg) {
                    if (theGameInfo.kickOffTeam == theOwnTeamInfo.teamNumber)
                        goto WalkToPosition_Attack;
                    else
                        goto WalkToPosition_Defend;
                }
            }
                        if( theRobotInfo.number == DEFENDER_NUMBER2) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFENDER_X2,DEFENDER_Y2);
                if(std::abs(relatePoint.rotation) < 2_deg) {
                    if (theGameInfo.kickOffTeam == theOwnTeamInfo.teamNumber)
                        goto WalkToPosition_Attack;
                    else
                        goto WalkToPosition_Defend;
                }
            }
        }
        action {
            if ( theRobotInfo.number == SUPPORTER_NUMBER) {        //Hawkeye
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X,SUPPORTER_Y);
                WalkToTarget(Pose2f(setTurnVelocity,0.0,0.0),Pose2f(relatePoint.rotation,0.0,0.0));
                ShowReadyPosition(relatePoint);
            }

            else if ( theRobotInfo.number == KEEPER_NUMBER) { //Flash
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X,KEEPER_Y);
                WalkToTarget(Pose2f(setTurnVelocity,0.0,0.0),Pose2f(relatePoint.rotation,0.0,0.0));
                ShowReadyPosition(relatePoint);
            }

            else if ( theRobotInfo.number == STRIKER_NUMBER) { //Thor
                if(theGameInfo.kickOffTeam == theOwnTeamInfo.teamNumber) {
                    Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,ATTACK_STRIKER_X,ATTACK_STRIKER_Y);
                    WalkToTarget(Pose2f(setTurnVelocity,0.0,0.0),Pose2f(relatePoint.rotation,0.0,0.0));
                    ShowReadyPosition(relatePoint);

                } else {
                    Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFEND_STRIKER_X,DEFEND_STRIKER_Y);
                    WalkToTarget(Pose2f(setTurnVelocity,0.0,0.0),Pose2f(relatePoint.rotation,0.0,0.0));
                    ShowReadyPosition(relatePoint);
                }
            } else if ( theRobotInfo.number == DEFENDER_NUMBER1) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFENDER_X1,DEFENDER_Y1);
                WalkToTarget(Pose2f(setTurnVelocity,0.0,0.0),Pose2f(relatePoint.rotation,0.0,0.0));
                ShowReadyPosition(relatePoint);
            }
            else if ( theRobotInfo.number == DEFENDER_NUMBER2) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFENDER_X2,DEFENDER_Y2);
                WalkToTarget(Pose2f(setTurnVelocity,0.0,0.0),Pose2f(relatePoint.rotation,0.0,0.0));
                ShowReadyPosition(relatePoint);
            }
        }
    }

    state(WalkToPosition_Attack) {
        transition {
            if ( theRobotInfo.number == SUPPORTER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X,SUPPORTER_Y);
                distance = relatePoint.translation.norm();

                if ( distance < deltaDistance )
                    goto AlignToGoal;
            } else if ( theRobotInfo.number == KEEPER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X,KEEPER_Y);
                distance = relatePoint.translation.norm();

                if ( distance < deltaDistance )
                    goto AlignToGoal;
            }

            else if (theRobotInfo.number == STRIKER_NUMBER ) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,ATTACK_STRIKER_X,ATTACK_STRIKER_Y);
                distance = relatePoint.translation.norm();
                if ( distance < deltaDistance )
                    goto AlignToGoal;
            } else if (theRobotInfo.number == DEFENDER_NUMBER1 ) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFENDER_X1,DEFENDER_Y1);
                distance = relatePoint.translation.norm();
                if ( distance < deltaDistance )
                    goto AlignToGoal;
            }
            else if (theRobotInfo.number == DEFENDER_NUMBER2 ) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFENDER_X2,DEFENDER_Y2);
                distance = relatePoint.translation.norm();
                if ( distance < deltaDistance )
                    goto AlignToGoal;
            }
        }
        action {

            if ( theRobotInfo.number == SUPPORTER_NUMBER) {        //Hawkeye
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,SUPPORTER_X,SUPPORTER_Y);

                WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));

                ShowReadyPosition(relatePoint);
            }

            else if ( theRobotInfo.number == KEEPER_NUMBER) { //Flash
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X,KEEPER_Y);

                WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));

                ShowReadyPosition(relatePoint);
            }

            else if ( theRobotInfo.number == STRIKER_NUMBER) { //Thor

                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,ATTACK_STRIKER_X,ATTACK_STRIKER_Y);

                WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));

                ShowReadyPosition(relatePoint);
            } else if ( theRobotInfo.number == DEFENDER_NUMBER1) { //Flash
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFENDER_X1,DEFENDER_Y1);

                WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));

                ShowReadyPosition(relatePoint);
            }
            else if ( theRobotInfo.number == DEFENDER_NUMBER2) { //Flash
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFENDER_X2,DEFENDER_Y2);

                WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));

                ShowReadyPosition(relatePoint);
            }

            ShowRobotToField(theRobotPose);

        }

    }

    state(WalkToPosition_Defend) {
        transition {
            if ( theRobotInfo.number == SUPPORTER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFEND_SUPPORTER_X,DEFEND_SUPPORTER_Y);
                distance = relatePoint.translation.norm();

                if ( distance < deltaDistance )
                    goto AlignToGoal;
            } else if ( theRobotInfo.number == KEEPER_NUMBER) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X,KEEPER_Y);
                distance = relatePoint.translation.norm();

                if ( distance < deltaDistance )
                    goto AlignToGoal;
            }

            else if (theRobotInfo.number == STRIKER_NUMBER ) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFEND_STRIKER_X,DEFEND_STRIKER_Y);
                distance = relatePoint.translation.norm();
                if ( distance < deltaDistance )
                    goto AlignToGoal;
            } else if (theRobotInfo.number == DEFENDER_NUMBER1 ) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFENDER_X1,DEFENDER_Y1);
                distance = relatePoint.translation.norm();
                if ( distance < deltaDistance )
                    goto AlignToGoal;
            }
             else if (theRobotInfo.number == DEFENDER_NUMBER2 ) {
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFENDER_X2,DEFENDER_Y2);
                distance = relatePoint.translation.norm();
                if ( distance < deltaDistance )
                    goto AlignToGoal;
            }
        }
        action {
            if ( theRobotInfo.number == SUPPORTER_NUMBER) {        //Hawkeye
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFEND_SUPPORTER_X,DEFEND_SUPPORTER_Y);

                WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));

                ShowReadyPosition(relatePoint);
            }

            else if ( theRobotInfo.number == KEEPER_NUMBER) { //Flash
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,KEEPER_X,KEEPER_Y);

                WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));

                ShowReadyPosition(relatePoint);
            }

            else if ( theRobotInfo.number == STRIKER_NUMBER) { //Thor
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFEND_STRIKER_X,DEFEND_STRIKER_Y);
                WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));

                ShowReadyPosition(relatePoint);
            } else if ( theRobotInfo.number == DEFENDER_NUMBER1) { //Flash
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFENDER_X1,DEFENDER_Y1);
                WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));

                ShowReadyPosition(relatePoint);
            }
            else if ( theRobotInfo.number == DEFENDER_NUMBER2) { //Flash
                Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,DEFENDER_X2,DEFENDER_Y2);
                WalkToTarget(Pose2f( setTurnVelocity,setAdjustVelocity,setAdjustVelocity),
                Pose2f(relatePoint.rotation,relatePoint.translation.x(),relatePoint.translation.y()));

                ShowReadyPosition(relatePoint);
            }
        }
    }


    state(AlignToGoal) {
        transition {
            if(action_done)
                goto finished;
        }
        action {
            WalkToTarget(Pose2f(10.f,0.f,0.f),Pose2f(-theRobotPose.rotation,0.0,0.0));
        }
    }

    target_state(finished) {
        action {
            ;
        }
    }
}
