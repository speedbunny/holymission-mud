
inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("wolf");
    set_alias("aggressive wolf");
    set_short("An aggressive wolf");
    set_long("He looks at you with glowing eyes.\n");
    set_race("animal");
    set_level(2);
    set_size(2);
    set_al(-100);
    set_aggressive(1);
    set_whimpy();
    move_object(clone_object("players/whisky/garden/obj/claws"),this_object());
  }
}
