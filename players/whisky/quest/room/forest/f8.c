#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f14","north",
      FORST+"f4","south",
      FORST+"f9","west",
      FORST+"f7","east",
      }); 
   
   }
 
