/* boar.c (C) Whisky */

inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("bat");
    set_short("An aggressive bat");
    set_long("An aggressive vampire bat flying around your head.\n");
    set_race("bat");
    set_level(1);
    set_size(1);
    set_al(-10);
    set_aggressive(1);
  }
}
