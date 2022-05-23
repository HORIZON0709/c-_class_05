//===================================================
//
//授業その5[main.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//インクルード
//********************************
#include "main.h"
#include "human.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//列挙型の定義
//********************************
namespace
{
enum class ACTION
{/* 行動 */
	NONE = 0,
	CLASS,		//授業
	REST,		//休憩
	OUTPUT,		//出力
	FINISH,		//終了
	MAX
};
}// namespaceはここまで

//********************************
//定数の定義
//********************************
namespace
{

}// namespaceはここまで

//********************************
//スタティック変数
//********************************
namespace
{

}// namespaceはここまで

//********************************
//プロトタイプ宣言
//********************************
namespace
{
void Init();
void Input();
void Action();

void Output();
void Uninit();

int SetNumHuman();
CHuman::TYPE SelectType();
ACTION SelectAction();
}// namespaceはここまで

//===================================================
//メイン関数
//===================================================
void main(void)
{
	//初期化
	Init();
	
	//入力
	Input();

	//行動
	Action();

	//終了メッセージ & Enter入力待ち
	printf("\n\n プログラムを終了します。お疲れ様でした。");
	PressEnter();
}

//===================================================
//Enter入力待ち
//===================================================
void PressEnter()
{
	//Enter入力待ち
	printf("\n\n Press Enter");
	rewind(stdin);
	getchar();
}

namespace
{
//---------------------------------------------------
//初期化
//---------------------------------------------------
void Init()
{
	//全ての人間の破棄
	CHuman::ReleaseAll();
}

//---------------------------------------------------
//入力
//---------------------------------------------------
void Input()
{
	//人間の数を設定
	int nNumHuman = SetNumHuman();

	for (int i = 0; i < nNumHuman; i++)
	{
		//何体目か表示
		printf("\n 《 %d体目 》", (i + 1));

		//敵の種類を選択
		CHuman::TYPE type = SelectType();

		//敵の生成
		CHuman* pHuman = CHuman::Create(type);

		if (pHuman == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrでは無い場合 */

		//入力
		pHuman->Input();

		//画面をクリア
		system("cls");
	}
}

//---------------------------------------------------
//行動
//---------------------------------------------------
void Action()
{
	bool bFinish = false;	//終了フラグ

	while (!bFinish)
	{
		//行動を選択
		ACTION action = SelectAction();

		switch (action)
		{
		case ACTION::CLASS:		/* 授業 */
			CHuman::ClassAll();
			break;

		case ACTION::REST:		/* 休憩 */
			CHuman::RestAll();
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

//---------------------------------------------------
//出力
//---------------------------------------------------
void Output()
{
	//全ての人間を出力
	CHuman::OutputAll();
}

//---------------------------------------------------
//終了
//---------------------------------------------------
void Uninit()
{
	//全ての人間の破棄
	CHuman::ReleaseAll();
}

//---------------------------------------------------
//人間の数を設定
//---------------------------------------------------
int SetNumHuman()
{
	int nNumHuman = 0;	//人間の数設定用

	while (1)
	{
		//メッセージ
		printf("\n 人間の数を設定( %d～%d体まで ) > ", CHuman::MIN_HUMAN, CHuman::MAX_HUMAN);
		scanf("%d", &nNumHuman);

		if ((nNumHuman >= CHuman::MIN_HUMAN) && (nNumHuman <= CHuman::MAX_HUMAN))
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

	return nNumHuman;	//設定した人間の数を返す
}

//---------------------------------------------------
//人間の種類を選択
//---------------------------------------------------
CHuman::TYPE SelectType()
{
	CHuman::TYPE selectType;	//人間の種類選択用

	while (1)
	{
		//メッセージ
		printf("\n 《 人間の種類を選択 》");
		printf("\n [%d] 先生", CHuman::TYPE::TEACHER);
		printf("\n [%d] 生徒", CHuman::TYPE::STUDENT);
		printf("\n 番号を入力 > ");
		scanf("%d", &selectType);

		if ((selectType > CHuman::TYPE::NONE) && (selectType < CHuman::TYPE::MAX))
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

	return selectType;	//選択した人間の種類を返す
}

//---------------------------------------------------
//行動を選択
//---------------------------------------------------
ACTION SelectAction()
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
}