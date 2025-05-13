inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("vanity");
    set_race("smurf");
    set_short("Vanity Smurf");
    set_long(
"This is Vanity Smurf. He thinks he's God's gift to all smurfs and is \
constantly gazing at himself in his mirror.\n");
    set_level(2);
    set_hp(60);
    set_wc(3);
    set_ac(0);
    set_al(750);
    set_gender(1);
    add_money(90);
}

