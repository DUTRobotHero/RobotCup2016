option(PlayingState)
{
       initial_state(start)
       {
           action
           {
                    theHeadControlMode = HeadControl::lookForward;
                    Stand();
           }
       }
}
