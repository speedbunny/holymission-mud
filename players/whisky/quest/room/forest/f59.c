#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({     
      FORST+"f67","northwest",
      FORST+"f58","east",
      }); 
   
   }
