#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f51","northeast",
      FORST+"f32","south",
      FORST+"f33","southwest",
      FORST+"f41","east",
      }); 
   
   }
 
