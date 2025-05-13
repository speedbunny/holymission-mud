/* Gorlin, 15.10.1996 */

inherit "room/room";

void reset (int arg) {

   clone_list=({
      1, 3, "grey elephant", "/players/gorlin/elephant_jungle/monsters/elephant", 0,
     -1, 2, "elephant tusk", "/players/gorlin/elephant_jungle/obj/tusk", 0,
      2, 1, "elephant bull", "/players/gorlin/elephant_jungle/monsters/elephant_bull", 0,
     -2, 2, "elephant tusk", "/players/gorlin/elephant_jungle/obj/tusk", 0,
   });

   ::reset (arg);
   if (arg) return;

   short_desc="Jungle";
   long_desc="Another part of the jungle. The air is damp, and the  "+
      "jungle continues in all directions. Luckily the insects have stoppped "+
      "their attacks for the moment.\n";
   set_light(1);
   dest_dir=({
      "/players/gorlin/elephant_jungle/rooms/jungle4","north",
      "/players/gorlin/elephant_jungle/rooms/jungle7","east",
   });
   smell="The air smells somewhat damp, but it's not too unpleasant.";
   replace_program("room/room");
   return;
}
