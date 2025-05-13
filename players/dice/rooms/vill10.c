
inherit "room/room";
object minekid;

reset(arg){::reset(arg);
  if(!arg){

           if(!minekid)
  move_object(minekid=clone_object("/players/dice/obj/minekid"),this_object());

 if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village";
   long_desc =
     "You are in the northeastern part of the village.\n"+
     "The stench of coals gets a bit heavier here.\n"+
     "You can see the eastern part of the working place to the north. \n"+
     "Laughter comes from the far east. \n";
   dest_dir = ({
      "players/dice/rooms/vill9","west",
      "players/dice/rooms/vill17","east"
       });

   items =({
            "working place","A small area which is used to clean the coals.",
            "place","A small area which is used to clean the coals.",
            "laughter","Laughter coming from the east."
            });


   smell = "The smell of coals gets stronger and it come from the northeast .\n";
 }
}
