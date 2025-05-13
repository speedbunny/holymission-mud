/* Gorlin, 30.4.1998 */

inherit "room/room";

void reset (int arg) {

   ::reset (arg);
   if (arg) return;

   short_desc="Jungle";
   long_desc="You are still in the middle of the jungle. The air is moist, "+
      "the insects annoying, and even worse, this seems to be a dead end.\n";
   set_light(1);
   dest_dir=({  
      "/players/gorlin/elephant_jungle/rooms/jungle7","west",
   });
   items=({
      "insects","They swarm around you, and being small and fast, "+
         "it is hell trying to squat them.",
   });
      
   smell="The air smells somewhat damp, but it's not too unpleasant.";
   replace_program("room/room");
   return;
}
 
