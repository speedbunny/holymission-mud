#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({     
      FORST+"f53","west",
      FORST+"f51","east",
      }); 
   
   }
