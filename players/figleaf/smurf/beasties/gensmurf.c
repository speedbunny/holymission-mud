inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("smurf");
    set_race("smurf");
    set_short("A happy little smurf");
    set_long(
"This little blue smurf whistles happily as he walks.\n");
    set_level(1);
    set_hp(50);
    set_wc(3);
    set_ac(0);
    set_al(750);
    set_gender(1);
    add_money(50);
}

