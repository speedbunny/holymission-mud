
/* Gorlin, 30.4.1998 */

inherit "room/room";

void reset (int arg) {

   clone_list=({
      1, 2, "grey elephant", "/players/gorlin/elephant_jungle/monsters/elephant", 0,
     -1, 2, "elephant tusk", "/players/gorlin/elephant_jungle/obj/tusk", 0,
   });
      
   ::reset (arg);
   if (arg) return;

   short_desc="Jungle";
   long_desc="Another part of the jungle. The air is moist, and luckily  "+
      "for you the insects have resumed their bloodhunt. Some days people "+
      "should just have remained at home.\n";
   set_light(1);
   dest_dir=({  
      "/players/gorlin/elephant_jungle/rooms/jungle6","west",
      "/players/gorlin/elephant_jungle/rooms/jungle8","east",
   });
   items=({
      "insects","They swarm around you, and being small and fast, "+
         "it is hell trying to squat them.",
   });
      
   smell="The air smells somewhat damp, but it's not too unpleasant.";
   replace_program("room/room");
   return;
}
 
