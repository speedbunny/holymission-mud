#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f42","north",
      FORST+"f22","south",
      FORST+"f33","west",
      FORST+"f31","east",
      }); 
   
   }
 
