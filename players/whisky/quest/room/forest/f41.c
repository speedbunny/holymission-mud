#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f51","north",
      FORST+"f31","south",
      FORST+"f42","west",
      FORST+"f40","east",
      }); 
   
   }
 
