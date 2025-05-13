/* Gorlin, 15.10.1996 */

inherit "room/room";

void reset (int arg) {

   ::reset (arg);
   if (arg) return;

   short_desc="Jungle";
   long_desc="You stand at the beginning of a tremendously large "+
      "jungle. In all directions around you there are plants and "+
      "buzzing insects. To the north, the jungle is getting lighter, "+
      "it seems you can leave the jungle this way.\n";
   set_light(1);
   dest_dir=({
      "/players/gorlin/elephant_jungle/rooms/path","north",
      "/players/gorlin/elephant_jungle/rooms/jungle2","south",
   });
   items=({
      "insects","They swarm around you, and being small and fast, "+
         "it is hell trying to squat them.",
   });
   smell="The air smells somewhat damp, but it's not too unpleasant.";
   replace_program("room/room");
   return;
}
