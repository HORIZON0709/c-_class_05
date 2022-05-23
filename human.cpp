//===================================================
//
//���Ƃ���5[human.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//�C���N���[�h
//********************************
#include "human.h"
#include "teacher.h"
#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//�ÓI�����o�ϐ�
//********************************
CHuman* CHuman::m_apHuman[MAX_HUMAN] = {};	//�|�C���^

int CHuman::m_nNumAll = 0;		//����
int CHuman::m_nNumTeacher = 0;	//�搶�̐�
int CHuman::m_nNumStudent = 0;	//���k�̐�

//===================================================
//����
//===================================================
CHuman* CHuman::Create(TYPE type)
{
	int nIdx = m_nNumAll;	//�C���f�b�N�X���p

	switch (type)
	{//��ޖ��̏���
	case TYPE::TEACHER:	/* �搶 */

		//�������̓��I�m��
		m_apHuman[nIdx] = new CTeacher;
		break;

	case TYPE::STUDENT:	/* ���k */

		//�������̓��I�m��
		m_apHuman[nIdx] = new CStudent;
		break;

	case TYPE::NONE:	/* �I��͈͊O */
	case TYPE::MAX:
	default:
		assert(false);
		break;
	}

	if (m_apHuman[nIdx] == nullptr)
	{//NULL�`�F�b�N
		assert(false);
	}

	/* nullptr�ł͂Ȃ� */

	//������
	m_apHuman[nIdx]->Init();

	return m_apHuman[nIdx];	//���I�m�ۂ������̂�Ԃ�
}

//===================================================
//�S�Ă̓G�̔j��
//===================================================
void CHuman::ReleaseAll()
{
	for (int i = 0; i < MAX_HUMAN; i++)
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
//�S�Ă̓G���o��
//===================================================
void CHuman::OutputAll()
{
	//���b�Z�[�W
	printf("\n �s �ݒ肵���l�Ԃ̃X�e�[�^�X�͂����� �t");

	for (int i = 0; i < m_nNumAll; i++)
	{
		if (m_apHuman[i] == nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�ł͖����ꍇ */

		//���̖ڂ��\��
		printf("\n\n ***** %d�l�� *****",(i + 1));

		//�o��
		m_apHuman[i]->Output();
	}

	//����\��
	OutputNum();
}

//===================================================
//�������擾
//===================================================
int CHuman::GetNumAll()
{
	return m_nNumAll;
}

//===================================================
//�l�^�̐����擾
//===================================================
int CHuman::GetNumTeacher()
{
	return m_nNumTeacher;
}

//===================================================
//���^�̐����擾
//===================================================
int CHuman::GetNumStudent()
{
	return m_nNumStudent;
}

//===================================================
//�G�̐���\��
//===================================================
void CHuman::OutputNum()
{
	printf("\n\n �l�Ԃ̑��� : [ %d ]", GetNumAll());
	printf("\n �搶 : [ %d ]", GetNumTeacher());
	printf("\n ���k : [ %d ]", GetNumStudent());
}

//===================================================
//�f�t�H���g�R���X�g���N�^
//===================================================
CHuman::CHuman()
{
	
}

//===================================================
//�I�[�o�[���[�h���ꂽ�R���X�g���N�^
//===================================================
CHuman::CHuman(TYPE type)
{
	//�����o�ϐ����N���A
	for (int i = 0; i < MAX_NAME; i++)
	{
		m_aName[i] = NULL;
	}
	
	m_nLife = 0;

	//�������J�E���g�A�b�v
	m_nNumAll++;

	switch (type)
	{
	case TYPE::TEACHER:	/* �搶 */
		
		//�����J�E���g�A�b�v
		m_nNumTeacher++;
		break;

	case TYPE::STUDENT:	/* ���k */
		
		//�����J�E���g�A�b�v
		m_nNumStudent++;
		break;

	case TYPE::NONE:	/* �͈͑I���O */
	case TYPE::MAX:
	default:
		assert(false);
		break;
	}
}

//===================================================
//�f�X�g���N�^
//===================================================
CHuman::~CHuman()
{
	/* �������� */
}