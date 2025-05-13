inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("wolf");
    set_race("canine");
    set_level(15);
    set_wc(10);
    set_short("A wild wolf");
    set_long("A wild and dangerous wolf of the forest.\n");
    set_aggressive(1);
}
