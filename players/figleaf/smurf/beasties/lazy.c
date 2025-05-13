inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("lazy");
    set_race("smurf");
    set_short("Lazy Smurf");
    set_long(
"This is Lazy Smurf. He is carrying a big pillow and you think he's just \
looking for a flat surface to take a nap on.\n");
    set_level(2);
    set_hp(60);
    set_wc(3);
    set_ac(0);
    set_al(750);
    set_gender(1);
    add_money(90);
}

