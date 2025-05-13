inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("fox");
    set_race("canine");
    set_level(8);
    set_wc(10);
    set_short("A crafty fox");
    set_long("A wily red fox.\n");
    set_aggressive(1);
}
