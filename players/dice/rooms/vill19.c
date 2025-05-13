

inherit "room/room";

object minekid;

reset(arg){::reset(arg);
  if(!arg){
   if(!minekid){
    minekid=clone_object("players/dice/obj/minekid");
    move_object(minekid,this_object());

 if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village";
   long_desc =
     "You are in the the utter eastern part of the coalminer village.\n"+
    "The pavement looks neglected here, maybe nobody wants to come here.\n"+
     "The houses have gone completely here, maybe cause something \n"+
     "strange has been happening here.\n"+
     "To the south you see a strange building.\n";
   dest_dir = ({
      "players/dice/rooms/vill18","west",
      "players/dice/rooms/vill20","south"
       });

   items =({
            "pavement","A kind of road almost entirly gone, and not kept \n"+
                       "maybe nobody wants to come here anymore",
            "building","A strange building to the south, it seems to emit a blue cold light",
            "strange building","A strange building to the south, it seems to emit a cold blue light",
            "path","A kind of road, almost entirely gone, and not kept \n"+
                   "maybe nobody wants to come here anymore",
            "house","One of the last houses of the village standing west of you",
            "houses","The last houses of the village standing west of you",
            "village","Coalminer village"
            });


   smell = "The strong smell of ozone comes from the south.\n";
  }
 }
}
