#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f69","southeast",
      FORST+"f70","south",
      FORST+"f78","west",
      FORST+"f76","east",
      }); 
   
   }
 
