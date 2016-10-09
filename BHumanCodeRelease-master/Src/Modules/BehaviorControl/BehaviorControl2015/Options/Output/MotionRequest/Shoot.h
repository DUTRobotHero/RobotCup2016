/**
 *Shoot the Ball with the specified \c kickMotionType.
 * @param kickMotionType The kickMotionType to be executed
 */
option(Shoot, ((KickRequest) KickMotionID) kickMotionType)
{
  /** Set the motion request / kickMotionType. */
  initial_state(launch)
  {
    transition
    {
      if(theMotionInfo.motion == MotionRequest::kick && theMotionInfo.kickRequest.kickMotionType == kickMotionType)
        goto execute;
    }
    action
    {
      theMotionRequest.motion =  MotionRequest::kick;
	  theMotionRequest.kickRequest.dynamical = true;
      theMotionRequest.kickRequest.kickMotionType =kickMotionType;
	  
    }
  }

  /** Executes the kick */
  state(execute)
  {
    transition
    {
      if(theMotionInfo.kickRequest.kickMotionType == KickRequest::none)
        goto finished;
    }
    action
    {
      theMotionRequest.motion =  MotionRequest::kick;
	  theMotionRequest.kickRequest.dynamical = true;
      theMotionRequest.kickRequest.kickMotionType = KickRequest::none;
    }
  }

  /** The kick has been executed */
  target_state(finished)
  {
    action
    {
	  theMotionRequest.motion =  MotionRequest::kick;
	  theMotionRequest.kickRequest.dynamical = true;
      theMotionRequest.kickRequest.kickMotionType = KickRequest::none;
    }
  }
}
