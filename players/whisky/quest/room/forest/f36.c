#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f46","north",
      FORST+"f25","south",
      FORST+"f37","west",
      FORST+"f35","east",
      }); 
   
   }
 
