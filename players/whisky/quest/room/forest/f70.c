#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f77","north",
      FORST+"f63","south",
      FORST+"f71","west",
      FORST+"f69","east",
      }); 
   
   }
