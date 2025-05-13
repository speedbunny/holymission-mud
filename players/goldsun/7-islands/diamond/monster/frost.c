inherit "/obj/monster";

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("frost");
 set_race("giant");
 set_short("Frost");
 set_long("Frost the giant.\nHe is 10 feet tall and his muscles looks dangerous.\n");
 set_gender(1);
 set_level(56);
 set_ac(15);
 set_wc(34);
 set_hp(query_hp()+400);
 set_spell_mess1("Long icicle hurts your body.\n");
 set_spell_mess2("Frost cast long icicle.\n");
 set_chance(50);
 set_spell_dam(100+random(20));
}

