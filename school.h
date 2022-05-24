//===================================================
//
//授業その5[school.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _SCHOOL_H_
#define _SCHOOL_H_

#include "human.h"

//********************************
//学校クラスの定義
//********************************
class CSchool
{/* 基本クラス */
public:		/* 列挙型の定義 */
	enum class ACTION
	{/* 行動 */
		NONE = 0,
		CLASS,		//授業
		REST,		//休憩
		OUTPUT,		//出力
		FINISH,		//終了
		MAX
	};

public:		/* 定数の定義 */
	static const int MAX_HUMAN = 3;		//最大数
	static const int MIN_HUMAN = 1;		//最少数

public:		/* 静的メンバ関数 */
	static CSchool* Create();	//生成

public:		/* コンストラクタ・デストラクタ */
	CSchool();
	~CSchool();

public:		/* メンバ関数 */
	void Init();			//初期化
	ACTION SelectAction();	//行動を選択
	void Action();			//行動
	void Class();			//授業
	void Rest();			//休憩
	void Output();			//出力
	void Uninit();			//終了
private:
	void OutputNumAll();	//全ての人間の数を表示

private:	/* メンバ変数 */
	CHuman* m_apHuman[MAX_HUMAN];	//ポインタ配列
};

#endif