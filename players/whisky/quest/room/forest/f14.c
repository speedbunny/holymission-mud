#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f8","south",
      FORST+"f13","east",
      FORST+"f15","west",     
      }); 
   
   }
 
