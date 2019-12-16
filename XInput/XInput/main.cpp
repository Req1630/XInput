#include "XInput/XInput.h"
#include <Windows.h>
#include <iostream>
#include <string>

HANDLE m_hConStdOut;
CONSOLE_CURSOR_INFO cci;

void controller_test_out( const int& connect_num );

int main()
{
	m_hConStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	GetConsoleCursorInfo( m_hConStdOut, &cci );
	cci.bVisible = FALSE;
	SetConsoleCursorInfo( m_hConStdOut, &cci );

	int count = 0;
	while(true)
	{
		COORD coord;
		coord.X = 0; coord.Y = 0;
		SetConsoleCursorPosition( m_hConStdOut,coord );

		std::cout << "Esc で終了" << std::endl;
		if( GetAsyncKeyState(VK_ESCAPE) & 0x0001 ) break;

		CXInput::StatsUpdate();

		std::cout << "コントローラー接続数 : " << CXInput::GetConnectCount() << std::endl;

		controller_test_out( CXInput::GetConnectCount() );
		Sleep(200);
		count++;
	}

	CloseHandle( m_hConStdOut );

	return 0;
}

void controller_test_out( const int& connect_num )
{
	for( int i = 0; i < connect_num; i++ ){
		COORD coord;
		coord.X = i * 30; coord.Y = 3;
		SetConsoleCursorPosition( m_hConStdOut,coord );

		std::cout << "A : [" << CXInput::A_Button(i) << "]" << std::endl;
		coord.X = i * 30; coord.Y = 4;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "B : [" << CXInput::B_Button(i) << "]" << std::endl;
		coord.X = i * 30; coord.Y = 5;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "X : [" << CXInput::X_Button(i) << "]" << std::endl;
		coord.X = i * 30; coord.Y = 6;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "Y : [" << CXInput::Y_Button(i) << "]" << std::endl;

		coord.X = i * 30; coord.Y = 7;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "UP    : [" << CXInput::DPadUp(i) << "]" << std::endl;
		coord.X = i * 30; coord.Y = 8;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "DOWN  : [" << CXInput::DPadDown(i) << "]" << std::endl;
		coord.X = i * 30; coord.Y = 9;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "LEFT  : [" << CXInput::DPadLEFT(i) << "]" << std::endl;
		coord.X = i * 30; coord.Y = 10;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "RIGHT : [" << CXInput::DPadRIGHT(i) << "]" << std::endl;

		coord.X = i * 30; coord.Y = 11;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "LThum X : [" << CXInput::LThumbX_Axis(i) << "]     " << std::endl;
		coord.X = i * 30; coord.Y = 12;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "LThum Y : [" << CXInput::LThumbY_Axis(i) << "]     " << std::endl;
		coord.X = i * 30; coord.Y = 13;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "RThum X : [" << CXInput::RThumbX_Axis(i) << "]     " << std::endl;
		coord.X = i * 30; coord.Y = 14;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "RThum Y : [" << CXInput::RThumbY_Axis(i) << "]     " << std::endl;

		coord.X = i * 30; coord.Y = 15;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "LThum Button : [" << CXInput::LThumb_Button(i) << "]" << std::endl;
		coord.X = i * 30; coord.Y = 16;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "RThum Button : [" << CXInput::RThumb_Button(i) << "]" << std::endl;

		coord.X = i * 30; coord.Y = 17;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "L : [" << CXInput::L_Button(i) << "]" << std::endl;
		coord.X = i * 30; coord.Y = 18;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "R : [" << CXInput::R_Button(i) << "]" << std::endl;

		coord.X = i * 30; coord.Y = 19;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "L Trigger : [" << CXInput::LTrigger(i) << "]    " << std::endl;
		coord.X = i * 30; coord.Y = 20;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "R Trigger : [" << CXInput::RTrigger(i) << "]    " << std::endl;

		coord.X = i * 30; coord.Y = 21;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "Start : [" << CXInput::Start_Button(i) << "]" << std::endl;
		coord.X = i * 30; coord.Y = 22;
		SetConsoleCursorPosition( m_hConStdOut,coord );
		std::cout << "Back  : [" << CXInput::Back_Button(i) << "]" << std::endl;
	}
};