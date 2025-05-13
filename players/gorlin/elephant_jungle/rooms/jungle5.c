/* Gorlin, 15.10.1996 */

inherit "room/room";

void reset (int arg) {

   ::reset (arg);
   if (arg) return;

   short_desc="Jungle";
   long_desc="More jungle. The air is getting damper, and the insects "+
      "more aggressive. There is still nothing but jungle, in all directions.\n";
   set_light(1);
   dest_dir=({
      "/players/gorlin/elephant_jungle/rooms/jungle4","northeast",
      "/players/gorlin/elephant_jungle/rooms/jungle9","south",
   });
   items=({
      "insects","They swarm around you, and being small and fast, "+
         "it is hell trying to squat them.",
   });
   smell="The air smells damp.";
   replace_program("room/room");
   return;
}
