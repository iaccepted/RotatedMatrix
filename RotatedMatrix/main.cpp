#include "RotatedMatrix.h"


int main()
{
	RotatedMatrix *tool = RotatedMatrix::sharedInstance();

	glm::vec3 a(4, 3.2, 3), b(2.2, 1.9, 9);

	a = glm::normalize(a);
	b = glm::normalize(b);

	glm::mat3 res = tool->getRotatedMatrix(a, b);

	cout << "��ʼ������" << a.x << "  " << a.y << "  " << a.z << endl;
	cout << "Ŀ��������" << b.x << "  " << b.y << "  " << b.z << endl;

	glm::vec3 c = res * a;

	cout <<"��ת�����" << c.x << "  " << c.y << "  " << c.z << endl;
	return 0;
}