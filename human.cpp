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
#include <string.h>
#include <assert.h>

//********************************
//�ÓI�����o�ϐ�
//********************************
int CHuman::m_nNumAll = 0;				//����
int CHuman::m_nNumTeacher = 0;			//�搶�̐�
int CHuman::m_nNumStudent = 0;			//���k�̐�

//===================================================
//����
//===================================================
CHuman* CHuman::Create(TYPE type)
{
	CHuman* pHuman = nullptr;	//�|�C���^
	
	switch (type)
	{//��ޖ��̏���
	case TYPE::TEACHER:	/* �搶 */

		//�������̓��I�m��
		pHuman = new CTeacher;
		break;

	case TYPE::STUDENT:	/* ���k */

		//�������̓��I�m��
		pHuman = new CStudent;
		break;

	case TYPE::NONE:	/* �I��͈͊O */
	case TYPE::MAX:
	default:
		assert(false);
		break;
	}

	if (pHuman == nullptr)
	{//NULL�`�F�b�N
		assert(false);
	}

	/* nullptr�ł͂Ȃ� */

	//������
	pHuman->Init();

	return pHuman;	//���I�m�ۂ������̂�Ԃ�
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
	memset(&m_aName[0], 0, sizeof(m_aName));
	m_nLife = 0;

	//�������J�E���g�A�b�v
	m_nNumAll++;

	switch (type)
	{//�^�C�v���Ƃ̏���
	case TYPE::TEACHER:	/* �搶 */
		
		//�����J�E���g�A�b�v
		m_nNumTeacher++;
		break;

	case TYPE::STUDENT:	/* ���k */
		
		//�����J�E���g�A�b�v
		m_nNumStudent++;
		break;

	case TYPE::NONE:	/* �I��͈͊O */
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