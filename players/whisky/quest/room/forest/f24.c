#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f35","north",
      FORST+"f17","south",
      FORST+"f25","west",
      FORST+"f23","east",
      }); 
   
   }
 
