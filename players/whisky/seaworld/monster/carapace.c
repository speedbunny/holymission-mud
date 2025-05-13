
inherit "/obj/monster";

reset(arg) 
{
  ::reset(arg);

  if (arg) return;

    set_name("carapace");
    set_level(8);
    set_has_gills();
    set_alt_name("big carapace");
    set_race("fish");
    set_short("A big carapace");
    set_long("You see a big brown carapace.\n");
    set_whimpy();
    move_object(clone_object("players/whisky/seaworld/obj/shield"),this_object());
}
