//===================================================
//
//���Ƃ���5[school.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _SCHOOL_H_
#define _SCHOOL_H_

#include "human.h"

//********************************
//�w�Z�N���X�̒�`
//********************************
class CSchool
{/* ��{�N���X */
public:		/* �񋓌^�̒�` */
	enum class ACTION
	{/* �s�� */
		NONE = 0,
		CLASS,		//����
		REST,		//�x�e
		OUTPUT,		//�o��
		FINISH,		//�I��
		MAX
	};

public:		/* �萔�̒�` */
	static const int MAX_HUMAN = 3;		//�ő吔
	static const int MIN_HUMAN = 1;		//�ŏ���

public:		/* �ÓI�����o�֐� */
	static CSchool* Create();	//����

public:		/* �R���X�g���N�^�E�f�X�g���N�^ */
	CSchool();
	~CSchool();

public:		/* �����o�֐� */
	void Init();			//������
	ACTION SelectAction();	//�s����I��
	void Action();			//�s��
	void Class();			//����
	void Rest();			//�x�e
	void Output();			//�o��
	void Uninit();			//�I��
private:
	void OutputNumAll();	//�S�Ă̐l�Ԃ̐���\��

private:	/* �����o�ϐ� */
	CHuman* m_apHuman[MAX_HUMAN];	//�|�C���^�z��
};

#endif