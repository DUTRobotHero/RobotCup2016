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
          ;
      }
      action
      {
		  
          ChooseRoles();
      }
  }
}
  

