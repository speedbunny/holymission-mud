#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f77","northwest",
      FORST+"f62","south",
      FORST+"f70","west",
      FORST+"f61","southeast",
      }); 
   
   }
