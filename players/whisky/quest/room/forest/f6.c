#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f2","south",
      FORST+"f5","east",
      FORST+"f7","west",
      FORST+"f12","north",
      }); 
   
   }
 
