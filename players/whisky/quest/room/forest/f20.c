#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";

reset(arg) {
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({
      FORST+"f29","northeast",
      FORST+"f16","southwest",
      FORST+"f21","west",
      FORST+"f30","north",
      }); 
   
   }
 
