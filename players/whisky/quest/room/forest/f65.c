#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f72","north",
      FORST+"f57","southeast",
      FORST+"f66","west",
      FORST+"f64","east",
      }); 
   
   }
