option(PlayingState)
{
  initial_state(play)
  {
    transition
    {
        if ( theRobotInfo.number == 1)
          goto Keeper;
      else if( theRobotInfo.number == 2)
          goto Striker;
          
    }
    action
    {
      /*Keeper();*/
      ;
    }
  }
  
  state(Keeper)
  {
      transition
      {
          ;
      }
      action
      {
          Keeper();
      }
  }


  state(Striker)
  {
      transition
      {
          ;
      }
      action
      {
          Striker();
      }
  }
}