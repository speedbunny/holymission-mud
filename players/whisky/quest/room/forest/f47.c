#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({     
      FORST+"f37","south",
      FORST+"f48","west",
      FORST+"f46","east",
      }); 
   
   }
