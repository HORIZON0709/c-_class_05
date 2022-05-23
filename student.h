//===================================================
//
//授業その5[student.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "human.h"

//********************************
//生徒クラスの定義
//********************************
class CStudent : public CHuman
{/* CHumanの派生クラス */
public:		/* コンストラクタ・デストラクタ */
	CStudent();
	~CStudent()override;

public:		/* メンバ関数宣言 */
	void Init()override;	//初期化
	void Input()override;	//入力
	void Class()override;	//授業
	void Rest()override;	//休憩
	void Output()override;	//出力
	void Uninit()override;	//終了

private:	/* メンバ変数宣言 */
	int m_nAbility;		//学力
};

#endif