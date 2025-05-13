/*Room description corrected by Silas*/
/* Matt 7-8-93: Revamp */

inherit "room/room";

object ob;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Entrance to Jug`s Castle";
  long_desc = 
    "You have entered the fabulous world of Jug, the WORLDS OF WONDER.\n" +
    "Behind you there is the other end of the dimension door you entered.\n" +
    "To the north is a hall which leads to the central point of the castle.\n" +
    "To the west is an entrance to a wonderful garden. There NEWBIES can\n" +
    "roam around in search of adventure.\n" +
    "Enjoy your visit here, you will see that there are many new things that\n" +
    "you can find (if you search for them).\n" +
    "\t\t\t\t\tGreets, Jug.\n";

  dest_dir = ({
    "/players/jug/room/entryhall", "north",
    "/players/jug/room/garden/gard_ent", "west",
    "/room/vill_shore2", "door",
  });

#if 0

  ob = clone_object("players/jug/obj/dim_door");
  transfer(ob, "room/vill_shore2");

#endif

}

