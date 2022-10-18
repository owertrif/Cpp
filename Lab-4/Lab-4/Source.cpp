#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;
class Tank;
class BTR;
class Tower;
class Soldiers_squad;

class Soldiers_squad {
public:
	Soldiers_squad() { status = "Alive"; }
	Soldiers_squad(double sp, double arm, double hp,double dmg,double throw_ac) {
		status = "Alive";
		speed = sp;
		if (arm >= 1)armor = arm;
		else {
			cout << "Armor cant be less than 0" << endl;
			armor = 0;
		}
		if (hp > 0)Hp = hp;
		else {
			cout << "HP cant be less than 0" << endl;
			Destroy();
		}
		if (dmg >= 0)damage = dmg;
		else {
			cout << "Damage cant be less than 0" << endl;
			damage = 0;
		}
		throw_acc = throw_ac;
	}

	void Destroy() {
		status = "Dead";
		Hp = 0;
	}

	void SetDamage(double dmg) {
		if(dmg >= 0)damage = dmg;
		else {
			cout << "Damage cant be less than 0" << endl;
			damage = 0;
		}
	}
	void SetSpeed(double speed_1) {
		speed = speed_1;
	}
	void SetThrowAcc(double throw_ac) {
		throw_acc = throw_ac;
	}
	void SetArmor(double arm) {
		if (arm >= 1)armor = arm;
		else {
			cout << "Armor cant be less than 0" << endl;
			armor = 0;
		}
	}
	void SetHp(double Hp_1) {
		if (Hp_1 > 0)Hp = Hp_1;
		else {
			cout << "Squad HP cant be less than 0. Dead !" << endl;
			Destroy();
		}
	}

	double GetSpeed() {
		return speed;
	}
	double GetDmg() {
		return damage;
	}
	double GetThrowAcc() {
		return throw_acc;
	}
	double GetArmor() {
		return armor;
	}
	string GetStatus() {
		return status;
	}
	double GetHp() {
		return Hp;
	}

	void Fire(Tank& tk);
	void Throw_Granade(Tank& tk);

	void Fire(Soldiers_squad& tk);
	void Throw_Granade(Soldiers_squad& tk);

	void Fire(BTR& tk);
	void Throw_Granade(BTR& tk);

private:
	double Hp;
	double damage;
	double speed;
	double armor;
	double throw_acc;
	string status;
};

class Tower{
public:
	Tower() { 
		damage = 0;
		accuracy = 0;
		ammo = 0;
		turn_speed = 0;
	}
	Tower(double dmg,double acc,double ts,int amm) {
		if (dmg >= 0)damage = dmg;
		else {
			cout << "Damage cant be less than 0" << endl;
			damage = 0;
		}
		accuracy = acc;
		if (amm >= 0)ammo = amm;
		else {
			cout << "Ammo cant be less than 0" << endl;
			ammo = 0;
		}
		turn_speed = ts;
	}

	void SetDamage(double dmg) {
		if (dmg >= 0)damage = dmg;
		else {
			cout << "Damage cant be less than 0" << endl;
			damage = 0;
		}
	}
	void SetAmmo(int ammo_1) {
		ammo = ammo_1;
	}
	void SetAcc(double acc) {
		accuracy = acc;
	}
	void SetTurnSp(double ts) {
		turn_speed = ts;
	}

	double GetTurnSp() {
		return turn_speed;
	}
	double GetAcc() {
		return accuracy;
	}
	double GetDmg() {
		return damage;
	}
	int GetAmmo() {
		return ammo;
	}

	void Shot(Soldiers_squad& sq);
	void Shot(Tank& sq);
	void Shot(BTR& sq);
	void Rearming() {
		cout << "Tank is rearming !" << endl;
		ammo = 1;
     }

private:
	double accuracy;
	double damage;
	int ammo;
	double turn_speed;
};

class Tank : public Tower {
public:
	Tank(){ status = "Good"; }
	Tank(double sp, double arm, double hp, string nm, int ammo, double accuracy, double damage, double turnspeed):Tower(damage,accuracy,turnspeed,ammo) {
		status = "Good";
		speed = sp;
		if (arm >= 1)armor_thick = arm;
		else {
			cout << "Armor thickness cant be less than 1" << endl;
			armor_thick = 1;
		}
		if (hp > 0)Hp = hp;
		else {
			cout << "HP cant be less than 0" << endl;
			Destroy();
		}
		name = nm;
	}

	void Destroy() {
		status = "Destroyed";
		Hp = 0;
	}

	void SetSpeed(double speed_1) {
		speed = speed_1;
	}
	void SetArmor(double arm) {
		if (arm >= 1)armor_thick = arm;
		else {
			cout << "Armor thickness cant be less than 1" << endl;
			armor_thick = 1;
		}
	}
	void SetName(string nm) {
		name = nm;
	}
	void SetHp(double Hp_1) {
		if (Hp_1 > 0)Hp = Hp_1;
		else {
			cout << " Tank HP cant be less than 0. Destroyed !" << endl;
			Destroy();
		}
	}
	

	string GetName() {
		return name;
	}
	double GetSpeed() {
		return speed;
	}
	
	double GetArmor() {
		return armor_thick;
	}
	string GetStatus() {
		return status;
	}
	double GetHp() {
		return Hp;
	}

private:
	string name;
	double speed;
	double armor_thick;
	double Hp;
	string status;
};

class Engine {
public:
	Engine() {
		speed = 0;
		cylinder_num = 0;
		fuel_consumption = 0;
		fuel_type = "none";
	}
	Engine(double s, int cn, double fc, string ft ) {
		speed = s;
		cylinder_num = cn;
		fuel_consumption = fc;
		fuel_type = ft;
	}

	double GetSpeed() {
		return speed;
	}
	double GetFC() {
		return fuel_consumption;
	}
	string GetFT() {
		return fuel_type;
	}
	int GetCN() {
		return cylinder_num;
	}

	void SetSpeed(double s) {
		speed = s;
	}
	void SetFC(double fc) {
		fuel_consumption = fc;
	}
	void SetFT(string ft) {
		fuel_type = ft;
	}
	void SetCN(int cn) {
		cylinder_num = cn;
	}
	
private:
	double speed;
	double fuel_consumption;
	int cylinder_num;
	string fuel_type;
};

class BTR : public Engine {
public:
	BTR() {
		hp = 0;
		damage = 0;
		armor = 0;
		name = "none";
		status = "Good";
	}
	BTR(string n, double hp_1, double arm, double dmg, double s, int cn, double fc, string ft) : Engine(s, cn, fc, ft) {
		name = n;
		if (hp_1 > 0)hp = hp_1;
		else {
			cout << "HP cant be less than 0. Destroyed !" << endl;
			Destroyed();
		}
		if (arm >= 1)armor = arm;
		else {
			cout << "Armor thickness cant be less than 1" << endl;
			armor = 1;
		}
		if (dmg >= 0)damage = dmg;
		else {
			cout << "Damage cant be less than 0" << endl;
			damage = 0;
		}
		status = "Good";
	}

	void Destroyed() {
		status = "Destroyed";
		hp = 0;
	}

	double GetHp() {
		return hp;
	}
	double GetArmor() {
		return armor;
	}
	double GetDamage() {
		return damage;
	}
	string GetName() {
		return name;
	}
	string GetStatus() {
		return status;
	}

	void SetName(string n) {
		name = n;
	}
	void SetHp(double hp_1) {
		if (hp_1 > 0)hp = hp_1;
		else {
			cout << " BTR HP cant be less than 0. Destroyed !" << endl;
			Destroyed();
		}
	}
	void SetDamage(double dmg) {
		if (dmg >= 0)damage = dmg;
		else {
			cout << "Damage cant be less than 0" << endl;
			damage = 0;
		}
	}
	void SetArmor(double arm) {
		if (arm >= 1)armor = arm;
		else {
			cout << "Armor thickness cant be less than 1" << endl;
			armor = 1;
		}
	}
	void Fire(Soldiers_squad& sq);
	void Fire(BTR& sq);
	void Fire(Tank& sq);

private:
	string status;
	string name;
	double hp;
	double armor;
	double damage;
};

void BTR :: Fire(Soldiers_squad& sq){
	cout <<GetName() << " is firing !" << endl;
	sq.SetHp(sq.GetHp() - (damage - sq.GetArmor() * 0.4));
}
void BTR::Fire(BTR& sq) {
	cout << GetName() << " is firing !" << endl;
	sq.SetHp(sq.GetHp() - (damage - sq.GetArmor() * 0.6));
}
void BTR::Fire(Tank& sq) {
	cout << GetName() << " is firing !" << endl;
	sq.SetHp(sq.GetHp() - (damage - sq.GetArmor() * 0.6));
}

void Tower::Shot(Soldiers_squad& sq) {
	srand(time(NULL));
	double total_hp;
	int chance;
	cout << "Tank is shooting !" << endl;
	if (ammo > 0) {
		chance = rand() % 101;
		if (chance <= accuracy) {
			ammo--;
			sq.SetHp(sq.GetHp() - (damage - sq.GetArmor() * 0.6));
		}
		else {
			cout << "Tank missed !" << endl;
		}
	}
	else cout << "No ammo !!!" << endl;
}
void Tower::Shot(Tank& sq) {
	double total_hp;
	int chance;
	cout << "Tank is shooting !" << endl;
	if (ammo > 0) {
		chance = rand() % 101;
		if (chance <= accuracy) {
			ammo--;
			sq.SetHp(sq.GetHp() - (damage - sq.GetArmor() * 0.2));
		}
		else {
			cout << "Tank missed !" << endl;
		}
	}
	else cout << "No ammo !!!" << endl;
}
void Tower::Shot(BTR& sq) {
	double total_hp;
	int chance;
	cout << "Tank is shooting !" << endl;
	if (ammo > 0) {
		chance = rand() % 101;
		if (chance <= accuracy) {
			ammo--;
			sq.SetHp(sq.GetHp() - (damage - sq.GetArmor() * 0.4));
		}
		else {
			cout << "Tank missed !" << endl;;
		}
	}
	else cout << "No ammo !!!" << endl;
}

void Soldiers_squad::Fire(Tank& tk) {
	cout << "Squad firing !" << endl;
	tk.SetHp(tk.GetHp() - (damage - tk.GetArmor() * 0.8));
}
void Soldiers_squad::Throw_Granade(Tank& tk) {
	cout << "Squad throwing granade !" << endl;
	int chance = rand() % 101;
	if (chance <= throw_acc)
	{
		tk.SetHp(tk.GetHp() - (damage*2 - tk.GetArmor() * 0.4));
	}
	else {
		cout << "Granade missed !" << endl;
	}
}

void Soldiers_squad::Fire(Soldiers_squad& tk) {
	cout << "Squad firing !" << endl;
	tk.SetHp(tk.GetHp() - (damage - tk.GetArmor() * 0.5));
}
void Soldiers_squad::Throw_Granade(Soldiers_squad& tk) {
	cout << "Squad throwing granade !" << endl;
	int chance = rand() % 101;
	if (chance <= throw_acc)
	{
		tk.SetHp(tk.GetHp() - (damage*2 - tk.GetArmor() * 0.4));
	}
	else {
		cout << "Granade missed !" << endl;
	}
}

void Soldiers_squad::Fire(BTR& tk) {
	cout << "Squad firing !" << endl;
	tk.SetHp(tk.GetHp() - (damage - tk.GetArmor() * 0.7));
}
void Soldiers_squad::Throw_Granade(BTR& tk) {
	cout << "Squad throwing granade !" << endl;
	int chance = rand() % 101;
	if (chance <= throw_acc)
	{
		tk.SetHp(tk.GetHp() - (damage*2 - tk.GetArmor() * 0.3));
	}
	else {
		cout << "Granade missed !" << endl;
	}
}

void main()
{
	srand(time(NULL));
	int choice;
	int turn_cntr = 0;
	BTR btr("BTR_1", 1000, 350, 400, 70, 10, 10, "Solarka");
	Tank tank(50, 500, 1500, "Tiger", 1, 80, 550, 15);
	Soldiers_squad sq(100, 200, 750, 500, 50);
	cout << ">>The battle has started !<<" << endl;
	while (1) {
		cout << ">>Turn number " << turn_cntr << "<<" << endl;
		if (sq.GetStatus() == "Dead" && tank.GetStatus() == "Destroyed")
		{
			cout << btr.GetName() << " is winner !!" << endl;
			break;
		}
		else if (sq.GetStatus() == "Dead" && btr.GetStatus() == "Destroyed")
		{
			cout << tank.GetName() << " is winner !!" << endl;
			break;
		}
		else if (tank.GetStatus() == "Destroyed" && btr.GetStatus() == "Destroyed")
		{
			cout << "Squad of soldiers is winner !!" << endl;
			break;
		}
		++turn_cntr;
			if (sq.GetStatus() != "Dead") {
				choice = rand() % 2;
				if (turn_cntr % 3 != 0) {
					if (choice == 0) {
						if (btr.GetStatus() != "Destroyed")sq.Fire(btr);
					}
					if (choice == 1) {
						if (tank.GetStatus() != "Destroyed")sq.Fire(tank);
					}
				}
				else {
					if (choice == 0) {
						if (btr.GetStatus() != "Destroyed")sq.Throw_Granade(btr);
					}
					if (choice == 1) {
						if (tank.GetStatus() != "Destroyed")sq.Throw_Granade(tank);
					}
				}
			}

			if (btr.GetStatus() != "Destroyed") {
				choice = rand() % 2;
				if (choice == 0) {
					if (sq.GetStatus() != "Dead")btr.Fire(sq);
				}
				if (choice == 1) {
					if (tank.GetStatus() != "Destroyed")btr.Fire(tank);
				}
			}

			if (turn_cntr % 2 == 0) {
				if (tank.GetStatus() != "Destroyed") {
					if (tank.GetAmmo() <= 0)tank.Rearming();
					else {
						choice = rand() % 2;
						if (choice == 0) {
							if (sq.GetStatus() != "Dead")tank.Shot(sq);
						}
						if (choice == 1) {
							if (btr.GetStatus() != "Destroyed")tank.Shot(btr);
						}
					}
				}
			}
			cout << ">>>>Tank hp: " << tank.GetHp() <<" <<<<" << endl << ">>>>BTR hp: " << btr.GetHp() << " <<<<" << endl << ">>>>Squad hp: " << sq.GetHp() << " <<<<" << endl;
	}
}