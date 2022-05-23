//===================================================
//
//授業その5[teacher.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//インクルード
//********************************
#include "teacher.h"

#include <stdio.h>
#include <stdlib.h>

//********************************
//静的メンバ変数
//********************************

//===================================================
//コンストラクタ
//===================================================
CTeacher::CTeacher() : CHuman(TYPE::TEACHER)
,m_nTension(0)
{
	
}

//===================================================
//デストラクタ
//===================================================
CTeacher::~CTeacher()
{
	/* 処理無し */
}

//===================================================
//初期化
//===================================================
void CTeacher::Init()
{
	//メンバ変数を初期化
	m_nTension = 0;
}

//===================================================
//終了
//===================================================
void CTeacher::Uninit()
{
	
}

//===================================================
//入力
//===================================================
void CTeacher::Input()
{
	//入力
	printf("\n 体力 > ");
	scanf("%d", &m_nLife);

	printf(" テンション > ");
	scanf("%d", &m_nTension);
}

//===================================================
//出力
//===================================================
void CTeacher::Output()
{
	printf("\n [ 体力 : %d ]", m_nLife);			//体力
	printf("\n [ テンション : %d ]", m_nTension);	//テンション
}