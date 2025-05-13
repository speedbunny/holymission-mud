/* Gorlin, 30.4.1998 */

inherit "room/room";

void reset (int arg) {

   ::reset (arg);
   if (arg) return;
   
   short_desc="Jungle";
   long_desc="Another part of the jungle. Damp air, vibrant plantlife, even "+
      "more vibrant insectlife... There are two paths leading onward into the "+
      "jungle from here on, besides the way back.\n";
   set_light(1);
   dest_dir=({  
      "/players/gorlin/elephant_jungle/rooms/jungle9","west", 
      "/players/gorlin/elephant_jungle/rooms/jungle11","east", 
      "/players/gorlin/elephant_jungle/rooms/jungle13","southeast",
       
    });
   items=({
      "insects","They swarm around you, and being small and fast, "+
         "it is hell trying to squat them.",
   });
   
   smell="The air smells somewhat damp, but it's not too unpleasant.";
   replace_program("room/room");
   return;
}
 
