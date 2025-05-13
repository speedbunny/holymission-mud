inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("small fish");
    set_alias("fish");
    set_level(1);
    set_ep(60);
    set_hp(20);
    set_wc(1);
    set_ac(5);
    set_al(0);
    set_short("A small fish");
    set_long("A small fish, swimming happily in the clear water of the\n"
           + "lake.\n");
    set_own_env("water");
  }
}
