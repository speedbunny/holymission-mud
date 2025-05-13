inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("hefty");
    set_race("smurf");
    set_short("Hefty Smurf");
    set_long(
"This is Hefty Smurf. He is carrying a large dumbbell in one hand. He is \
very well built, for a smurf, and he has a heart tattoo on his arm.\n");
    set_level(3);
    set_hp(70);
    set_wc(3);
    set_ac(1);
    set_al(750);
    set_gender(1);
    add_money(105);
}

