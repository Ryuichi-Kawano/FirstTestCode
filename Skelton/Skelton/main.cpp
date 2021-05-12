#include<DxLib.h>

struct Vector2 {
	float x, y;
};

using Position2 = Vector2;

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

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	Rect rcA = { 100,100,50,50 };

	char keystate[256];
	while (ProcessMessage() != -1) {
		ClearDrawScreen();
		GetHitKeyStateAll(keystate);
		constexpr float speed = 4.0f;
		if (keystate[KEY_INPUT_LEFT]) {
			rcA.center.x -= speed;
		}
		if (keystate[KEY_INPUT_RIGHT]) {
			rcA.center.x += speed;
		}
		if (keystate[KEY_INPUT_UP]) {
			rcA.center.y -= speed;
		}
		if (keystate[KEY_INPUT_DOWN]) {
			rcA.center.y += speed;
		}
		DrawBox(rcA.Left(), rcA.Top(), rcA.Right(), rcA.Bottom(), 0xffffff, true);
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}