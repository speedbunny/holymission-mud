/* Gorlin, 15.10.1996 */

inherit "room/room";

void reset (int arg) {

   clone_list=({
      1, 1, "grey elephant", "/players/gorlin/elephant_jungle/monsters/elephant", 0,
     -1, 2, "elephant tusk", "/players/gorlin/elephant_jungle/obj/tusk", 0,
   });

   ::reset (arg);
   if (arg) return;

   short_desc="Jungle";
   long_desc="Another part of the jungle. Damp air, vibrant plantlife, "+
      "lots of mosquitos and other annoying insects. All you can see "+
      "around you is still more jungle.\n";
   set_light(1);
   dest_dir=({
      "/players/gorlin/elephant_jungle/rooms/jungle1","north",
      "/players/gorlin/elephant_jungle/rooms/jungle3","east",
      "/players/gorlin/elephant_jungle/rooms/jungle4","west",
   });
   items=({
      "insects","They swarm around you, and being small and fast, "+
         "it is hell trying to squat them.",
   });
   smell="The air smells somewhat damp, but it's not too unpleasant.";
   replace_program("room/room");
   return;
}
