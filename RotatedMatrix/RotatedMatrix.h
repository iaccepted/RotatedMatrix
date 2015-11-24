#ifndef __ROTATEDMATRIX_H__
#define __ROTATEDMATRIX_H__

#include <iostream>
#include <glm/glm.hpp>
#include <glm/matrix.hpp>

using namespace std;

class RotatedMatrix;

static RotatedMatrix *rotatedMatrix = NULL;

/*
*	�����࣬������תǰ�������ֵ����ת���� 
*/
class RotatedMatrix
{
public:
	static RotatedMatrix *sharedInstance();
	static glm::mat3 getRotatedMatrix(glm::vec3 &veca, glm::vec3 &vecb);

	//���������ĵ��
	static float product(glm::vec3 &veca, glm::vec3 &vecb);

	//�������ĳ���
	static float distance(glm::vec3 &vec);

};

#endif