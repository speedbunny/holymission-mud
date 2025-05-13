inherit "/obj/monster";

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("frost");
 set_race("giant");
 set_short("Frost");
 set_long(
"Before you stands Frost the giant.  He is a little over 10 feet tall and "+
"his muscles flex rhythmically as he wrings his hands.  He is wearing an "+
"untanned hide and you can smell the rot rolling off of it every time he "+
"moves.\n");
 set_gender(1);
 set_level(56);
 set_ac(15);
 set_wc(34);
 set_hp(query_hp()+400);
 set_spell_mess1("Long icicle stab into your body.\n");
 set_spell_mess2("Frost casts an icicle spell.\n");
 set_chance(50);
 set_spell_dam(100+random(20));
}

