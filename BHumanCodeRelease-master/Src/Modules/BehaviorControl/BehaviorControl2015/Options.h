/** All option files that belong to the current behavior have to be included by this file. */

#include "Options/Soccer.h"


#include "Options/GameControl/HandleGameState.h"
#include "Options/GameControl/HandlePenaltyState.h"
#include "Options/GameControl/ChooseRoles.h"
#include "Options/GameControl/PlayingState.h"
#include "Options/GameControl/ReadyState.h"
#include "Options/GameControl/SetState.h"

#include "Options/HeadControl/HeadControl.h"
#include "Options/HeadControl/LookForward.h"
#include "Options/HeadControl/LeftAndRight.h"
#include "Options/HeadControl/LookAround.h"

#include "Options/Output/Annotation.h"


#include "Options/Output/ArmMotionRequest/KeyFrameArms.h"

#include "Options/Output/HeadMotionRequest/SetHeadPanTilt.h"
#include "Options/Output/HeadMotionRequest/SetHeadTarget.h"
#include "Options/Output/HeadMotionRequest/SetHeadTargetOnGround.h"

#include "Options/Output/MotionRequest/GetUpEngine.h"
#include "Options/Output/MotionRequest/InWalkKick.h"
#include "Options/Output/MotionRequest/PathToTarget.h"
#include "Options/Output/MotionRequest/SpecialAction.h"
#include "Options/Output/MotionRequest/Stand.h"
#include "Options/Output/MotionRequest/WalkAtSpeed.h"
#include "Options/Output/MotionRequest/WalkAtSpeedPercentage.h"
#include "Options/Output/MotionRequest/WalkToTarget.h"
#include "Options/Output/MotionRequest/WalkToPosition.h"
#include "Options/Output/MotionRequest/WalkToTargetAbsolute.h"
#include "Options/Output/MotionRequest/Shoot.h"

#include "Options/Output/PlaySound.h"

#include "Options/Output/ShowBallToField.h"
#include "Options/Output/ShowBallToRobot.h"
#include "Options/Output/ShowBool.h"
#include "Options/Output/ShowArea.h"
#include "Options/Output/Value.h"
#include "Options/Output/Position.h"

#include "Options/Output/ShowRobotToField.h"
#include "Options/Output/ShowGoalPost.h"
#include "Options/Output/ShowSomething.h"
#include "Options/Output/ShowTeamBallModel.h"
#include "Options/Output/ShowObstacles.h"
#include "Options/Output/ShowWhistle.h"

#include "Options/Output/ShowReadyPosition.h"
#include "Options/Output/ShowTeammateData.h"

#include "Options/Roles/Striker.h"
#include "Options/Roles/Keeper.h"
#include "Options/Roles/Supporter.h"
#include "Options/Roles/TestPlayer.h"
#include "Options/Roles/StrikerTestShoot.h"
#include "Options/Roles/Defender.h"


#include "Options/Output/ShowRobotPose.h"
#include "Options/Skills/LeftKick.h"
#include "Options/Skills/RightKick.h"


#include "Options/Roles/StrikerDong1.h"
#include "Options/Roles/StrikerMing.h"

#include "Options/Skills/ArmContact.h"
#include "Options/Skills/GetUp.h"


#include "Options/Tools/ButtonPressedAndReleased.h"
