#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f69","northwest",
      FORST+"f54","southeast",
      FORST+"f62","west",
      FORST+"f68","north",    
      }); 
   
   }
