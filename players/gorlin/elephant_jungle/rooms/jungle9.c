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
   long_desc="Yet another part of the jungle. The air is very damp, and the "+
      "insects attack you more aggressively than ever.\n";
   set_light(1);
   dest_dir=({
      "/players/gorlin/elephant_jungle/rooms/jungle5","north",
      "/players/gorlin/elephant_jungle/rooms/jungle10","east",     
      "/players/gorlin/elephant_jungle/rooms/jungle12","south",
    });
   items=({
      "insects","They swarm around you, and being small and fast, "+
         "it is hell trying to squat them.",
   });
 
   smell="The air smells somewhat damp, but it's not too unpleasant.";
   replace_program("room/room");
   return;
}

