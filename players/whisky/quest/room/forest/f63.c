#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f70","north",
      FORST+"f57","southwest",
      FORST+"f64","west",
      FORST+"f62","east",
      }); 
   
   }
