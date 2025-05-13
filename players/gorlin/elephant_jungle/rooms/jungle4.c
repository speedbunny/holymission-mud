/* Gorlin, 15.10.1996 */

inherit "room/room";

void reset (int arg) {

   clone_list=({
      1, 1, "tiger", "/players/gorlin/elephant_jungle/monsters/tiger", 0,
   });

   ::reset (arg);
   if (arg) return;

   short_desc="Jungle";
   long_desc="Another part of the jungle. Damp air, vibrant plantlife, "+
      "lots of mosquitos and other annoying insects. All you can see "+
      "around you is jungle. Getting bored?\n";
   set_light(1);
   dest_dir=({
      "/players/gorlin/elephant_jungle/rooms/jungle2","east",
      "/players/gorlin/elephant_jungle/rooms/jungle5","southwest",
      "/players/gorlin/elephant_jungle/rooms/jungle6","south",
   });
   items=({
      "insects","They swarm around you, and being small and fast, "+
         "it is hell trying to squat them.",
   });
   smell="The air smells somewhat damp, but it's not too unpleasant.";
   replace_program("room/room");
   return;
}
