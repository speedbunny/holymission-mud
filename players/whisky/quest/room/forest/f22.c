#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f32","north",
      FORST+"f16","southeast",
      FORST+"f33","northwest",
      FORST+"f21","east",
      }); 
   
   }
 
