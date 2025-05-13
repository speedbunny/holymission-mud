inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("farmer");
    set_race("smurf");
    set_short("Farmer Smurf");
    set_long(
"This is Farmer Smurf. He is wearing a pair of white overalls and carries \
a big hoe.\n");
    set_level(3);
    set_hp(70);
    set_wc(3);
    set_ac(1);
    set_al(750);
    set_gender(1);
    add_money(105);
}

