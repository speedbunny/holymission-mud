#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f7","north",
      FORST+"f4","west",
      FORST+"f2","east",
      FORST+"f1","south",
      }); 
   
   }
 
