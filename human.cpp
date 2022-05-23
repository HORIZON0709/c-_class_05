//===================================================
//
//授業その5[human.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//インクルード
//********************************
#include "human.h"
#include "teacher.h"
#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//静的メンバ変数
//********************************
CHuman* CHuman::m_apHuman[MAX_HUMAN] = {};	//ポインタ

int CHuman::m_nNumAll = 0;		//総数
int CHuman::m_nNumTeacher = 0;	//先生の数
int CHuman::m_nNumStudent = 0;	//生徒の数

//===================================================
//生成
//===================================================
CHuman* CHuman::Create(TYPE type)
{
	int nIdx = m_nNumAll;	//インデックス数用

	switch (type)
	{//種類毎の処理
	case TYPE::TEACHER:	/* 先生 */

		//メモリの動的確保
		m_apHuman[nIdx] = new CTeacher;
		break;

	case TYPE::STUDENT:	/* 生徒 */

		//メモリの動的確保
		m_apHuman[nIdx] = new CStudent;
		break;

	case TYPE::NONE:	/* 選択範囲外 */
	case TYPE::MAX:
	default:
		assert(false);
		break;
	}

	if (m_apHuman[nIdx] == nullptr)
	{//NULLチェック
		assert(false);
	}

	/* nullptrではない */

	//初期化
	m_apHuman[nIdx]->Init();

	return m_apHuman[nIdx];	//動的確保したものを返す
}

//===================================================
//全ての敵の破棄
//===================================================
void CHuman::ReleaseAll()
{
	for (int i = 0; i < MAX_HUMAN; i++)
	{
		if (m_apHuman[i] == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrではない場合 */

		//終了
		m_apHuman[i]->Uninit();

		//メモリの解放
		delete m_apHuman[i];
		m_apHuman[i] = nullptr;
	}
}

//===================================================
//全ての敵を出力
//===================================================
void CHuman::OutputAll()
{
	//メッセージ
	printf("\n 《 設定した人間のステータスはこちら 》");

	for (int i = 0; i < m_nNumAll; i++)
	{
		if (m_apHuman[i] == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrでは無い場合 */

		//何体目か表示
		printf("\n\n ***** %d人目 *****",(i + 1));

		//出力
		m_apHuman[i]->Output();
	}

	//数を表示
	OutputNum();
}

//===================================================
//総数を取得
//===================================================
int CHuman::GetNumAll()
{
	return m_nNumAll;
}

//===================================================
//人型の数を取得
//===================================================
int CHuman::GetNumTeacher()
{
	return m_nNumTeacher;
}

//===================================================
//鳥型の数を取得
//===================================================
int CHuman::GetNumStudent()
{
	return m_nNumStudent;
}

//===================================================
//敵の数を表示
//===================================================
void CHuman::OutputNum()
{
	printf("\n\n 人間の総数 : [ %d ]", GetNumAll());
	printf("\n 先生 : [ %d ]", GetNumTeacher());
	printf("\n 生徒 : [ %d ]", GetNumStudent());
}

//===================================================
//デフォルトコンストラクタ
//===================================================
CHuman::CHuman()
{
	
}

//===================================================
//オーバーロードされたコンストラクタ
//===================================================
CHuman::CHuman(TYPE type)
{
	//メンバ変数をクリア
	for (int i = 0; i < MAX_NAME; i++)
	{
		m_aName[i] = NULL;
	}
	
	m_nLife = 0;

	//総数をカウントアップ
	m_nNumAll++;

	switch (type)
	{
	case TYPE::TEACHER:	/* 先生 */
		
		//数をカウントアップ
		m_nNumTeacher++;
		break;

	case TYPE::STUDENT:	/* 生徒 */
		
		//数をカウントアップ
		m_nNumStudent++;
		break;

	case TYPE::NONE:	/* 範囲選択外 */
	case TYPE::MAX:
	default:
		assert(false);
		break;
	}
}

//===================================================
//デストラクタ
//===================================================
CHuman::~CHuman()
{
	/* 処理無し */
}