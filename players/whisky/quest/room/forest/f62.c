#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f69","north",
      FORST+"f55","southeast",
      FORST+"f63","west",
      FORST+"f61","east",
      }); 
   
   }
