#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f9","south",
      FORST+"f14","east",
      FORST+"f16","west",     
      }); 
   
   }
 
