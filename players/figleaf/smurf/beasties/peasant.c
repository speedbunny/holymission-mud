inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("peasant");
    set_race("human");
    set_short("A sorry-looking peasant");
    set_long(
"This poor soul trudges wearily about his business.\n");
    set_level(2);
    set_hp(60);
    set_wc(3);
    set_ac(0);
    set_al(200);
    set_gender(1);
    add_money(50);
}

