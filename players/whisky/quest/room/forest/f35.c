#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f46","northwest",
      FORST+"f23","southeast",
      FORST+"f36","west",
      FORST+"f24","south",
      }); 
   
   }
 
