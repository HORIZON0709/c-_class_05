//===================================================
//
//���Ƃ���5[human.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _HUMAN_H_
#define _HUMAN_H_

//********************************
//�l�ԃN���X�̒�`
//********************************
class CHuman
{/* ��{�N���X */
public:		/* �񋓌^�̒�` */
	enum class TYPE
	{//���
		NONE = 0,
		TEACHER,	//�搶
		STUDENT,	//���k
		MAX,
	};

public:		/* �萔�̒�` */
	static const int MAX_HUMAN = 5;		//�ő吔
	static const int MIN_HUMAN = 1;		//�ŏ���
	static const int MAX_NAME = 256;	//���O�̍ő啶����

public:		/* �ÓI�����o�֐��錾 */
	static CHuman* Create(TYPE type);	//����
	static void ReleaseAll();			//�S�Ă̐l�Ԃ̔j��
	static void OutputAll();			//�S�Ă̐l�Ԃ��o��
public:	/* Get�n */
	static int GetNumAll();		//�������擾
	static int GetNumTeacher();	//�搶�̐����擾
	static int GetNumStudent();	//���k�̐����擾
private:
	static void OutputNum();	//���̕\��

public:		/* �R���X�g���N�^�E�f�X�g���N�^ */
	CHuman();
	CHuman(TYPE type);
	virtual ~CHuman();

public:		/* ���z�֐��錾 */
	virtual void Init() = 0;	//������ (�������z�֐��u�` = 0;�v�c�֐��̎��Ԃ͕s�v)
	virtual void Input() = 0;	//����
	virtual void Class() = 0;	//����
	virtual void Rest() = 0;	//�x�e
	virtual void Output() = 0;	//�o��
	virtual void Uninit() = 0;	//�I��

private:	/* �ÓI�����o�ϐ��錾 */
	static CHuman* m_apHuman[MAX_HUMAN];	//�|�C���^�z��
	static int m_nNumAll;					//����
	static int m_nNumTeacher;				//�搶�̐�
	static int m_nNumStudent;				//���k�̐�

protected:	/* �����o�ϐ��錾 */
	char m_aName[MAX_NAME];		//���O
	int m_nLife;				//�̗�
};

#endif