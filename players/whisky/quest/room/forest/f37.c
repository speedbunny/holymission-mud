#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f47","north",
      FORST+"f26","south",
      FORST+"f38","west",
      FORST+"f36","east",
      }); 
   
   }
 
