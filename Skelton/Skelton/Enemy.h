#pragma once

//�l�[���X�y�[�X���̃N���X�̑O���錾��
//���̂悤�ɁA���̃l�[���X�y�[�X�ň͂񂶂Ⴂ�܂��B
namespace Battle {
	class Player;//�v���g�^�C�v�錾
	class Weapon;
	class Shot;
}
class Enemy
{
	Battle::Player* player_;//Battle::������̂ɒ���
	Battle::Weapon* weapon_;
	Battle::Shot* shot_;
	int life_=100;
public:
	void OnDamage(int damage);
	void Attack();
};


