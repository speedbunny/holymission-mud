#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f40","north",
      FORST+"f20","south",
      FORST+"f31","west",
      FORST+"f29","east",
      }); 
   
   }
 
