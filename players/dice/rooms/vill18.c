

inherit "room/room";

reset(arg){::reset(arg);
  if(!arg){

 if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village";
   long_desc =
     "You are in the almost the utter eastern part of the coalminer village.\n"+
     "The pavement here looks well kept.\n"+
     "The houses have almost disappeared here, maybe something strange is going on.\n"+
     "To the east you see a strange building standing just south of the road.\n";
   dest_dir = ({
      "players/dice/rooms/vill17","west",
      "players/dice/rooms/vill19","east"
       });

   items =({
            "pavement","A kind of road, but better plaved and better kept",
            "building","A strange building, it seems to emit a blue cold light",
            "strange building","A strange building to the east, it seems to emit a cold blue light",
            "house","One of the last houses of the village",
            "houses","The last houses of the village",
            "village","Coalminer village"
            });


 }
   smell = "The slight smell of ozone comes from the east.\n";
}
