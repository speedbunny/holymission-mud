

inherit "room/room";

object mindaugh;

reset(arg){::reset(arg);
   if(!arg){
           if(!mindaugh)
           mindaugh=clone_object("/players/dice/obj/mindaugh");
           move_object(mindaugh,this_object());
           }


if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Miners daughter's room";
   long_desc =
     "This room has recently been rebuild.\n"+
     "All done by the Coalminer himself of course.\n"+
     "Two pictures are hanging on the wall.\n";

   dest_dir = ({
      "players/dice/rooms/house1","west"
             });

   items =({
          "picture 1","A beautiful picture of the miners daughter",
          "picture 2","A picture of the entire family",
          "family","Mam, dad, son and daughter coalminer",
          "picture","Which picture 1 or 2 ??",
          "pictures","Which picture 1 or 2 ??"
          });

   smell = "This room smells like it has been rebuild lately.";

}
