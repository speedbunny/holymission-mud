#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f40","south",
      FORST+"f51","west",
      FORST+"f49","east",
      }); 
   
   }
