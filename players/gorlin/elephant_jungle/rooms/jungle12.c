/* Gorlin, 30.4.1998 */

inherit "room/room";

void reset (int arg) {

   clone_list=({
      1, 3, "tiger", "/players/gorlin/elephant_jungle/monsters/tiger", 0,
   });
      
   ::reset (arg);
   if (arg) return;

   short_desc="Jungle";
   long_desc="A dead end, in the middle of the jungle. Let's just turn back "+
      "pretend that we never went here, right?\n";
   set_light(1);
   dest_dir=({  
      "/players/gorlin/elephant_jungle/rooms/jungle9","north",
    });
   items=({
      "insects","They swarm around you, and being small and fast, "+
         "it is hell trying to squat them.",
   });
      
   smell="The air smells somewhat damp, but it's not too unpleasant.";
   replace_program("room/room");
   return;
}
 
