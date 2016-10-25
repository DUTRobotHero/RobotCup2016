option(ChooseRoles)
{
	#define KEEPER_NUM 1
	#define STRIKER_NUM  2
	#define SUPPORTER_NUM  3
	#define DEFENDER_FORWARD  4
    #define DEFENDER_BACKWARD  5
  /** Stand still and wait. */
  initial_state(initial)
  {
	  transition{
		  if ( theRobotInfo.number == KEEPER_NUM )
			goto Keeper;
		else if  ( theRobotInfo.number == DEFENDER_FORWARD)
			goto DefenderForward;
        else if ( theRobotInfo.number == DEFENDER_BACKWARD)
            goto DefenderBackward;
		else if (theRobotInfo.number == STRIKER_NUM)
			goto Striker;
		else if (theRobotInfo.number == SUPPORTER_NUM)
			goto Supporter;
	}
    action
    {
     theHeadControlMode = HeadControl::none;
      SetHeadPanTilt(0.f, 0.f, 150_deg);
    }
  }
  state(Keeper)
  {
	  action
	  {
		  Keeper();
          theBehaviorStatus.role = Role::keeper;
		}
	}
	state(DefenderForward)
  {
	  transition{
		  if ( theTeammateData.numberOfActiveTeammates !=0 ){//判断是否有发送消息的队友
				for (Teammate tempTeammate:theTeammateData.teammates)
				{		//找到DefenderBackward的信息
						if (tempTeammate.number != KEEPER_NUM &&
							tempTeammate.number != STRIKER_NUM && 
                            tempTeammate.number != SUPPORTER_NUM &&
							tempTeammate.number != theRobotInfo.number )
							{otherDefender=tempTeammate;}
				}
				if (otherDefender.number ==-1 || otherDefender.status != Teammate::Status::FULLY_ACTIVE )//为空或者没有在踢球
					goto DefenderBackward;
				if (theFrameInfo.getTimeSince(otherDefender.ball.timeWhenLastSeen) < 600 &&
							libCodeRelease.timeSinceBallWasSeen()<300 &&
							(otherDefender.ball.estimate.position.norm() > theBallModel.estimate.position.norm()) )
					goto DefenderBackward;
				else if (theFrameInfo.getTimeSince(otherDefender.ball.timeWhenLastSeen) > 7000 &&
							libCodeRelease.timeSinceBallWasSeen()<300)
					goto DefenderBackward;
		  }
		  }
	  action
	  {
			//ShowTeammateData(otherTeammate.number,otherTeammate.ball);
           // for(Obstacle o:theObstacleModel.obstacles)
             //   ShowObstacles(o.center);
			DefenderForward();
            theBehaviorStatus.role = Role::defender;
		}
	}
    
    state(DefenderBackward)
    {
		transition{
		  if ( theTeammateData.numberOfActiveTeammates !=0 ){//判断是否有发送消息的队友，没有的情况默认为Striker
				for (Teammate tempTeammate:theTeammateData.teammates)
				{		//找到DefenderForward的信息
						if (tempTeammate.number != KEEPER_NUM &&
							tempTeammate.number != STRIKER_NUM && 
                            tempTeammate.number != SUPPORTER_NUM &&
							tempTeammate.number != theRobotInfo.number )
							{otherDefender=tempTeammate;}
				}
				if (theFrameInfo.getTimeSince(otherDefender.ball.timeWhenLastSeen) < 600 &&
						libCodeRelease.timeSinceBallWasSeen()<300 &&
						(otherDefender.ball.estimate.position.norm() < theBallModel.estimate.position.norm()) )
					goto DefenderForward;
		  }
	  }
        action
        {
            DefenderBackward();
            theBehaviorStatus.role = Role::defender;
        }
    }
    
state(Striker)
  {
	  transition{
		  if ( theTeammateData.numberOfActiveTeammates !=0 ){//判断是否有发送消息的队友，没有的情况默认为Striker
				for (Teammate tempTeammate:theTeammateData.teammates)
				{		//找到Supporter的信息
						if (tempTeammate.number != KEEPER_NUM &&
							tempTeammate.number != DEFENDER_FORWARD && 
                            tempTeammate.number != DEFENDER_BACKWARD &&
							tempTeammate.number != theRobotInfo.number )
							{otherTeammate=tempTeammate;}
				}
				if (theFrameInfo.getTimeSince(otherTeammate.ball.timeWhenLastSeen) < 600 &&
						libCodeRelease.timeSinceBallWasSeen()<300 &&
						(otherTeammate.ball.estimate.position.norm() < theBallModel.estimate.position.norm()) )
					goto Supporter;
		  }
	  }
	  action
	  {
                ShowTeammateData(otherTeammate.number,otherTeammate.ball);
                StrikerDong();
                theBehaviorStatus.role = Role::striker;
		}
	}
	state(Supporter)
  {
	  transition{
		  if ( theTeammateData.numberOfActiveTeammates !=0 ){//判断是否有发送消息的队友，没有的情况默认为Striker
				for (Teammate tempTeammate:theTeammateData.teammates)
				{		//找到Striker的信息
						if (tempTeammate.number != KEEPER_NUM &&
							tempTeammate.number != DEFENDER_FORWARD && 
                            tempTeammate.number != DEFENDER_BACKWARD &&
							tempTeammate.number != theRobotInfo.number )
							{otherTeammate=tempTeammate;}
				}
				if (otherTeammate.number ==-1 || otherTeammate.status != Teammate::Status::FULLY_ACTIVE )//为空或者没有在踢球
					goto Striker;
				if (theFrameInfo.getTimeSince(otherTeammate.ball.timeWhenLastSeen) < 600 &&
							libCodeRelease.timeSinceBallWasSeen()<300 &&
							(otherTeammate.ball.estimate.position.norm() > theBallModel.estimate.position.norm()) )
					goto Striker;
				else if (theFrameInfo.getTimeSince(otherTeammate.ball.timeWhenLastSeen) > 7000 &&
							libCodeRelease.timeSinceBallWasSeen()<300)
					goto Striker;
		  }
		  else {goto Striker;}
	  }
	  action
	  {
                ShowTeammateData(otherTeammate.number,otherTeammate.ball);
                theBehaviorStatus.role = Role::supporter;
                Supporter();
		}
}
}
Teammate otherTeammate;
Teammate otherDefender;
