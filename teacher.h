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

public:		/* �I�[�o�[���C�h�֐� */
	void Init()override;	//������
	void Input()override;	//����
	void Class()override;	//����
	void Rest()override;	//�x�e
	void Output()override;	//�o��
	void Uninit()override;	//�I��

private:	/* �����o�ϐ� */
	int m_nTension;		//�e���V����
};

#endif