inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("red knight");
    set_alias("knight");
    set_long("This Knight is clad in blood red armor and carrys a Blood red shield.\n");
    set_level(16);
    set_hp(700);
    set_al(-200);
    set_ac(6);
    set_wc(25);
    set_aggressive(1 );
}
