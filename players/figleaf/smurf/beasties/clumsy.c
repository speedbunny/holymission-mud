inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("clumsy");
    set_race("smurf");
    set_short("Clumsy Smurf");
    set_long(
"This is Clumsy Smurf. He has a big bandage around his leg and is \
stumbling along on his crutches, knocking things over all around.\n");
    set_level(2);
    set_hp(60);
    set_wc(3);
    set_ac(0);
    set_al(750);
    set_gender(1);
    add_money(90);
}

