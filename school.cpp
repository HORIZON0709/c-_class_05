//===================================================
//
//授業その5[school.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//インクルード
//********************************
#include "school.h"
#include "human.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//静的メンバ変数
//********************************

//===================================================
//生成
//===================================================
CSchool* CSchool::Create()
{
	//動的確保
	CSchool* pSchool = new CSchool;

	return pSchool;		//動的確保したものを返す
}

//===================================================
//コンストラクタ
//===================================================
CSchool::CSchool()
{
	for (int i = 0; i < MAX_HUMAN; i++)
	{//メンバ変数をクリア
		m_apHuman[i] = nullptr;
	}
}

//===================================================
//デストラクタ
//===================================================
CSchool::~CSchool()
{
	/* 処理なし */
}

//===================================================
//行動を選択
//===================================================
CSchool::ACTION CSchool::SelectAction()
{
	ACTION action = ACTION::NONE;	//行動設定用

	while (1)
	{
		//メッセージ
		printf("\n 《 行動を選択 》");
		printf("\n [%d] 授業", ACTION::CLASS);
		printf("\n [%d] 休憩", ACTION::REST);
		printf("\n [%d] 出力", ACTION::OUTPUT);
		printf("\n [%d] 終了", ACTION::FINISH);
		printf("\n 番号を入力 > ");
		scanf("%d", &action);

		if ((action > ACTION::NONE) && (action < ACTION::MAX))
		{//範囲内
			break;
		}

		/* 範囲外 */

		//メッセージ & Enter入力待ち
		printf("\n ※※※ 範囲外です ※※※");
		PressEnter();

		//画面をクリア
		system("cls");
	}

	//画面をクリア
	system("cls");

	return action;	//設定した行動を返す
}

//===================================================
//行動
//===================================================
void CSchool::Action()
{
	bool bFinish = false;	//終了フラグ

	while (!bFinish)
	{
		//行動を選択
		ACTION action = SelectAction();

		switch (action)
		{
		case ACTION::CLASS:		/* 授業 */
			Class();
			break;

		case ACTION::REST:		/* 休憩 */
			Rest();
			break;

		case ACTION::OUTPUT:	/* 出力 */
			Output();
			break;

		case ACTION::FINISH:	/* 終了 */
			Uninit();
			bFinish = true;		//終了フラグを立てる
			break;

		case ACTION::NONE:
		case ACTION::MAX:
		default:
			assert(false);
			break;
		}

		if (!bFinish)
		{//終了時は通らない
			//Enter入力待ち
			PressEnter();

			//画面をクリア
			system("cls");
		}
	}
}

//===================================================
//初期化
//===================================================
void CSchool::Init()
{
	for (int i = 0; i < MAX_HUMAN; i++)
	{
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
void CSchool::Class()
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
void CSchool::Rest()
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
void CSchool::Output()
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
void CSchool::Uninit()
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
void CSchool::OutputNumAll()
{
	printf("\n\n 人間の総数 : [ %d ]", CHuman::GetNumAll());
	printf("\n 先生 : [ %d ]", CHuman::GetNumTeacher());
	printf("\n 生徒 : [ %d ]", CHuman::GetNumStudent());
}