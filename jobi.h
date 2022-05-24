//===================================================
//
//授業その5[jobi.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _JOBI_H_
#define _JOBI_H_

#include "school.h"

//********************************
//学校クラスの定義
//********************************
class CJobi : public CSchool
{/* CSchoolの派生クラス */
public:		/* コンストラクタ・デストラクタ */
	CJobi();
	~CJobi()override;

public:		/* オーバーライド関数 */
	void Init()override;	//初期化
	void Class()override;	//授業
	void Rest()override;	//休憩
	void Output()override;	//出力
	void Uninit()override;	//終了

private:	/* メンバ関数 */
	void OutputNumAll();	//全ての人間の数を表示
};

#endif