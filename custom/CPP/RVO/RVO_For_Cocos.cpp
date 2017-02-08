//
//  RVO_For_Cocos.cpp
//  XuYouGame
//
//  Created by chenhongliang on 16/12/26.
//
//

#include "RVO_For_Cocos.h"
#include "cocos2d.h"

using namespace cocos2d;


static CocosRVO * cocosRVO = nullptr;

/**
 * \brief      Constructs a m_simulator instance.
 */
CocosRVO::CocosRVO()
:m_simulator(nullptr)
{
    CCLOG("CocosRVO::CocosRVO()");
    this->m_simulator = new RVO::RVOSimulator;
    this->m_agentsNode.clear();
    this->m_agentsNextPos.clear();
}

/**
 * \brief      Constructs a m_simulator instance and sets the default
 *             properties for any new agent that is added.
 * \param      timeStep        The time step of the simulation.
 *                             Must be positive.
 * \param      neighborDist    The default maximum distance (center point
 *                             to center point) to other agents a new agent
 *                             takes into account in the navigation. The
 *                             larger this number, the longer he running
 *                             time of the simulation. If the number is too
 *                             low, the simulation will not be safe. Must be
 *                             non-negative.
 * \param      maxNeighbors    The default maximum number of other agents a
 *                             new agent takes into account in the
 *                             navigation. The larger this number, the
 *                             longer the running time of the simulation.
 *                             If the number is too low, the simulation
 *                             will not be safe.
 * \param      timeHorizon     The default minimal amount of time for which
 *                             a new agent's velocities that are computed
 *                             by the simulation are safe with respect to
 *                             other agents. The larger this number, the
 *                             sooner an agent will respond to the presence
 *                             of other agents, but the less freedom the
 *                             agent has in choosing its velocities.
 *                             Must be positive.
 * \param      timeHorizonObst The default minimal amount of time for which
 *                             a new agent's velocities that are computed
 *                             by the simulation are safe with respect to
 *                             obstacles. The larger this number, the
 *                             sooner an agent will respond to the presence
 *                             of obstacles, but the less freedom the agent
 *                             has in choosing its velocities.
 *                             Must be positive.
 * \param      radius          The default radius of a new agent.
 *                             Must be non-negative.
 * \param      maxSpeed        The default maximum speed of a new agent.
 *                             Must be non-negative.
 * \param      velocity        The default initial two-dimensional linear
 *                             velocity of a new agent (optional).
 */
CocosRVO::CocosRVO(float timeStep, float neighborDist, size_t maxNeighbors,float timeHorizon, float timeHorizonObst, float radius,float maxSpeed, const Vec2 &velocity)
:m_simulator(nullptr)
{
    const RVO::Vector2 v = RVO::Vector2(velocity.x,velocity.y);
    this->m_simulator = new RVO::RVOSimulator(timeStep,neighborDist,maxNeighbors,timeHorizon,timeHorizonObst,radius,maxSpeed,v);
    this->m_agentsNode.clear();
    this->m_agentsNextPos.clear();
}

/**
 * \brief      Destroys this m_simulator instance.
 */
CocosRVO::~CocosRVO(){
    CCLOG("CocosRVO::~CocosRVO()");
    delete this->m_simulator;
    this->m_simulator = nullptr;
    this->m_agentsNode.clear();
    this->m_agentsNextPos.clear();
}

RVO::Vector2 CocosRVO::splitStringToVcetor2(const std::string& s, const std::string& c)
{
    std::vector<std::string> v;
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
        
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length()){
        v.push_back(s.substr(pos1));
    }
    
    if (v.size()==0) {
        return RVO::Vector2(0,0);
    }
    else if (v.size() == 1){
        return RVO::Vector2(std::atof(v[0].c_str()),0);
    }
    else{
        return RVO::Vector2(std::atof(v[0].c_str()),std::atof(v[1].c_str()));
    }
}

CocosRVO * CocosRVO::create()
{
    if (cocosRVO) {
        cocosRVO->release();
    }
    cocosRVO = new CocosRVO();
    return cocosRVO;
}
CocosRVO * CocosRVO::create(float timeStep, float neighborDist, size_t maxNeighbors,
                         float timeHorizon, float timeHorizonObst, float radius,
                         float maxSpeed, const Vec2 &velocity)
{
    if (cocosRVO) {
        cocosRVO->release();
    }
    cocosRVO = new CocosRVO(timeStep,neighborDist,maxNeighbors,timeHorizon,timeHorizonObst,radius,maxSpeed,velocity);
    return cocosRVO;
}

void CocosRVO::release()
{
    delete cocosRVO;
    cocosRVO = nullptr;
}

/**
 * \brief      Adds a new agent with default properties to the
 *             simulation.
 * \param      position        The two-dimensional starting position of
 *                             this agent.
 * \return     The number of the agent, or RVO::RVO_ERROR when the agent
 *             defaults have not been set.
 */
size_t CocosRVO::addAgent(Node* node, const Vec2 &position)
{
    this->m_agentsNode.push_back(node);
    RVO::Vector2 p = RVO::Vector2(position.x,position.y);
    return this->m_simulator->addAgent(p);
}

/**
 * \brief      Adds a new agent to the simulation.
 * \param      position        The two-dimensional starting position of
 *                             this agent.
 * \param      neighborDist    The maximum distance (center point to
 *                             center point) to other agents this agent
 *                             takes into account in the navigation. The
 *                             larger this number, the longer the running
 *                             time of the simulation. If the number is too
 *                             low, the simulation will not be safe.
 *                             Must be non-negative.
 * \param      maxNeighbors    The maximum number of other agents this
 *                             agent takes into account in the navigation.
 *                             The larger this number, the longer the
 *                             running time of the simulation. If the
 *                             number is too low, the simulation will not
 *                             be safe.
 * \param      timeHorizon     The minimal amount of time for which this
 *                             agent's velocities that are computed by the
 *                             simulation are safe with respect to other
 *                             agents. The larger this number, the sooner
 *                             this agent will respond to the presence of
 *                             other agents, but the less freedom this
 *                             agent has in choosing its velocities.
 *                             Must be positive.
 * \param      timeHorizonObst The minimal amount of time for which this
 *                             agent's velocities that are computed by the
 *                             simulation are safe with respect to
 *                             obstacles. The larger this number, the
 *                             sooner this agent will respond to the
 *                             presence of obstacles, but the less freedom
 *                             this agent has in choosing its velocities.
 *                             Must be positive.
 * \param      radius          The radius of this agent.
 *                             Must be non-negative.
 * \param      maxSpeed        The maximum speed of this agent.
 *                             Must be non-negative.
 * \param      velocity        The initial two-dimensional linear velocity
 *                             of this agent (optional).
 * \return     The number of the agent.
 */
size_t CocosRVO::addAgent(Node* node, const Vec2 &position, float neighborDist,
                size_t maxNeighbors, float timeHorizon,
                float timeHorizonObst, float radius, float maxSpeed,
                const Vec2 &velocity)
{
    this->m_agentsNode.push_back(node);
    RVO::Vector2 p = RVO::Vector2(position.x,position.y);
    RVO::Vector2 v2 = RVO::Vector2(velocity.x,velocity.y);
    return this->m_simulator->addAgent(p, neighborDist, maxNeighbors, timeHorizon, timeHorizonObst, radius, maxSpeed, v2);
}

bool CocosRVO::removeAgent(size_t agentNo)
{
    std::vector<Node*>::iterator itNode = this->m_agentsNode.begin();
    for (size_t i=0; i<this->m_agentsNode.size(); ++i,itNode++) {
        if (i == agentNo) {
            this->m_agentsNode.erase(itNode);
            break;
        }
    }
    return this->m_simulator->removeAgent(agentNo);
}

/**
 * \brief      Adds a new obstacle to the simulation.
 * \param      vertices        List of the vertices of the polygonal
 *             obstacle in counterclockwise order.
 * \return     The number of the first vertex of the obstacle,
 *             or RVO::RVO_ERROR when the number of vertices is less than two.
 * \note       To add a "negative" obstacle, e.g. a bounding polygon around
 *             the environment, the vertices should be listed in clockwise
 *             order.
 */
size_t CocosRVO::addObstacle(const std::vector<Vec2> &vertices)
{
    std::vector<RVO::Vector2> vs;
    for (size_t i=0; i<vertices.size(); ++i) {
        vs.push_back(RVO::Vector2(vertices[i].x,vertices[i].y));
    }
    return this->m_simulator->addObstacle(vs);
}

/**
 * \brief      Lets the m_simulator perform a simulation step and updates the
 *             two-dimensional position and two-dimensional velocity of
 *             each agent.
 */
void CocosRVO::doStep()
{
    this->updateVisualization();
    this->setPreferredVelocities();
    
    this->m_simulator->doStep();
    
    this->reachedGoal();
}

/**
 * \brief      Returns the specified agent neighbor of the specified
 *             agent.
 * \param      agentNo         The number of the agent whose agent
 *                             neighbor is to be retrieved.
 * \param      neighborNo      The number of the agent neighbor to be
 *                             retrieved.
 * \return     The number of the neighboring agent.
 */
size_t CocosRVO::getAgentAgentNeighbor(size_t agentNo, size_t neighborNo) const
{
    return this->m_simulator->getAgentAgentNeighbor(agentNo, neighborNo);
}

/**
 * \brief      Returns the maximum neighbor count of a specified agent.
 * \param      agentNo         The number of the agent whose maximum
 *                             neighbor count is to be retrieved.
 * \return     The present maximum neighbor count of the agent.
 */
size_t CocosRVO::getAgentMaxNeighbors(size_t agentNo) const
{
    return this->m_simulator->getAgentMaxNeighbors(agentNo);
}

/**
 * \brief      Returns the maximum speed of a specified agent.
 * \param      agentNo         The number of the agent whose maximum speed
 *                             is to be retrieved.
 * \return     The present maximum speed of the agent.
 */
float CocosRVO::getAgentMaxSpeed(size_t agentNo) const
{
    return this->m_simulator->getAgentMaxSpeed(agentNo);
}

/**
 * \brief      Returns the maximum neighbor distance of a specified
 *             agent.
 * \param      agentNo         The number of the agent whose maximum
 *                             neighbor distance is to be retrieved.
 * \return     The present maximum neighbor distance of the agent.
 */
float CocosRVO::getAgentNeighborDist(size_t agentNo) const
{
    return this->m_simulator->getAgentNeighborDist(agentNo);
}

/**
 * \brief      Returns the count of agent neighbors taken into account to
 *             compute the current velocity for the specified agent.
 * \param      agentNo         The number of the agent whose count of agent
 *                             neighbors is to be retrieved.
 * \return     The count of agent neighbors taken into account to compute
 *             the current velocity for the specified agent.
 */
size_t CocosRVO::getAgentNumAgentNeighbors(size_t agentNo) const
{
    return this->m_simulator->getAgentNumAgentNeighbors(agentNo);
}

/**
 * \brief      Returns the count of obstacle neighbors taken into account
 *             to compute the current velocity for the specified agent.
 * \param      agentNo         The number of the agent whose count of
 *                             obstacle neighbors is to be retrieved.
 * \return     The count of obstacle neighbors taken into account to
 *             compute the current velocity for the specified agent.
 */
size_t CocosRVO::getAgentNumObstacleNeighbors(size_t agentNo) const
{
    return this->m_simulator->getAgentNumObstacleNeighbors(agentNo);
}


/**
 * \brief      Returns the count of ORCA constraints used to compute
 *             the current velocity for the specified agent.
 * \param      agentNo         The number of the agent whose count of ORCA
 *                             constraints is to be retrieved.
 * \return     The count of ORCA constraints used to compute the current
 *             velocity for the specified agent.
 */
size_t CocosRVO::getAgentNumORCALines(size_t agentNo) const
{
    return this->m_simulator->getAgentNumORCALines(agentNo);
}

/**
 * \brief      Returns the specified obstacle neighbor of the specified
 *             agent.
 * \param      agentNo         The number of the agent whose obstacle
 *                             neighbor is to be retrieved.
 * \param      neighborNo      The number of the obstacle neighbor to be
 *                             retrieved.
 * \return     The number of the first vertex of the neighboring obstacle
 *             edge.
 */
size_t CocosRVO::getAgentObstacleNeighbor(size_t agentNo, size_t neighborNo) const
{
    return this->m_simulator->getAgentObstacleNeighbor(agentNo,neighborNo);
}

/**
 * \brief      Returns the specified ORCA constraint of the specified
 *             agent.
 * \param      agentNo         The number of the agent whose ORCA
 *                             constraint is to be retrieved.
 * \param      lineNo          The number of the ORCA constraint to be
 *                             retrieved.
 * \return     A line representing the specified ORCA constraint.
 * \note       The halfplane to the left of the line is the region of
 *             permissible velocities with respect to the specified
 *             ORCA constraint.
 */
const std::vector<Vec2> CocosRVO::getAgentORCALine(size_t agentNo, size_t lineNo) const
{
    const RVO::Line& l = this->m_simulator->getAgentORCALine(agentNo,lineNo);
    std::vector<Vec2> vs;
    vs.resize(2);
    
    vs.push_back(Vec2(l.point.x(),l.point.y()));
    vs.push_back(Vec2(l.direction.x(),l.direction.y()));
    return vs;
}

/**
 * \brief      Returns the two-dimensional position of a specified
 *             agent.
 * \param      agentNo         The number of the agent whose
 *                             two-dimensional position is to be retrieved.
 * \return     The present two-dimensional position of the (center of the)
 *             agent.
 */
const Vec2 CocosRVO::getAgentPosition(size_t agentNo) const
{
    auto v = this->m_simulator->getAgentPosition(agentNo);
    return Vec2(v.x(),v.y());
}

/**
 * \brief      Returns the two-dimensional preferred velocity of a
 *             specified agent.
 * \param      agentNo         The number of the agent whose
 *                             two-dimensional preferred velocity is to be
 *                             retrieved.
 * \return     The present two-dimensional preferred velocity of the agent.
 */
const Vec2 CocosRVO::getAgentPrefVelocity(size_t agentNo) const
{
    auto v = this->m_simulator->getAgentPrefVelocity(agentNo);
    return Vec2(v.x(),v.y());
}

/**
 * \brief      Returns the radius of a specified agent.
 * \param      agentNo         The number of the agent whose radius is to
 *                             be retrieved.
 * \return     The present radius of the agent.
 */
float CocosRVO::getAgentRadius(size_t agentNo) const
{
    return this->m_simulator->getAgentRadius(agentNo);
}

/**
 * \brief      Returns the time horizon of a specified agent.
 * \param      agentNo         The number of the agent whose time horizon
 *                             is to be retrieved.
 * \return     The present time horizon of the agent.
 */
float CocosRVO::getAgentTimeHorizon(size_t agentNo) const
{
    return this->m_simulator->getAgentTimeHorizon(agentNo);
}

/**
 * \brief      Returns the time horizon with respect to obstacles of a
 *             specified agent.
 * \param      agentNo         The number of the agent whose time horizon
 *                             with respect to obstacles is to be
 *                             retrieved.
 * \return     The present time horizon with respect to obstacles of the
 *             agent.
 */
float CocosRVO::getAgentTimeHorizonObst(size_t agentNo) const
{
    return this->m_simulator->getAgentTimeHorizonObst(agentNo);
}

/**
 * \brief      Returns the two-dimensional linear velocity of a
 *             specified agent.
 * \param      agentNo         The number of the agent whose
 *                             two-dimensional linear velocity is to be
 *                             retrieved.
 * \return     The present two-dimensional linear velocity of the agent.
 */
const Vec2 CocosRVO::getAgentVelocity(size_t agentNo) const
{
    auto v = this->m_simulator->getAgentVelocity(agentNo);
    return Vec2(v.x(),v.y());
}

/**
 * \brief      Returns the global time of the simulation.
 * \return     The present global time of the simulation (zero initially).
 */
float CocosRVO::getGlobalTime() const
{
    return this->m_simulator->getGlobalTime();
}

/**
 * \brief      Returns the count of agents in the simulation.
 * \return     The count of agents in the simulation.
 */
size_t CocosRVO::getNumAgents() const
{
    return this->m_simulator->getNumAgents();
}

/**
 * \brief      Returns the count of obstacle vertices in the simulation.
 * \return     The count of obstacle vertices in the simulation.
 */
size_t CocosRVO::getNumObstacleVertices() const
{
    return this->m_simulator->getNumObstacleVertices();
}

/**
 * \brief      Returns the two-dimensional position of a specified obstacle
 *             vertex.
 * \param      vertexNo        The number of the obstacle vertex to be
 *                             retrieved.
 * \return     The two-dimensional position of the specified obstacle
 *             vertex.
 */
const Vec2 CocosRVO::getObstacleVertex(size_t vertexNo) const
{
    auto v = this->m_simulator->getObstacleVertex(vertexNo);
    return Vec2(v.x(),v.y());
}

/**
 * \brief      Returns the number of the obstacle vertex succeeding the
 *             specified obstacle vertex in its polygon.
 * \param      vertexNo        The number of the obstacle vertex whose
 *                             successor is to be retrieved.
 * \return     The number of the obstacle vertex succeeding the specified
 *             obstacle vertex in its polygon.
 */
size_t CocosRVO::getNextObstacleVertexNo(size_t vertexNo) const
{
    return this->m_simulator->getNextObstacleVertexNo(vertexNo);
}

/**
 * \brief      Returns the number of the obstacle vertex preceding the
 *             specified obstacle vertex in its polygon.
 * \param      vertexNo        The number of the obstacle vertex whose
 *                             predecessor is to be retrieved.
 * \return     The number of the obstacle vertex preceding the specified
 *             obstacle vertex in its polygon.
 */
size_t CocosRVO::getPrevObstacleVertexNo(size_t vertexNo) const
{
    return this->m_simulator->getPrevObstacleVertexNo(vertexNo);
}

/**
 * \brief      Returns the time step of the simulation.
 * \return     The present time step of the simulation.
 */
float CocosRVO::getTimeStep() const
{
    return this->m_simulator->getTimeStep();
}

/**
 * \brief      Processes the obstacles that have been added so that they
 *             are accounted for in the simulation.
 * \note       Obstacles added to the simulation after this function has
 *             been called are not accounted for in the simulation.
 */
void CocosRVO::processObstacles()
{
    return this->m_simulator->processObstacles();
}

/**
 * \brief      Performs a visibility query between the two specified
 *             points with respect to the obstacles
 * \param      point1          The first point of the query.
 * \param      point2          The second point of the query.
 * \param      radius          The minimal distance between the line
 *                             connecting the two points and the obstacles
 *                             in order for the points to be mutually
 *                             visible (optional). Must be non-negative.
 * \return     A boolean specifying whether the two points are mutually
 *             visible. Returns true when the obstacles have not been
 *             processed.
 */
bool CocosRVO::queryVisibility(const Vec2 &point1, const Vec2 &point2,
                     float radius) const
{
    auto p1 = RVO::Vector2(point1.x,point1.y);
    auto p2 = RVO::Vector2(point2.x,point2.y);
    return this->m_simulator->queryVisibility(p1, p2);
}

/**
 * \brief      Sets the default properties for any new agent that is
 *             added.
 * \param      neighborDist    The default maximum distance (center point
 *                             to center point) to other agents a new agent
 *                             takes into account in the navigation. The
 *                             larger this number, the longer he running
 *                             time of the simulation. If the number is too
 *                             low, the simulation will not be safe.
 *                             Must be non-negative.
 * \param      maxNeighbors    The default maximum number of other agents a
 *                             new agent takes into account in the
 *                             navigation. The larger this number, the
 *                             longer the running time of the simulation.
 *                             If the number is too low, the simulation
 *                             will not be safe.
 * \param      timeHorizon     The default minimal amount of time for which
 *                             a new agent's velocities that are computed
 *                             by the simulation are safe with respect to
 *                             other agents. The larger this number, the
 *                             sooner an agent will respond to the presence
 *                             of other agents, but the less freedom the
 *                             agent has in choosing its velocities.
 *                             Must be positive.
 * \param      timeHorizonObst The default minimal amount of time for which
 *                             a new agent's velocities that are computed
 *                             by the simulation are safe with respect to
 *                             obstacles. The larger this number, the
 *                             sooner an agent will respond to the presence
 *                             of obstacles, but the less freedom the agent
 *                             has in choosing its velocities.
 *                             Must be positive.
 * \param      radius          The default radius of a new agent.
 *                             Must be non-negative.
 * \param      maxSpeed        The default maximum speed of a new agent.
 *                             Must be non-negative.
 * \param      velocity        The default initial two-dimensional linear
 *                             velocity of a new agent (optional).
 */
void CocosRVO::setAgentDefaults(float neighborDist, size_t maxNeighbors,
                      float timeHorizon, float timeHorizonObst,
                      float radius, float maxSpeed,
                      const Vec2 &velocity)
{
    auto v = RVO::Vector2(velocity.x,velocity.y);
    this->m_simulator->setAgentDefaults(neighborDist, maxNeighbors, timeHorizon, timeHorizonObst, radius, maxSpeed, v);
}

/**
 * \brief      Sets the maximum neighbor count of a specified agent.
 * \param      agentNo         The number of the agent whose maximum
 *                             neighbor count is to be modified.
 * \param      maxNeighbors    The replacement maximum neighbor count.
 */
void CocosRVO::setAgentMaxNeighbors(size_t agentNo, size_t maxNeighbors)
{
    this->m_simulator->setAgentMaxNeighbors(agentNo, maxNeighbors);
}

/**
 * \brief      Sets the maximum speed of a specified agent.
 * \param      agentNo         The number of the agent whose maximum speed
 *                             is to be modified.
 * \param      maxSpeed        The replacement maximum speed. Must be
 *                             non-negative.
 */
void CocosRVO::setAgentMaxSpeed(size_t agentNo, float maxSpeed)
{
    this->m_simulator->setAgentMaxSpeed(agentNo, maxSpeed);
}

/**
 * \brief      Sets the maximum neighbor distance of a specified agent.
 * \param      agentNo         The number of the agent whose maximum
 *                             neighbor distance is to be modified.
 * \param      neighborDist    The replacement maximum neighbor distance.
 *                             Must be non-negative.
 */
void CocosRVO::setAgentNeighborDist(size_t agentNo, float neighborDist)
{
    this->m_simulator->setAgentNeighborDist(agentNo, neighborDist);
}

/**
 * \brief      Sets the two-dimensional position of a specified agent.
 * \param      agentNo         The number of the agent whose
 *                             two-dimensional position is to be modified.
 * \param      position        The replacement of the two-dimensional
 *                             position.
 */
void CocosRVO::setAgentPosition(size_t agentNo, const Vec2 &position)
{
    auto p = RVO::Vector2(position.x,position.y);
    this->m_simulator->setAgentPosition(agentNo, p);
}

/**
 * \brief      Sets the two-dimensional preferred velocity of a
 *             specified agent.
 * \param      agentNo         The number of the agent whose
 *                             two-dimensional preferred velocity is to be
 *                             modified.
 * \param      prefVelocity    The replacement of the two-dimensional
 *                             preferred velocity.
 */
void CocosRVO::setAgentPrefVelocity(size_t agentNo, const Vec2 &prefVelocity)
{
    auto pv = RVO::Vector2(prefVelocity.x,prefVelocity.y);
    this->m_simulator->setAgentPrefVelocity(agentNo, pv);
}

/**
 * \brief      Sets the radius of a specified agent.
 * \param      agentNo         The number of the agent whose radius is to
 *                             be modified.
 * \param      radius          The replacement radius.
 *                             Must be non-negative.
 */
void CocosRVO::setAgentRadius(size_t agentNo, float radius)
{
    this->m_simulator->setAgentRadius(agentNo, radius);
}

/**
 * \brief      Sets the time horizon of a specified agent with respect
 *             to other agents.
 * \param      agentNo         The number of the agent whose time horizon
 *                             is to be modified.
 * \param      timeHorizon     The replacement time horizon with respect
 *                             to other agents. Must be positive.
 */
void CocosRVO::setAgentTimeHorizon(size_t agentNo, float timeHorizon)
{
    this->m_simulator->setAgentTimeHorizon(agentNo, timeHorizon);
}

/**
 * \brief      Sets the time horizon of a specified agent with respect
 *             to obstacles.
 * \param      agentNo         The number of the agent whose time horizon
 *                             with respect to obstacles is to be modified.
 * \param      timeHorizonObst The replacement time horizon with respect to
 *                             obstacles. Must be positive.
 */
void CocosRVO::setAgentTimeHorizonObst(size_t agentNo, float timeHorizonObst)
{
    this->m_simulator->setAgentTimeHorizonObst(agentNo, timeHorizonObst);
}

/**
 * \brief      Sets the two-dimensional linear velocity of a specified
 *             agent.
 * \param      agentNo         The number of the agent whose
 *                             two-dimensional linear velocity is to be
 *                             modified.
 * \param      velocity        The replacement two-dimensional linear
 *                             velocity.
 */
void CocosRVO::setAgentVelocity(size_t agentNo, const Vec2 &velocity)
{
    auto v = RVO::Vector2(velocity.x,velocity.y);
    this->m_simulator->setAgentVelocity(agentNo, v);
}

/**
 * \brief      Sets the time step of the simulation.
 * \param      timeStep        The time step of the simulation.
 *                             Must be positive.
 */
void CocosRVO::setTimeStep(float timeStep)
{
    this->m_simulator->setTimeStep(timeStep);
}

size_t CocosRVO::setAgentsNextPos(const std::vector<Vec2> &poses)
{
    this->m_agentsNextPos.clear();
    this->m_agentsNextPos = poses;
    return this->m_agentsNextPos.size();
}

void CocosRVO::updateVisualization()
{
    std::vector<Node*> locals;
    for (size_t i=0; i<this->getNumAgents(); ++i) {
        if(this->m_agentsNode.size() > i){
            Vec2 curPos = this->getAgentPosition(i);
            this->m_agentsNode[i]->setPosition(curPos);
            locals.push_back(this->m_agentsNode[i]);
        }
    }
    if (locals.size() <= 0) {
        return;
    }
    std::sort(locals.begin(), locals.end(), [](const Node* n1, const Node* n2){
        auto pos1 = n1->getPosition();
        auto pos2 = n2->getPosition();
        return pos1.y > pos2.y;
//        if (pos1.y > pos2.y) {
//            return true;
//        }
//        else if (fabs(pos1.y-pos2.y) < 0.1){
//            return pos1.x < pos2.x;
//        }
//        return false;
    });
    for (size_t i=0;i<locals.size();++i){
        locals[i]->setLocalZOrder(static_cast<int>(i+10));
    }
}

void CocosRVO::setPreferredVelocities()
{
    for (int i = 0; i < static_cast<int>(this->getNumAgents()); ++i) {
        if (i < this->m_agentsNextPos.size()) {
            Vec2 goalVector = this->m_agentsNextPos[i] - this->getAgentPosition(i);

//            if (goalVector.dot(goalVector) > 1.0f) {
//                goalVector.normalize();
//            }
            
            this->setAgentPrefVelocity(i, goalVector);
            
            float angle = std::rand() * 2.0f * M_PI / RAND_MAX;
            float dist = std::rand() * 0.0001f / RAND_MAX;
            
            this->setAgentPrefVelocity(i, this->getAgentPrefVelocity(i) + dist * Vec2(std::cos(angle), std::sin(angle)));
        }
    }
}

std::vector<int> CocosRVO::reachedGoal()
{
    std::vector<int> reachs;
    for (size_t i = 0; i < this->getNumAgents(); ++i) {
        if (i < this->m_agentsNextPos.size()) {
            Vec2 v = this->getAgentPosition(i) - this->m_agentsNextPos[i];
            if (v.dot(v) < this->getAgentRadius(i) * this->getAgentRadius(i)) {
//                this->setAgentPosition(i, this->getAgentPosition(i));
                this->setAgentPosition(i, this->m_agentsNextPos[i]);
                reachs.push_back(static_cast<int>(i));
            }
        }
    }
    
    return reachs;
}
