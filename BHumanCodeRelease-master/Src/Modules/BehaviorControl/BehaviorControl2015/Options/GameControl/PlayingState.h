option(PlayingState)
{

//    int STRIKER_NUMBER = 2;
    int KEEPER_NUMBER = 1;
 //   int SUPPORTER_NUMBER = 3;
	
	initial_state(upstand)
  {
    transition
    {
      if(theFallDownState.state == FallDownState::upright && action_done)
        goto play;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      Stand();
    }
  }
  state(play)
  {
    transition
    {
        if (state_time>5000){
			goto changeRoles;
		}
    }
    action
    {
      theHeadControlMode = HeadControl::leftAndRight;
    }
  }

  state(changeRoles)
  {
      transition
      {
          if (libCodeRelease.returnFormPenalty == true ){
			  libCodeRelease.returnFormPenalty=false;
			  goto backToField;
			  }
      }
      action
      {
          ShowBool(theOwnSideModel.returnFromGameControllerPenalty);
          ShowBool(theOwnSideModel.returnFromManualPenalty);
          ChooseRoles();
      }
  }
  state(backToField)
  {
      transition
      {
		  if ( theRobotInfo.number == KEEPER_NUMBER ){
				Pose2f relatePoint=AbsolutePointToRobot(theRobotPose,theFieldDimensions.xPosOwnPenaltyMark,0);
				if (relatePoint.translation.norm() < 500.f)
					goto changeRoles;
		   }else{
			   Pose2f relatePoint=AbsolutePointToRobot(theRobotPose,theFieldDimensions.xPosOwnPenaltyMark+1000.f,0);
				if (relatePoint.translation.norm() < 500.f)
					goto changeRoles;
		   }
      }
      action
      {
		  if ( theRobotInfo.number == KEEPER_NUMBER ){
				Pose2f relatePoint = AbsolutePointToRobot(theRobotPose,theFieldDimensions.xPosOwnPenaltyMark,0);
				WalkToTarget(Pose2f(10.f,10.f,10.f),relatePoint);
		   }
		   else {
				Pose2f relatePoint=AbsolutePointToRobot(theRobotPose,theFieldDimensions.xPosOwnPenaltyMark+1000.f,0);
			   WalkToTarget(Pose2f(10.f,10.f,10.f),relatePoint);
			}
      }
  }
}
  

