inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("alligator");
    set_alias("alligator");
    set_long("An immense, tough-skinned, alligator.\n");
    set_level(17);
    set_hp(1500);
    set_al(-1000);
    set_ac(17);
    set_wc(13);
    set_aggressive(1);
    add_money(547);
}
