#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f25","north",
      FORST+"f10","south",
      FORST+"f19","west",
      FORST+"f17","east",
      }); 
   
   }
 
