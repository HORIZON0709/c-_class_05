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
#include <string.h>
#include <assert.h>

//********************************
//静的メンバ変数
//********************************
int CHuman::m_nNumAll = 0;				//総数
int CHuman::m_nNumTeacher = 0;			//先生の数
int CHuman::m_nNumStudent = 0;			//生徒の数

//===================================================
//生成
//===================================================
CHuman* CHuman::Create(TYPE type)
{
	CHuman* pHuman = nullptr;	//ポインタ
	
	switch (type)
	{//種類毎の処理
	case TYPE::TEACHER:	/* 先生 */

		//メモリの動的確保
		pHuman = new CTeacher;
		break;

	case TYPE::STUDENT:	/* 生徒 */

		//メモリの動的確保
		pHuman = new CStudent;
		break;

	case TYPE::NONE:	/* 選択範囲外 */
	case TYPE::MAX:
	default:
		assert(false);
		break;
	}

	if (pHuman == nullptr)
	{//NULLチェック
		assert(false);
	}

	/* nullptrではない */

	//初期化
	pHuman->Init();

	return pHuman;	//動的確保したものを返す
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
	memset(&m_aName[0], 0, sizeof(m_aName));
	m_nLife = 0;

	//総数をカウントアップ
	m_nNumAll++;

	switch (type)
	{//タイプごとの処理
	case TYPE::TEACHER:	/* 先生 */
		
		//数をカウントアップ
		m_nNumTeacher++;
		break;

	case TYPE::STUDENT:	/* 生徒 */
		
		//数をカウントアップ
		m_nNumStudent++;
		break;

	case TYPE::NONE:	/* 選択範囲外 */
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