#pragma once

//ネームスペース内のクラスの前方宣言は
//このように、そのネームスペースで囲んじゃいます。
namespace Battle {
	class Player;//プロトタイプ宣言
	class Weapon;
	class Shot;
}
class Enemy
{
	Battle::Player* player_;//Battle::があるのに注意
	Battle::Weapon* weapon_;
	Battle::Shot* shot_;
	int life_=100;
public:
	void OnDamage(int damage);
	void Attack();
};


