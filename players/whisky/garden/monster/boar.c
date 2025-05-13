/* boar.c (C) Whisky */

inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("boar");
    set_alias("wild boar");
    set_short("A wild boar");
    set_long("An brown aggressive wild boar.\n");
    set_race("boar");
    set_level(2);
    set_size(2);
    set_al(-100);
    set_aggressive(1);
    move_object(clone_object("players/whisky/garden/obj/cone"),this_object());
  }
}
