//===================================================
//
//���Ƃ���5[jobi.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _JOBI_H_
#define _JOBI_H_

#include "school.h"

//********************************
//�w�Z�N���X�̒�`
//********************************
class CJobi : public CSchool
{/* CSchool�̔h���N���X */
public:		/* �R���X�g���N�^�E�f�X�g���N�^ */
	CJobi();
	~CJobi()override;

public:		/* �I�[�o�[���C�h�֐� */
	void Init()override;	//������
	void Class()override;	//����
	void Rest()override;	//�x�e
	void Output()override;	//�o��
	void Uninit()override;	//�I��

private:	/* �����o�֐� */
	void OutputNumAll();	//�S�Ă̐l�Ԃ̐���\��
};

#endif