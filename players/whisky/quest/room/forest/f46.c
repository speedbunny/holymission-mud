#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f35","southeast",
      FORST+"f36","south",
      FORST+"f47","west",
      FORST+"f45","east",
      }); 
   
   }
