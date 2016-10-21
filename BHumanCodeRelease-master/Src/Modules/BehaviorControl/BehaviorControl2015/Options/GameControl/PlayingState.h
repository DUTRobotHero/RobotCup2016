option(PlayingState)
{


    int KEEPER_NUMBER = 1;
    int STRIKER_NUMBER = 2;
    int SUPPORTER_NUMBER = 3;
	int DEFENDER_NUMBER1 = 4;
    int DEFENDER_NUMBER2 = 5;
	initial_state(upstand)
  {
    transition
    {
      if(theFallDownState.state == FallDownState::upright && action_done)
        goto play;
		if (theRobotInfo.number == 6)
			goto	test;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      Stand();
    }
  }
state(test)
{
	transition{
		}
	action{
		TestPlayer();
		}
	}
  state(play)
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
          ChooseRoles();
		  ShowSomething(theTeammateData.numberOfActiveTeammates);
      }
  }
  state(backToField)
  {
      transition
      {
           if(action_done)
               goto play;
      }
      action
      {
          ReadyState();
      }
  }
}