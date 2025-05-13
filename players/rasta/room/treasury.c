/* This file was completely revamped by Cashimor 220992 */
/* Now the quest resets and seed and thief return       */

inherit "room/room";

object seed,thief;

reset(arg) {
  if (!arg) {
    set_light(0);
    property = "no_teleport";
    dest_dir=({"/players/rasta/room/afflict","up"});
    short_desc="Treasury Chamber";
    long_desc=
      "You are in the Treasury Chamber, where the glitter of crowns and "
    + "ceremonial\n"
    + "swords, of state vestments and paraments, of agate goblets and huge "
    + "emeralds\n"
    + "of narwhale ivory and the gold-encrusted christening gowns of Prince "
    + "Rasta\n"
    + "used to shimmer through the enigmatic twilight.\n"
    + "Unfortunately these valuables were stolen some time ago.\n";
  }
  if (!thief) {
    thief=clone_object("players/rasta/obj/thief");
    move_object(thief,this_object());
  }
  if(!seed) {
    seed=clone_object("players/rasta/obj/seed");
    move_object(seed,thief);
  }
}
           
