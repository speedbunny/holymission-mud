#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f41","north",
      FORST+"f21","south",
      FORST+"f32","west",
      FORST+"f30","east",
      }); 
   
   }
 
