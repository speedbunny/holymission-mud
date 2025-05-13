inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("smurfette");
    set_race("smurf");
    set_short("Smurfette");
    set_long(
"This is Smurfette. She is dressed differently from the other smurfs, \
wearing a little dress and high heels. Her yellow hair reaches half-way \
down her back.\n");
    set_level(3);
    set_hp(70);
    set_wc(3);
    set_ac(1);
    set_al(750);
    set_gender(2);
    add_money(105);
}

