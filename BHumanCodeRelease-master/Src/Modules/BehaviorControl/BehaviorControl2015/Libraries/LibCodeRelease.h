
/**
* @file LibCodeRelease.h
*/

class LibCodeRelease : public LibraryBase
{
public:
  /** Constructor for initializing all members*/
  LibCodeRelease();

  void preProcess() override;

  void postProcess() override;
  
  
  bool between(float value, float min, float max);
  float getAngle(const Vector2f& vector1, const Vector2f& vector2);
  
  Vector2f turnCoordnate(const Vector2f& vect);
    
  int timeSinceBallWasSeen();

  float angleToGoal;
  float angleToGoalForStriker;
  float angleForPenaltyStriker;
  bool returnFormPenalty;
  bool firstKick;
  std::vector<Obstacle> filterdObstacles;
};