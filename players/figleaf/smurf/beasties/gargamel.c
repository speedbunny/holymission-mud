inherit "obj/monster";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("gargamel");
    set_race("human");
    set_short("Gargamel");
    set_long(
"This is the evil and rather inept wizard Gargamel. He's short and ugly \
with a big, rubbery nose. He is all hunched-over in his dirty, patched-up \
robe. He never ceases in his life's mission to catch all the smurfs.\n");
    set_level(6);
    set_hp(100);
    set_wc(5);
    set_ac(2);
    set_al(-750);
    set_gender(1);
    add_money(500);
}

