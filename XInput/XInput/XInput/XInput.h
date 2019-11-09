#ifndef XINPUT_H
#define XINPUT_H

#include <Windows.h>
#include <crtdbg.h>
#include <Xinput.h>
#include <vector>
#include <memory>

#pragma comment( lib, "xinput.lib" )

static const int IDLE_THUMB_MAX		=  10000;	// スティックの遊び.
static const int IDLE_THUMB_MIN		= -10000;	// スティックの遊び.
static const int IDLE_TIGGER_MAX	=  100;		// トリガーボタンの遊び.

/////////////////////////////////////////////////
//	Xinput :　コントローラークラス.
//　　　　　シングルトンとして使用.
//////
class CXInput
{
	const int CONTROTLLERS_MAX = 4;	// 接続コントローラの最大数.
public:
	CXInput();
	~CXInput();

	// コントローラーの状態を更新.
	static void StatsUpdate();

	// コントローラーの接続数取得.
	static int GetConnectCount(){ return GetInstance()->m_ConnectedCount; }
	
	// A ボタン.
	// connectNum : 使用したいコントローラーの指定.
	static bool A_Button( const int& connectNum = 0 );
	// B ボタン.
	// connectNum : 使用したいコントローラーの指定.
	static bool B_Button( const int& connectNum = 0 );
	// X ボタン.
	// connectNum : 使用したいコントローラーの指定.
	static bool X_Button( const int& connectNum = 0 );
	// Y ボタン.
	// connectNum : 使用したいコントローラーの指定.
	static bool Y_Button( const int& connectNum = 0 );

	// 方向キー : UP.
	// connectNum : 使用したいコントローラーの指定.
	// isKeyinput : キーボードの方向キーを使用するかどうか.
	static bool DPadUp( const int& connectNum = 0, const bool& isKeyinput = false );
	// 方向キー : DOWN.
	// connectNum : 使用したいコントローラーの指定.
	// isKeyinput : キーボードの方向キーを使用するかどうか.
	static bool DPadDown( const int& connectNum = 0, const bool& isKeyinput = false );
	// 方向キー : LEFT.
	// connectNum : 使用したいコントローラーの指定.
	// isKeyinput : キーボードの方向キーを使用するかどうか.
	static bool DPadLEFT( const int& connectNum = 0, const bool& isKeyinput = false );
	// 方向キー : RIGHT.
	// connectNum : 使用したいコントローラーの指定.
	// isKeyinput : キーボードの方向キーを使用するかどうか.
	static bool DPadRIGHT( const int& connectNum = 0, const bool& isKeyinput = false );

	// L スティック : X軸.
	// connectNum : 使用したいコントローラーの指定.
	static SHORT LThumbX_Axis( const int& connectNum = 0 );
	// L スティック : Y軸.
	// connectNum : 使用したいコントローラーの指定.
	static SHORT LThumbY_Axis( const int& connectNum = 0 );

	// R スティック : X軸.
	// connectNum : 使用したいコントローラーの指定.
	static SHORT RThumbX_Axis( const int& connectNum = 0 );
	// R スティック : Y軸.
	// connectNum : 使用したいコントローラーの指定.
	static SHORT RThumbY_Axis( const int& connectNum = 0 );

	// L スティックボタン.
	// connectNum : 使用したいコントローラーの指定.
	static bool LThumb_Button( const int& connectNum = 0 );
	// R スティックボタン.
	// connectNum : 使用したいコントローラーの指定.
	static bool RThumb_Button( const int& connectNum = 0 );

	// L トリガー.
	// connectNum : 使用したいコントローラーの指定.
	static INT LTrigger( const int& connectNum = 0 );
	// R トリガー.
	// connectNum : 使用したいコントローラーの指定.
	static INT RTrigger( const int& connectNum = 0 );

	// L ボタン.
	// connectNum : 使用したいコントローラーの指定.
	static bool L_Button( const int& connectNum = 0 );
	// R ボタン.
	// connectNum : 使用したいコントローラーの指定.
	static bool R_Button( const int& connectNum = 0 );

	// スタートボタン.
	// connectNum : 使用したいコントローラーの指定.
	static bool Start_Button( const int& connectNum = 0 );
	// バックボタン.
	// connectNum : 使用したいコントローラーの指定.
	static bool Back_Button( const int& connectNum = 0 );

private:
	// 指定した数が接続されているかチェック.
	void ConnectCheck( const int& connectNum );
	// ボタン系の状態取得.
	bool IsButtonInput( const int& connectNum, const DWORD& button_mask );
	// インスタンス取得関数.
	static CXInput* GetInstance()
	{
		static std::unique_ptr<CXInput> pInstance = std::make_unique<CXInput>();
		return pInstance.get();
	}

private:
	std::vector<XINPUT_STATE> m_State;	// 接続したコントローラーの状態.
	int m_ConnectedCount;				// 接続したコントローラーの数.

	// コピー・ムーブコンストラクタ, 代入演算子の削除.
	CXInput( const CXInput & )				= delete;
	CXInput( CXInput && )					= delete;
	CXInput& operator = ( const CXInput & )	= delete;
	CXInput& operator = ( CXInput && )		= delete;
};


#endif	// #ifndef XINPUT_H.