inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("brainy");
    set_race("smurf");
    set_short("Brainy Smurf");
    set_long(
"This is Brainy smurf. He is wearing thick glasses and carrying a big pile \
of books.\n");
    set_level(1);
    set_hp(50);
    set_wc(3);
    set_ac(0);
    set_al(750);
    set_gender(1);
    add_money(50);
}

