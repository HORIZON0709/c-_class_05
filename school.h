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
	static const int MAX_HUMAN = 4;		//�ő吔
	static const int MIN_HUMAN = 1;		//�ŏ���

public:		/* �ÓI�����o�֐� */
	static CSchool* Create();	//����

public:		/* �R���X�g���N�^�E�f�X�g���N�^ */
	CSchool();
	virtual~CSchool();

public:		/* ���z�֐� */
	virtual void Init() = 0;	//������
	virtual void Class() = 0;	//����
	virtual void Rest() = 0;	//�x�e
	virtual void Output() = 0;	//�o��
	virtual void Uninit() = 0;	//�I��

public:		/* �����o�֐� */
	void Action();			//�s��
private:
	ACTION SelectAction();	//�s����I��
	
protected:	/* �����o�ϐ� */
	CHuman* m_apHuman[MAX_HUMAN];	//�|�C���^�z��
};

#endif