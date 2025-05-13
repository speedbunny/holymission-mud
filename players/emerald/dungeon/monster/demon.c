inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("demon");
    set_race("demon");
    set_long("The demon is inky black, with a menacing red-eyed stare.\n");
    set_level(60);
    set_al(-400);
    set_ac(25);
    set_wc(20);
    add_money(3400);
    set_aggressive(1);
}
