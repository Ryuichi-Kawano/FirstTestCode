#pragma once
class Enemy;

namespace Battle {
	class Player
	{
		Enemy* enemy_;//8ƒoƒCƒg(ŒÅ’è)
		int life_ = 100;
	public:
		void OnDamage(int damage);
		void Attack();
	};
}