#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f78","north",
      FORST+"f64","south",
      FORST+"f72","west",
      FORST+"f70","east",
      }); 
   
   }
