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

public:		/* �����o�[�֐��錾 */
	void Init()override;	//������
	void Uninit()override;	//�I��
	void Input()override;	//����
	void Output()override;	//�o��

private:	/* �����o�[�ϐ��錾 */
	int m_nTension;		//�e���V����
};

#endif