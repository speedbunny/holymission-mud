#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f38","north",
      FORST+"f19","southeast",
      FORST+"f28","west",
      FORST+"f26","east",
      }); 
   
   }
 
