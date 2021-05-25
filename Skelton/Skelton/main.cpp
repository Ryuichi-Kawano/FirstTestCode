#include<DxLib.h>
#include<array>//stlで配列を表すもの
#include<cassert>
#include<memory>//スマートポインタ
#include<sstream>//文字列ストリーム
#include<iomanip>//ストリームマニピュレータ
#include"Debug.h"

struct Vector2 {
	float x, y;
};

using Position2 = Vector2;
using KeyboardData_t = std::array<char, 256>;

struct Rect {
	Position2 center;
	float w;//width/2
	float h;//height/w
	float Left()const {
		return center.x - w;
	}
	float Top()const {
		return center.y - h;
	}
	float Right()const {
		return center.x + w;
	}
	float Bottom()const {
		return center.y + h;
	}
	float Width()const {
		return w * 2;
	}
	float Height()const {
		return h * 2;
	}
};

void MoveByInput(const KeyboardData_t& keystate, Position2& pos) {
	
	constexpr float speed = 4.0f;
	if (keystate[KEY_INPUT_LEFT]) {
		pos.x -= speed;
	}
	if (keystate[KEY_INPUT_RIGHT]) {
		pos.x += speed;
	}
	if (keystate[KEY_INPUT_UP]) {
		pos.y -= speed;
	}
	if (keystate[KEY_INPUT_DOWN]) {
		pos.y += speed;
	}
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetWindowText(L"0000000_川野竜一");
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	int graphH[6] = {};
	for (int i = 0; i < 6; ++i) {
		std::wostringstream oss;
		oss << L"../../Asset/Adventurer-1.5/Individual Sprites/adventurer-run-";
		oss << std::setw(2);
		oss << std::setfill(L'0');
		oss << i << ".png";

		//wsprintf(path, L"../../Asset/Adventurer-1.5/Individual Sprites/adventurer-run-%02d.png", i);
		graphH[i] = LoadGraph(oss.str().c_str());
		assert(graphH[i] != -1);
	}
	Rect rcA = { 100,100,75,75 };
	KeyboardData_t keystate;
	
	int a[10] = {};
	a[5]++;

	a[7]++;
	
	unsigned int frameNo = 0;
	while (ProcessMessage() != -1) {
		ClearDrawScreen();
		GetHitKeyStateAll(keystate.data());
		MoveByInput(keystate, rcA.center);
		DrawBox(rcA.Left(), rcA.Top(), rcA.Right(), rcA.Bottom(), 0xffffff, true);
		//wchar_t out[64];
		//wsprintf(out, L"x=%d , y=%d\n", (int)rcA.center.x, (int)rcA.center.y);
		//OutputDebugString(out);

		std::wostringstream oss;
		oss << L"x=" << rcA.center.x;
		oss << L" , y=" << rcA.center.y << std::endl;
		OutputDebugString(oss.str().c_str());


		DrawRotaGraph(rcA.center.x, rcA.center.y, 4.0f, 0.0f, graphH[frameNo/10], true);

		//sprintf_s(out, sizeof(out),"x=%3.2f , y=%3.2f\n",rcA.center.x,rcA.center.y);
		//OutputDebugStringA(out);

		//Debug::Out(16);
		//Debug::Out(3.14f);
		//Debug::Out("Debug Out\n");
		//Debug::Out(L"Debug WOut\n");

		ScreenFlip();
		frameNo = (frameNo + 1) % 60;
	}


	DxLib_End();
	return 0;
}