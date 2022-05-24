//===================================================
//
//���Ƃ���5[school.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//�C���N���[�h
//********************************
#include "school.h"
#include "jobi.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//�ÓI�����o�ϐ�
//********************************

//===================================================
//����
//===================================================
CSchool* CSchool::Create()
{
	//���I�m��
	CSchool* pSchool = new CJobi;

	return pSchool;		//���I�m�ۂ������̂�Ԃ�f
}

//===================================================
//�R���X�g���N�^
//===================================================
CSchool::CSchool()
{
	for (int i = 0; i < MAX_HUMAN; i++)
	{//�����o�ϐ����N���A
		m_apHuman[i] = nullptr;
	}
}

//===================================================
//�f�X�g���N�^
//===================================================
CSchool::~CSchool()
{
	/* �����Ȃ� */
}

//===================================================
//�s��
//===================================================
void CSchool::Action()
{
	bool bFinish = false;	//�I���t���O

	while (!bFinish)
	{
		//�s����I��
		ACTION action = SelectAction();

		switch (action)
		{
		case ACTION::CLASS:		/* ���� */
			Class();
			break;

		case ACTION::REST:		/* �x�e */
			Rest();
			break;

		case ACTION::OUTPUT:	/* �o�� */
			Output();
			break;

		case ACTION::FINISH:	/* �I�� */
			Uninit();
			bFinish = true;		//�I���t���O�𗧂Ă�
			break;

		case ACTION::NONE:
		case ACTION::MAX:
		default:
			assert(false);
			break;
		}

		if (!bFinish)
		{//�I�����͒ʂ�Ȃ�
			//Enter���͑҂�
			PressEnter();

			//��ʂ��N���A
			system("cls");
		}
	}
}

//===================================================
//�s����I��
//===================================================
CSchool::ACTION CSchool::SelectAction()
{
	ACTION action = ACTION::NONE;	//�s���ݒ�p

	while (1)
	{
		//���b�Z�[�W
		printf("\n �s �s����I�� �t");
		printf("\n [%d] ����", ACTION::CLASS);
		printf("\n [%d] �x�e", ACTION::REST);
		printf("\n [%d] �o��", ACTION::OUTPUT);
		printf("\n [%d] �I��", ACTION::FINISH);
		printf("\n �ԍ������ > ");
		scanf("%d", &action);

		if ((action > ACTION::NONE) && (action < ACTION::MAX))
		{//�͈͓�
			break;
		}

		/* �͈͊O */

		//���b�Z�[�W & Enter���͑҂�
		printf("\n ������ �͈͊O�ł� ������");
		PressEnter();

		//��ʂ��N���A
		system("cls");
	}

	//��ʂ��N���A
	system("cls");

	return action;	//�ݒ肵���s����Ԃ�
}