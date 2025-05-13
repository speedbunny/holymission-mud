
/* Gorlin, 15.10.1996 */

inherit "room/room";

void reset (int arg) {

   ::reset (arg);
   if (arg) return;

   short_desc="Jungle";
   long_desc="A dead end. The vegetation around you is too dense "+
      "to let you pass. The air is still damp, and the insects are still "+
      "there too...\n";
   set_light(1);
   dest_dir=({
      "/players/gorlin/elephant_jungle/rooms/jungle2","west",
   });
   items=({
      "insects","They swarm around you, and being small and fast, "+
         "it is hell trying to squat them. Try insect repellents...",
   });
   smell="The air smells somewhat damp, but it's not too unpleasant.";
   replace_program("room/room");
   return;
}
