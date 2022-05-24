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
#include "human.h"
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
	CSchool* pSchool = new CSchool;

	return pSchool;		//���I�m�ۂ������̂�Ԃ�
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
//������
//===================================================
void CSchool::Init()
{
	for (int i = 0; i < MAX_HUMAN; i++)
	{
		if (i == 0)
		{//�ŏ��̈�l
			m_apHuman[i] = CHuman::Create(CHuman::TYPE::TEACHER);	//�搶�𐶐�
			continue;
		}

		/* �搶�𐶐������� */

		//���k�𐶐�
		m_apHuman[i] = CHuman::Create(CHuman::TYPE::STUDENT);
	}
}

//===================================================
//����
//===================================================
void CSchool::Class()
{
	for (int i = 0; i < CHuman::GetNumAll(); i++)
	{
		if (m_apHuman[i] == nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�ł͖����ꍇ */

		//����
		m_apHuman[i]->Class();
	}
}

//===================================================
//�x�e
//===================================================
void CSchool::Rest()
{
	for (int i = 0; i < CHuman::GetNumAll(); i++)
	{
		if (m_apHuman[i] == nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�ł͖����ꍇ */

		//�x�e
		m_apHuman[i]->Rest();
	}
}

//===================================================
//�o��
//===================================================
void CSchool::Output()
{
	//���b�Z�[�W
	printf("\n �s �ݒ肵���l�Ԃ̃X�e�[�^�X�͂����� �t");

	for (int i = 0; i < CHuman::GetNumAll(); i++)
	{
		if (m_apHuman[i] == nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�ł͖����ꍇ */

		//���̖ڂ��\��
		printf("\n\n ***** %d�l�� *****", (i + 1));

		//�o��
		m_apHuman[i]->Output();
	}

	//�S�Ă̐l�Ԃ̐���\��
	OutputNumAll();
}

//===================================================
//�I��
//===================================================
void CSchool::Uninit()
{
	for (int i = 0; i < CHuman::GetNumAll(); i++)
	{
		if (m_apHuman[i] == nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�ł͂Ȃ��ꍇ */

		//�I��
		m_apHuman[i]->Uninit();

		//�������̉��
		delete m_apHuman[i];
		m_apHuman[i] = nullptr;
	}
}

//===================================================
//�S�Ă̐l�Ԃ̐���\��
//===================================================
void CSchool::OutputNumAll()
{
	printf("\n\n �l�Ԃ̑��� : [ %d ]", CHuman::GetNumAll());
	printf("\n �搶 : [ %d ]", CHuman::GetNumTeacher());
	printf("\n ���k : [ %d ]", CHuman::GetNumStudent());
}