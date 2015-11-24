#ifndef __ROTATEDMATRIX_H__
#define __ROTATEDMATRIX_H__

#include <iostream>
#include <glm/glm.hpp>
#include <glm/matrix.hpp>

using namespace std;

class RotatedMatrix;

static RotatedMatrix *rotatedMatrix = NULL;

/*
*	工具类，根据旋转前后的向量值求旋转矩阵 
*/
class RotatedMatrix
{
public:
	static RotatedMatrix *sharedInstance();
	static glm::mat3 getRotatedMatrix(glm::vec3 &veca, glm::vec3 &vecb);

	//求两向量的点积
	static float product(glm::vec3 &veca, glm::vec3 &vecb);

	//求向量的长度
	static float distance(glm::vec3 &vec);

};

#endif