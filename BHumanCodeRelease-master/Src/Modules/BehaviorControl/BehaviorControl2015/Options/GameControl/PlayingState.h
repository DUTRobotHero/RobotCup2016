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
              OUTPUT_TEXT("libCodeRelease.returnFormPenalty" << libCodeRelease.returnFormPenalty);
              OUTPUT_TEXT("theOwnSideModel.returnFromGameControllerPenalty" << theOwnSideModel.returnFromGameControllerPenalty);
              OUTPUT_TEXT("theOwnSideModel.returnFromManualPenalty" << theOwnSideModel.returnFromManualPenalty);
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
				if (relatePoint.translation.norm() < 100.f)
					goto changeRoles;
		   }else{
			   Pose2f relatePoint=AbsolutePointToRobot(theRobotPose,theFieldDimensions.xPosOwnPenaltyMark,0);
				if (relatePoint.translation.norm() < 100.f)
					goto changeRoles;
		   }
           if(action_done)
               goto play;
      }
      action
      {
          ReadyState();
      }
  }
}
  

