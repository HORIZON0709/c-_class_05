//===================================================
//
//���Ƃ���5[student.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "human.h"

//********************************
//���k�N���X�̒�`
//********************************
class CStudent : public CHuman
{/* CHuman�̔h���N���X */
public:		/* �R���X�g���N�^�E�f�X�g���N�^ */
	CStudent();
	~CStudent()override;

public:		/* �����o�֐��錾 */
	void Init()override;	//������
	void Input()override;	//����
	void Class()override;	//����
	void Rest()override;	//�x�e
	void Output()override;	//�o��
	void Uninit()override;	//�I��

private:	/* �����o�ϐ��錾 */
	int m_nAbility;		//�w��
};

#endif