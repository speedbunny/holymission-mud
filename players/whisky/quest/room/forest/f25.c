#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f36","north",
      FORST+"f18","south",
      FORST+"f26","west",
      FORST+"f24","east",
      }); 
   
   }
 
