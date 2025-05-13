inherit "/obj/monster";


reset(arg) {
::reset(arg);
if(arg) return;

	set_name("Zombie");
	set_alias("zombie");
	set_level(11);
	set_short("A zombie");
	set_long(
"A horrific walking corpse, which smells awful...  The stench of rotten \n" +
"flesh is almost enough to knock you unconcious\n");
	set_al(-500);
	set_aggressive(1);
	set_hp(500);
	set_wc(10);
	set_ac(5);
        set_ep(750+random(500));
	set_spell_mess2(
"The Zombie smacks you in the face with his stump of an arm!!\n");
	set_spell_mess1(
"The Zombie swings his stump violently!!!\n");
	set_chance(5);
	set_spell_dam(10+random(40));
	}
