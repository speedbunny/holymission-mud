inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("papa");
    set_race("smurf");
    set_short("Papa Smurf");
    set_long(
"This is Papa smurf. He is dressed in red pants and a red hat, and has a \
bushy white beard. He's carrying a small walking stick.\n");
    set_level(4);
    set_hp(80);
    set_wc(4);
    set_ac(1);
    set_al(750);
    set_gender(1);
    add_money(160);
    set_chance(10);
    set_spell_dam(5);
    set_spell_mess1("Papa Smurf casts a little spell.\n");
    set_spell_mess2("Papa Smurf casts a little spell at you\n");
}

