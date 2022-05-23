//===================================================
//
//���Ƃ���5[teacher.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _TEACHER_H_
#define _TEACHER_H_

#include "human.h"

//********************************
//�搶�N���X�̒�`
//********************************
class CTeacher : public CHuman
{/* CHuman�̔h���N���X */
public:		/* �R���X�g���N�^�E�f�X�g���N�^ */
	CTeacher();
	~CTeacher()override;

public:		/* �����o�֐��錾 */
	void Init()override;	//������
	void Input()override;	//����
	void Class()override;	//����
	void Rest()override;	//�x�e
	void Output()override;	//�o��
	void Uninit()override;	//�I��

private:	/* �����o�ϐ��錾 */
	int m_nTension;		//�e���V����
};

#endif