#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f21","north",
      FORST+"f9","southeast",
      FORST+"f22","northwest",
      FORST+"f12","west",     
      }); 
   
   }
 
