#include "RotatedMatrix.h"

RotatedMatrix *RotatedMatrix::sharedInstance()
{
	if (rotatedMatrix == NULL)
	{
		rotatedMatrix = new RotatedMatrix();
	}
	return rotatedMatrix;
}

glm::mat3 RotatedMatrix::getRotatedMatrix(glm::vec3 &veca, glm::vec3 &vecb)
{
	//求出旋转轴
	glm::vec3 axis = glm::cross(veca, vecb);

	//求出旋转角
	float angle = acos(product(veca, vecb));

	axis = glm::normalize(axis);

	//rotated Matrix
	glm::mat3 res = glm::mat3(0);
	float cv = cos(angle), sv = sin(angle);

	/*res[0][0] = cv + axis[0] * axis[0] * (1.0f - cv);
	res[0][1] = axis[0] * axis[1] * (1.0f - cv) - axis[2] * sv;
	res[0][2] = axis[1] * sv + axis[0] * axis[2] * (1.0f - cv);

	res[1][0] = axis[2] * sv + axis[0] * axis[1] * (1.0f - cv);
	res[1][1] = cv + axis[1] * axis[1] * (1 - cv);
	res[1][2] = -axis[0] * sv + axis[1] * axis[2] * (1.0f - cv);

	res[2][0] = -axis[1] * sv + axis[0] * axis[2] * (1.0f - cv);
	res[2][1] = axis[0] * sv + axis[1] * axis[2] * (1.0f - cv);
	res[2][2] = cv + axis[2] * axis[2] * (1.0f - cos(angle));*/

	res[0][0] = cv + axis[0] * axis[0] * (1.0f - cv);
	res[1][0] = axis[0] * axis[1] * (1.0f - cv) - axis[2] * sv;
	res[2][0] = axis[1] * sv + axis[0] * axis[2] * (1.0f - cv);

	res[0][1] = axis[2] * sv + axis[0] * axis[1] * (1.0f - cv);
	res[1][1] = cv + axis[1] * axis[1] * (1 - cv);
	res[2][1] = -axis[0] * sv + axis[1] * axis[2] * (1.0f - cv);

	res[0][2] = -axis[1] * sv + axis[0] * axis[2] * (1.0f - cv);
	res[1][2] = axis[0] * sv + axis[1] * axis[2] * (1.0f - cv);
	res[2][2] = cv + axis[2] * axis[2] * (1.0f - cos(angle));

	return res;
}

float RotatedMatrix::product(glm::vec3 &veca, glm::vec3 &vecb)
{
	return (veca.x * vecb.x + veca.y * vecb.y + veca.z * vecb.z);
}

float RotatedMatrix::distance(glm::vec3 &vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
