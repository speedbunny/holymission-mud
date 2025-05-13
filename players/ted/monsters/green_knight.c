inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("green knight");
    set_alias("knight");
    set_long("This Knight is clad in green and wears green platemail.\n");
    set_level(17);
    set_hp(1500);
    set_al(-500);
    set_ac(6);
    set_wc(25);
    set_aggressive(1);
}
