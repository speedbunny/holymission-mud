#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f43","northwest",
      FORST+"f22","southeast",
      FORST+"f42","northeast",
      FORST+"f32","east",
      }); 
   
   }
 
