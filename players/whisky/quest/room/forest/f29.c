#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f39","north",
      FORST+"f20","southwest",
      FORST+"f30","west",
      FORST+"f28","east",
      }); 
   
   }
 
