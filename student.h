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

public:		/* メンバー関数宣言 */
	void Init()override;	//初期化
	void Uninit()override;	//終了
	void Input()override;	//入力
	void Output()override;	//出力

private:	/* メンバー変数宣言 */
	int m_nAbility;		//学力
};

#endif