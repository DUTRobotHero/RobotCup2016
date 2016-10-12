/** a  defener  defends  the own  goal  without  entering  the penalty area*/
 option(Defender)
 {
	    float  X=0;
	   float Y= 0;
	   double  distance=0;
      Vector2f  center=Vector2f(0.f,0.f);
    initial_state(start)
         {
				 transition
 				  {
					  if(state_time > 1000)
						goto AtThePosition; //后卫就位；
					       
                        
				   }
				action
				{
				  theHeadControlMode = HeadControl::lookForward;
				  Stand();
		     	}
           }
   state(AtThePosition)
		{
			transition
					{
						if(state_time>20000)
						{
							goto act;
						}
					}
           action
					{
                        LookAround();
                          SetHeadPanTilt(0.f,0.f,150_deg);
                         Vector2f  RobotPosition=Vector2f(-2500.f,0.f);
                         WalkToPosition(Pose2f(50.f,50.f,50.f),RobotPosition);
		        	}
		  }
	 state(act)
		{
             double fieldX=0; 
			transition
			{
						if(theObstacleModel.obstacles.empty()==true)
						{
							 goto  AtThePosition;
			            }
						else
						{
							  int  VectorSize=0;
						      VectorSize=theObstacleModel.obstacles.size();
								for(int i=0;i<VectorSize;i++)
								{
										if(theObstacleModel.obstacles[i].type==Obstacle::opponent)
											{
												X=theObstacleModel.obstacles[i].center.x();
                                               Y= theObstacleModel.obstacles[i].center.y();
                                              center=Vector2f(X,Y);
											}
										else 
					                     continue;
                                    fieldX=cos(theRobotPose.rotation)*X-sin(theRobotPose.rotation)*Y+theRobotPose.translation.x();
							       } 
								distance = std::sqrt(X*X+Y*Y);
								if(distance<=2500 && fieldX<=0) //如果defender和Opponent之间得距离小于2000mm且Opponent已经过中线；
								  goto  defendOpponent;
								
                        }
             }
        action
                {
	                 SetHeadPanTilt(0.f,0.f,150_deg);
                     LookAround();
		            Position("Opponent  Position",center);
                    Value("Robot and Defender's Distance",distance);
		        } 
		}
    state(defendOpponent)
			 {
				 transition
				 {
                     if(theObstacleModel.obstacles.empty()==true)
						{
							goto  lookAround;
		                }
						else
						{
							  int  VectorSize=0;
						      VectorSize=theObstacleModel.obstacles.size();
								for(int i=0;i<VectorSize;i++)
								{
										if(theObstacleModel.obstacles[i].type==Obstacle::opponent)
											{
												X=theObstacleModel.obstacles[i].center.x()-300.f;
                                               Y= theObstacleModel.obstacles[i].center.y();
                                              center=Vector2f(X,Y);
											}
										else 
                                            continue;
							       } 
					 
			        }
                 }
                action
					{
						  SetHeadPanTilt(0.f,-0.2f,150_deg);
                          WalkToTarget(Pose2f(50.f,50.f,50.f),Pose2f(0.f, X,Y));
					      Position("Opponent  Position",center);
                          Value("Robot and Defender's Distance",distance);
					  }
            }
                  
    state(lookAround)
                 {
                     transition
                     {
                         if(theObstacleModel.obstacles.empty()==true && state_time>=20000)
                             {
                                goto AtThePosition ; 
                             }
                       else
                          { 
                                  int  VectorSize=0;
                                  VectorSize=theObstacleModel.obstacles.size();
								  for(int i=0;i<VectorSize;i++)
								    {
										if(theObstacleModel.obstacles[i].type==Obstacle::someRobot  || theObstacleModel.obstacles[i].type==Obstacle::opponent)
											 {
												   goto defendOpponent;
										   	 }
										else 
                                            continue;
                                    }
                             
                          }
                       }
                     
	                  action
                           {
                                Position("Opponent Position",center);
                                 Value("Robot Own rotation",theRobotPose.rotation);
                                 LookAround();
                             
                           }
                 }
                     
  
      
  }
  
  

                 