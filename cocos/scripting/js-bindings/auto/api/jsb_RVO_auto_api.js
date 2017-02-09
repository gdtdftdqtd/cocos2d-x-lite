/**
 * @module RVO
 */
var RVO = RVO || {};

/**
 * @class Vector2
 */
RVO.Vector2 = {

/**
 * @method y
 * @return {float}
 */
y : function (
)
{
    return 0;
},

/**
 * @method x
 * @return {float}
 */
x : function (
)
{
    return 0;
},

/**
 * @method Vector2
 * @constructor
* @param {float} float
* @param {float} float
*/
Vector2 : function(
float,
float 
)
{
},

};

/**
 * @class RVOSimulator
 */
RVO.RVOSimulator = {

/**
 * @method setAgentVelocity
 * @param {unsigned long} arg0
 * @param {RVO::Vector2} arg1
 */
setAgentVelocity : function (
long, 
array 
)
{
},

/**
 * @method setAgentRadius
 * @param {unsigned long} arg0
 * @param {float} arg1
 */
setAgentRadius : function (
long, 
float 
)
{
},

/**
 * @method setAgentPrefVelocity
 * @param {unsigned long} arg0
 * @param {RVO::Vector2} arg1
 */
setAgentPrefVelocity : function (
long, 
array 
)
{
},

/**
 * @method setTimeStep
 * @param {float} arg0
 */
setTimeStep : function (
float 
)
{
},

/**
 * @method getNextObstacleVertexNo
 * @param {unsigned long} arg0
 * @return {unsigned long}
 */
getNextObstacleVertexNo : function (
long 
)
{
    return 0;
},

/**
 * @method setAgentDefaults
 * @param {float} arg0
 * @param {unsigned long} arg1
 * @param {float} arg2
 * @param {float} arg3
 * @param {float} arg4
 * @param {float} arg5
 * @param {RVO::Vector2} arg6
 */
setAgentDefaults : function (
float, 
long, 
float, 
float, 
float, 
float, 
array 
)
{
},

/**
 * @method getNumObstacleVertices
 * @return {unsigned long}
 */
getNumObstacleVertices : function (
)
{
    return 0;
},

/**
 * @method getAgentTimeHorizon
 * @param {unsigned long} arg0
 * @return {float}
 */
getAgentTimeHorizon : function (
long 
)
{
    return 0;
},

/**
 * @method getTimeStep
 * @return {float}
 */
getTimeStep : function (
)
{
    return 0;
},

/**
 * @method doStep
 */
doStep : function (
)
{
},

/**
 * @method getAgentMaxNeighbors
 * @param {unsigned long} arg0
 * @return {unsigned long}
 */
getAgentMaxNeighbors : function (
long 
)
{
    return 0;
},

/**
 * @method setAgentTimeHorizon
 * @param {unsigned long} arg0
 * @param {float} arg1
 */
setAgentTimeHorizon : function (
long, 
float 
)
{
},

/**
 * @method addObstacle
 * @param {Array} arg0
 * @return {unsigned long}
 */
addObstacle : function (
array 
)
{
    return 0;
},

/**
 * @method getAgentNumAgentNeighbors
 * @param {unsigned long} arg0
 * @return {unsigned long}
 */
getAgentNumAgentNeighbors : function (
long 
)
{
    return 0;
},

/**
 * @method getAgentRadius
 * @param {unsigned long} arg0
 * @return {float}
 */
getAgentRadius : function (
long 
)
{
    return 0;
},

/**
 * @method getAgentVelocity
 * @param {unsigned long} arg0
 * @return {RVO::Vector2}
 */
getAgentVelocity : function (
long 
)
{
    return new Array();
},

/**
 * @method removeAgent
 * @param {unsigned long} arg0
 * @return {bool}
 */
removeAgent : function (
long 
)
{
    return false;
},

/**
 * @method getAgentNumORCALines
 * @param {unsigned long} arg0
 * @return {unsigned long}
 */
getAgentNumORCALines : function (
long 
)
{
    return 0;
},

/**
 * @method getAgentNeighborDist
 * @param {unsigned long} arg0
 * @return {float}
 */
getAgentNeighborDist : function (
long 
)
{
    return 0;
},

/**
 * @method setAgentMaxSpeed
 * @param {unsigned long} arg0
 * @param {float} arg1
 */
setAgentMaxSpeed : function (
long, 
float 
)
{
},

/**
 * @method getAgentPrefVelocity
 * @param {unsigned long} arg0
 * @return {RVO::Vector2}
 */
getAgentPrefVelocity : function (
long 
)
{
    return new Array();
},

/**
 * @method setAgentMaxNeighbors
 * @param {unsigned long} arg0
 * @param {unsigned long} arg1
 */
setAgentMaxNeighbors : function (
long, 
long 
)
{
},

/**
 * @method getNumAgents
 * @return {unsigned long}
 */
getNumAgents : function (
)
{
    return 0;
},

/**
 * @method getAgentMaxSpeed
 * @param {unsigned long} arg0
 * @return {float}
 */
getAgentMaxSpeed : function (
long 
)
{
    return 0;
},

/**
 * @method setAgentTimeHorizonObst
 * @param {unsigned long} arg0
 * @param {float} arg1
 */
setAgentTimeHorizonObst : function (
long, 
float 
)
{
},

/**
 * @method addAgent
* @param {RVO::Vector2|RVO::Vector2} array
* @param {float} float
* @param {unsigned long} long
* @param {float} float
* @param {float} float
* @param {float} float
* @param {float} float
* @param {RVO::Vector2} array
* @return {unsigned long|unsigned long}
*/
addAgent : function(
array,
float,
long,
float,
float,
float,
float,
array 
)
{
    return 0;
},

/**
 * @method getAgentObstacleNeighbor
 * @param {unsigned long} arg0
 * @param {unsigned long} arg1
 * @return {unsigned long}
 */
getAgentObstacleNeighbor : function (
long, 
long 
)
{
    return 0;
},

/**
 * @method getGlobalTime
 * @return {float}
 */
getGlobalTime : function (
)
{
    return 0;
},

/**
 * @method getObstacleVertex
 * @param {unsigned long} arg0
 * @return {RVO::Vector2}
 */
getObstacleVertex : function (
long 
)
{
    return new Array();
},

/**
 * @method getAgentAgentNeighbor
 * @param {unsigned long} arg0
 * @param {unsigned long} arg1
 * @return {unsigned long}
 */
getAgentAgentNeighbor : function (
long, 
long 
)
{
    return 0;
},

/**
 * @method setAgentPosition
 * @param {unsigned long} arg0
 * @param {RVO::Vector2} arg1
 */
setAgentPosition : function (
long, 
array 
)
{
},

/**
 * @method getAgentTimeHorizonObst
 * @param {unsigned long} arg0
 * @return {float}
 */
getAgentTimeHorizonObst : function (
long 
)
{
    return 0;
},

/**
 * @method getAgentNumObstacleNeighbors
 * @param {unsigned long} arg0
 * @return {unsigned long}
 */
getAgentNumObstacleNeighbors : function (
long 
)
{
    return 0;
},

/**
 * @method queryVisibility
 * @param {RVO::Vector2} arg0
 * @param {RVO::Vector2} arg1
 * @param {float} arg2
 * @return {bool}
 */
queryVisibility : function (
array, 
array, 
float 
)
{
    return false;
},

/**
 * @method getAgentPosition
 * @param {unsigned long} arg0
 * @return {RVO::Vector2}
 */
getAgentPosition : function (
long 
)
{
    return new Array();
},

/**
 * @method processObstacles
 */
processObstacles : function (
)
{
},

/**
 * @method getPrevObstacleVertexNo
 * @param {unsigned long} arg0
 * @return {unsigned long}
 */
getPrevObstacleVertexNo : function (
long 
)
{
    return 0;
},

/**
 * @method setAgentNeighborDist
 * @param {unsigned long} arg0
 * @param {float} arg1
 */
setAgentNeighborDist : function (
long, 
float 
)
{
},

/**
 * @method getAgentORCALine
 * @param {unsigned long} arg0
 * @param {unsigned long} arg1
 * @return {RVO::Line}
 */
getAgentORCALine : function (
long, 
long 
)
{
    return RVO::Line;
},

/**
 * @method RVOSimulator
 * @constructor
* @param {float} float
* @param {float} float
* @param {unsigned long} long
* @param {float} float
* @param {float} float
* @param {float} float
* @param {float} float
* @param {RVO::Vector2} array
*/
RVOSimulator : function(
float,
float,
long,
float,
float,
float,
float,
array 
)
{
},

};
