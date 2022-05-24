//===================================================
//
//���Ƃ���5[jobi.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//�C���N���[�h
//********************************
#include "jobi.h"
#include "human.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//�ÓI�����o�ϐ�
//********************************

//===================================================
//�R���X�g���N�^
//===================================================
CJobi::CJobi()
{
	
}

//===================================================
//�f�X�g���N�^
//===================================================
CJobi::~CJobi()
{
	/* �����Ȃ� */
}

//===================================================
//������
//===================================================
void CJobi::Init()
{
	for (int i = 0; i < MAX_HUMAN; i++)
	{
		if (m_apHuman[i] != nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�̏ꍇ */

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
void CJobi::Class()
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
void CJobi::Rest()
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
void CJobi::Output()
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
void CJobi::Uninit()
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
void CJobi::OutputNumAll()
{
	printf("\n\n �l�Ԃ̑��� : [ %d ]", CHuman::GetNumAll());
	printf("\n �搶 : [ %d ]", CHuman::GetNumTeacher());
	printf("\n ���k : [ %d ]", CHuman::GetNumStudent());
}