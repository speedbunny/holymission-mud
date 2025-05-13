inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("jokey");
    set_race("smurf");
    set_short("Jokey Smurf");
    set_long(
"This is Jokey Smurf. He is cackling maniacally to himself and carrying a \
large, brightly-wrapped package.\n");
    set_level(2);
    set_hp(60);
    set_wc(3);
    set_ac(0);
    set_al(750);
    set_gender(1);
    add_money(90);
}

