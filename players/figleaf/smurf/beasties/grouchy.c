inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("grouchy");
    set_race("smurf");
    set_short("Grouchy Smurf");
    set_long(
"This is Grouchy Smurf. He's in a REALLY bad mood today so you'd better \
steer clear of him.\n");
    set_level(2);
    set_hp(60);
    set_wc(3);
    set_ac(0);
    set_al(750);
    set_gender(1);
    add_money(90);
}

