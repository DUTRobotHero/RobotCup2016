option(PlayingState)
{
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