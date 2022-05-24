//===================================================
//
//授業その5[jobi.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//インクルード
//********************************
#include "jobi.h"
#include "human.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//静的メンバ変数
//********************************

//===================================================
//コンストラクタ
//===================================================
CJobi::CJobi()
{
	
}

//===================================================
//デストラクタ
//===================================================
CJobi::~CJobi()
{
	/* 処理なし */
}

//===================================================
//初期化
//===================================================
void CJobi::Init()
{
	for (int i = 0; i < MAX_HUMAN; i++)
	{
		if (m_apHuman[i] != nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrの場合 */

		if (i == 0)
		{//最初の一人
			m_apHuman[i] = CHuman::Create(CHuman::TYPE::TEACHER);	//先生を生成
			continue;
		}

		/* 先生を生成した後 */

		//生徒を生成
		m_apHuman[i] = CHuman::Create(CHuman::TYPE::STUDENT);
	}
}

//===================================================
//授業
//===================================================
void CJobi::Class()
{
	for (int i = 0; i < CHuman::GetNumAll(); i++)
	{
		if (m_apHuman[i] == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrでは無い場合 */

		//授業
		m_apHuman[i]->Class();
	}
}

//===================================================
//休憩
//===================================================
void CJobi::Rest()
{
	for (int i = 0; i < CHuman::GetNumAll(); i++)
	{
		if (m_apHuman[i] == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrでは無い場合 */

		//休憩
		m_apHuman[i]->Rest();
	}
}

//===================================================
//出力
//===================================================
void CJobi::Output()
{
	//メッセージ
	printf("\n 《 設定した人間のステータスはこちら 》");

	for (int i = 0; i < CHuman::GetNumAll(); i++)
	{
		if (m_apHuman[i] == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrでは無い場合 */

		//何体目か表示
		printf("\n\n ***** %d人目 *****", (i + 1));

		//出力
		m_apHuman[i]->Output();
	}

	//全ての人間の数を表示
	OutputNumAll();
}

//===================================================
//終了
//===================================================
void CJobi::Uninit()
{
	for (int i = 0; i < CHuman::GetNumAll(); i++)
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
//全ての人間の数を表示
//===================================================
void CJobi::OutputNumAll()
{
	printf("\n\n 人間の総数 : [ %d ]", CHuman::GetNumAll());
	printf("\n 先生 : [ %d ]", CHuman::GetNumTeacher());
	printf("\n 生徒 : [ %d ]", CHuman::GetNumStudent());
}