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
#include "human.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//�񋓌^�̒�`
//********************************
namespace
{
enum class ACTION
{/* �s�� */
	NONE = 0,
	CLASS,		//����
	REST,		//�x�e
	OUTPUT,		//�o��
	FINISH,		//�I��
	MAX
};
}// namespace�͂����܂�

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
void Action();

void Output();
void Uninit();

int SetNumHuman();
CHuman::TYPE SelectType();
ACTION SelectAction();
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

	//�s��
	Action();

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
	//�S�Ă̐l�Ԃ̔j��
	CHuman::ReleaseAll();
}

//---------------------------------------------------
//����
//---------------------------------------------------
void Input()
{
	//�l�Ԃ̐���ݒ�
	int nNumHuman = SetNumHuman();

	for (int i = 0; i < nNumHuman; i++)
	{
		//���̖ڂ��\��
		printf("\n �s %d�̖� �t", (i + 1));

		//�G�̎�ނ�I��
		CHuman::TYPE type = SelectType();

		//�G�̐���
		CHuman* pHuman = CHuman::Create(type);

		if (pHuman == nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�ł͖����ꍇ */

		//����
		pHuman->Input();

		//��ʂ��N���A
		system("cls");
	}
}

//---------------------------------------------------
//�s��
//---------------------------------------------------
void Action()
{
	bool bFinish = false;	//�I���t���O

	while (!bFinish)
	{
		//�s����I��
		ACTION action = SelectAction();

		switch (action)
		{
		case ACTION::CLASS:		/* ���� */
			CHuman::ClassAll();
			break;

		case ACTION::REST:		/* �x�e */
			CHuman::RestAll();
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

//---------------------------------------------------
//�o��
//---------------------------------------------------
void Output()
{
	//�S�Ă̐l�Ԃ��o��
	CHuman::OutputAll();
}

//---------------------------------------------------
//�I��
//---------------------------------------------------
void Uninit()
{
	//�S�Ă̐l�Ԃ̔j��
	CHuman::ReleaseAll();
}

//---------------------------------------------------
//�l�Ԃ̐���ݒ�
//---------------------------------------------------
int SetNumHuman()
{
	int nNumHuman = 0;	//�l�Ԃ̐��ݒ�p

	while (1)
	{
		//���b�Z�[�W
		printf("\n �l�Ԃ̐���ݒ�( %d�`%d�̂܂� ) > ", CHuman::MIN_HUMAN, CHuman::MAX_HUMAN);
		scanf("%d", &nNumHuman);

		if ((nNumHuman >= CHuman::MIN_HUMAN) && (nNumHuman <= CHuman::MAX_HUMAN))
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

	return nNumHuman;	//�ݒ肵���l�Ԃ̐���Ԃ�
}

//---------------------------------------------------
//�l�Ԃ̎�ނ�I��
//---------------------------------------------------
CHuman::TYPE SelectType()
{
	CHuman::TYPE selectType;	//�l�Ԃ̎�ޑI��p

	while (1)
	{
		//���b�Z�[�W
		printf("\n �s �l�Ԃ̎�ނ�I�� �t");
		printf("\n [%d] �搶", CHuman::TYPE::TEACHER);
		printf("\n [%d] ���k", CHuman::TYPE::STUDENT);
		printf("\n �ԍ������ > ");
		scanf("%d", &selectType);

		if ((selectType > CHuman::TYPE::NONE) && (selectType < CHuman::TYPE::MAX))
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

	return selectType;	//�I�������l�Ԃ̎�ނ�Ԃ�
}

//---------------------------------------------------
//�s����I��
//---------------------------------------------------
ACTION SelectAction()
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
}