//===================================================
//
//���Ƃ���5[main.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//�C���N���[�h
//********************************
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//�萔�̒�`
//********************************
namespace
{

}// namespace�͂����܂�

//********************************
//�X�^�e�B�b�N�ϐ�
//********************************
namespace
{

}// namespace�͂����܂�

//********************************
//�v���g�^�C�v�錾
//********************************
namespace
{
void Init();
void Input();
void Output();
void Uninit();

}// namespace�͂����܂�

//===================================================
//���C���֐�
//===================================================
void main(void)
{
	//������
	Init();
	
	//����
	Input();

	//�o��
	Output();

	//�I��
	Uninit();

	//�I�����b�Z�[�W & Enter���͑҂�
	printf("\n\n �v���O�������I�����܂��B�����l�ł����B");
	PressEnter();
}

//===================================================
//Enter���͑҂�
//===================================================
void PressEnter()
{
	//Enter���͑҂�
	printf("\n\n Press Enter");
	rewind(stdin);
	getchar();
}

namespace
{
//---------------------------------------------------
//������
//---------------------------------------------------
void Init()
{
	
}

//---------------------------------------------------
//����
//---------------------------------------------------
void Input()
{
	//�G�̐���ݒ�
	int nNumEnemy = SetNumEnemy();

	for (int i = 0; i < nNumEnemy; i++)
	{
		//���̖ڂ��\��
		printf("\n �s %d�̖� �t", (i + 1));

		//�G�̎�ނ�I��
		CEnemy::TYPE type = SelectType();

		//�G�̐���
		CEnemy* pEnemy = CEnemy::Create(type);

		if (pEnemy == nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�ł͖����ꍇ */

		//����
		pEnemy->Input();

		//��ʂ��N���A
		system("cls");
	}
}

//---------------------------------------------------
//�o��
//---------------------------------------------------
void Output()
{
	
}

//---------------------------------------------------
//�I��
//---------------------------------------------------
void Uninit()
{
	
}

//---------------------------------------------------
//�G�̐���ݒ�
//---------------------------------------------------
int SetNumEnemy()
{
	int nNumEnemy = 0;	//�G�̐��ݒ�p

	while (1)
	{
		//���b�Z�[�W
		printf("\n �G�̐���ݒ�( %d�`%d�̂܂� ) > ", CEnemy::MIN_ENEMY, CEnemy::MAX_ENEMY);
		scanf("%d", &nNumEnemy);

		if ((nNumEnemy >= CEnemy::MIN_ENEMY) && (nNumEnemy <= CEnemy::MAX_ENEMY))
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

	return nNumEnemy;	//�ݒ肵���G�̐���Ԃ�
}

//---------------------------------------------------
//�G�̎�ނ�I��
//---------------------------------------------------
CEnemy::TYPE SelectType()
{
	CEnemy::TYPE selectType;	//�G�̎�ޑI��p

	while (1)
	{
		//���b�Z�[�W
		printf("\n �s �G�̎�ނ�I�� �t");
		printf("\n [%d] �l�^", CEnemy::TYPE::HUMAN);
		printf("\n [%d] ���^", CEnemy::TYPE::BIRD);
		printf("\n �ԍ������ > ");
		scanf("%d", &selectType);

		if ((selectType > CEnemy::TYPE::NONE) && (selectType < CEnemy::TYPE::MAX))
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

	return selectType;	//�I�������G�̎�ނ�Ԃ�
}
}