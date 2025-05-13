inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("black knight");
    set_alias("knight");
    set_long("This huge knight is clad in black and wields a black sword.\n");
    set_level(17);
    set_hp(1500);
    set_al(-1000);
    set_ac(8);
    set_wc(28);
    set_aggressive(1);
}
