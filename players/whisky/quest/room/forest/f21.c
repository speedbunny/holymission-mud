#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f31","north",
      FORST+"f16","south",
      FORST+"f22","west",
      FORST+"f20","east",
      }); 
   
   }
 
