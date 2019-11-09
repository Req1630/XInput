#ifndef XINPUT_H
#define XINPUT_H

#include <Windows.h>
#include <crtdbg.h>
#include <Xinput.h>
#include <vector>
#include <memory>

#pragma comment( lib, "xinput.lib" )

static const int IDLE_THUMB_MAX		=  10000;	// �X�e�B�b�N�̗V��.
static const int IDLE_THUMB_MIN		= -10000;	// �X�e�B�b�N�̗V��.
static const int IDLE_TIGGER_MAX	=  100;		// �g���K�[�{�^���̗V��.

/////////////////////////////////////////////////
//	Xinput :�@�R���g���[���[�N���X.
//�@�@�@�@�@�V���O���g���Ƃ��Ďg�p.
//////
class CXInput
{
	const int CONTROTLLERS_MAX = 4;	// �ڑ��R���g���[���̍ő吔.
public:
	CXInput();
	~CXInput();

	// �R���g���[���[�̏�Ԃ��X�V.
	static void StatsUpdate();

	// �R���g���[���[�̐ڑ����擾.
	static int GetConnectCount(){ return GetInstance()->m_ConnectedCount; }
	
	// A �{�^��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static bool A_Button( const int& connectNum = 0 );
	// B �{�^��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static bool B_Button( const int& connectNum = 0 );
	// X �{�^��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static bool X_Button( const int& connectNum = 0 );
	// Y �{�^��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static bool Y_Button( const int& connectNum = 0 );

	// �����L�[ : UP.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	// isKeyinput : �L�[�{�[�h�̕����L�[���g�p���邩�ǂ���.
	static bool DPadUp( const int& connectNum = 0, const bool& isKeyinput = false );
	// �����L�[ : DOWN.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	// isKeyinput : �L�[�{�[�h�̕����L�[���g�p���邩�ǂ���.
	static bool DPadDown( const int& connectNum = 0, const bool& isKeyinput = false );
	// �����L�[ : LEFT.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	// isKeyinput : �L�[�{�[�h�̕����L�[���g�p���邩�ǂ���.
	static bool DPadLEFT( const int& connectNum = 0, const bool& isKeyinput = false );
	// �����L�[ : RIGHT.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	// isKeyinput : �L�[�{�[�h�̕����L�[���g�p���邩�ǂ���.
	static bool DPadRIGHT( const int& connectNum = 0, const bool& isKeyinput = false );

	// L �X�e�B�b�N : X��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static SHORT LThumbX_Axis( const int& connectNum = 0 );
	// L �X�e�B�b�N : Y��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static SHORT LThumbY_Axis( const int& connectNum = 0 );

	// R �X�e�B�b�N : X��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static SHORT RThumbX_Axis( const int& connectNum = 0 );
	// R �X�e�B�b�N : Y��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static SHORT RThumbY_Axis( const int& connectNum = 0 );

	// L �X�e�B�b�N�{�^��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static bool LThumb_Button( const int& connectNum = 0 );
	// R �X�e�B�b�N�{�^��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static bool RThumb_Button( const int& connectNum = 0 );

	// L �g���K�[.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static INT LTrigger( const int& connectNum = 0 );
	// R �g���K�[.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static INT RTrigger( const int& connectNum = 0 );

	// L �{�^��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static bool L_Button( const int& connectNum = 0 );
	// R �{�^��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static bool R_Button( const int& connectNum = 0 );

	// �X�^�[�g�{�^��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static bool Start_Button( const int& connectNum = 0 );
	// �o�b�N�{�^��.
	// connectNum : �g�p�������R���g���[���[�̎w��.
	static bool Back_Button( const int& connectNum = 0 );

private:
	// �w�肵�������ڑ�����Ă��邩�`�F�b�N.
	void ConnectCheck( const int& connectNum );
	// �{�^���n�̏�Ԏ擾.
	bool IsButtonInput( const int& connectNum, const DWORD& button_mask );
	// �C���X�^���X�擾�֐�.
	static CXInput* GetInstance()
	{
		static std::unique_ptr<CXInput> pInstance = std::make_unique<CXInput>();
		return pInstance.get();
	}

private:
	std::vector<XINPUT_STATE> m_State;	// �ڑ������R���g���[���[�̏��.
	int m_ConnectedCount;				// �ڑ������R���g���[���[�̐�.

	// �R�s�[�E���[�u�R���X�g���N�^, ������Z�q�̍폜.
	CXInput( const CXInput & )				= delete;
	CXInput( CXInput && )					= delete;
	CXInput& operator = ( const CXInput & )	= delete;
	CXInput& operator = ( CXInput && )		= delete;
};


#endif	// #ifndef XINPUT_H.