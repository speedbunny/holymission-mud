#define FORST "players/whisky/quest/room/forest/"

inherit "players/whisky/quest/room/room_forest";
 object stone;

reset(arg) {

  if (!stone) {
     stone=clone_object("players/whisky/quest/obj/ruby");
     move_object(stone,this_object());
     }
     
  ::reset(arg);
   if (arg) return;
   
  dest_dir= ({     
      FORST+"f55","east",
      }); 
   
   }
