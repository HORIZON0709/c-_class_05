//===================================================
//
//授業その5[human.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _HUMAN_H_
#define _HUMAN_H_

//********************************
//人間クラスの定義
//********************************
class CHuman
{/* 基本クラス */
public:		/* 列挙型の定義 */
	enum class TYPE
	{//種類
		NONE = 0,
		TEACHER,	//先生
		STUDENT,	//生徒
		MAX,
	};

public:		/* 定数の定義 */
	static const int MAX_NAME = 256;	//名前の最大文字数

public:		/* 静的メンバ関数 */
	static CHuman* Create(TYPE type);	//生成
public:	/* Get系 */
	static int GetNumAll();		//総数を取得
	static int GetNumTeacher();	//先生の数を取得
	static int GetNumStudent();	//生徒の数を取得

public:		/* コンストラクタ・デストラクタ */
	CHuman();
	CHuman(TYPE type);
	virtual ~CHuman();

public:		/* 仮想関数 */
	virtual void Init() = 0;	//初期化 (純粋仮想関数「～ = 0;」…関数の実態は不要)
	virtual void Class() = 0;	//授業
	virtual void Rest() = 0;	//休憩
	virtual void Output() = 0;	//出力
	virtual void Uninit() = 0;	//終了

private:	/* 静的メンバ変数 */
	static int m_nNumAll;					//総数
	static int m_nNumTeacher;				//先生の数
	static int m_nNumStudent;				//生徒の数

protected:	/* メンバ変数 */
	char m_aName[MAX_NAME];		//名前
	int m_nLife;				//体力
};

#endif