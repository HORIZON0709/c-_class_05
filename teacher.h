//===================================================
//
//授業その5[teacher.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _TEACHER_H_
#define _TEACHER_H_

#include "human.h"

//********************************
//先生クラスの定義
//********************************
class CTeacher : public CHuman
{/* CHumanの派生クラス */
public:		/* コンストラクタ・デストラクタ */
	CTeacher();
	~CTeacher()override;

public:		/* オーバーライド関数 */
	void Init()override;	//初期化
	void Input()override;	//入力
	void Class()override;	//授業
	void Rest()override;	//休憩
	void Output()override;	//出力
	void Uninit()override;	//終了

private:	/* メンバ変数 */
	int m_nTension;		//テンション
};

#endif