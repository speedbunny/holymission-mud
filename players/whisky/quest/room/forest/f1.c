#define FORST "players/whisky/quest/room/forest/"

inherit "/players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f3","north",
      "players/whisky/quest/room/forest_entrance","south",
      FORST+"f4","northwest",
      FORST+"f2","northeast",
      }); 
   
   }
 
