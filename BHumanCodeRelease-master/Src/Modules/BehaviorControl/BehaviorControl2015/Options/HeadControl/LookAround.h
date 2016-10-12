 //环顾四周
 option(LookAround)
 {
    initial_state(LookAround)
    {
        transition{
            if(state_time>=1000)
                goto LookAroundLeft;
                
        }
      
    }
     state(LookAroundLeft)
     {
         transition
         {
              if(  (theRobotPose.rotation<0.5f && theRobotPose.rotation>=0 )  )
                      goto WalkAroundRight;
         }
          action
          {        SetHeadPanTilt(0.f,-0.f,150_deg);  
                  WalkAtSpeedPercentage(Pose2f(1.f, 0.f, 0.f));                        
        }
     }
      state(WalkAroundRight)
        {
            transition
            {
                if((theRobotPose.rotation>-0.5f && theRobotPose.rotation<=0))
                    goto LookAroundLeft;
            }
            action
            {
                     SetHeadPanTilt(0.f,-0.f,150_deg);
                     WalkAtSpeedPercentage(Pose2f(-1.f, 0.f, 0.f));
            }
        }               
     
 }