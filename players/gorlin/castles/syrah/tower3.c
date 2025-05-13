
/* Gorlin, 22.4.1996 */

inherit "room/room";

void reset (int arg)
{
   ::reset (arg);
   if (arg) return;

   set_light(1);
   short_desc="In a slender tower";
   long_desc="You are standing in a library. You can see some "+
             "comfortable chairs in here, and of course lots of "+
             "cupboards with books in them. The books are dusty "+
             "and very old, and are hidden behind some kind of "+
             "blue magic field for their protection.\n";
   dest_dir=({
      "/players/gorlin/castles/syrah/tower2","down"
      });

   items=({
      "books","They are hidden behind an energy field",
      "field","An impenetrable magic field",
      "chairs","Comfortable chairs",
      "skulls","They once belonged to various animals and monsters",
      });
   smell="You smell nothing special.";
}

