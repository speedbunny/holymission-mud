inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("azrael");
    set_race("cat");
    set_short("Azrael");
    set_long(
"This is Gargamel's cat, Azrael. He is a mangy, flea-bitten specimen, his \
orange and white fur all dirty and matted. He has a big chunk missing out \
of one ear. He has an interesting-looking collar; made from a silvery \
metal with small, blue stones set in it.\n");
    set_level(4);
    set_hp(80);
    set_wc(4);
    set_ac(1);
    set_al(-500);
    set_gender(1);
    add_money(160);
}

