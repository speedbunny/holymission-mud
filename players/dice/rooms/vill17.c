

inherit "room/room";

reset(arg){::reset(arg);
  if(!arg){

 if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village";
   long_desc =
     "You are in the eastern part of the coalminer village.\n"+
     "The pavement here looks well kept.\n"+
     "The houses here look well decorated, and in good condition.\n"+
     "To the far east you see a strange building standing just south of the road.\n";
   dest_dir = ({
      "players/dice/rooms/vill10","west",
      "players/dice/rooms/vill18","east"
       });

   items =({
            "pavement","A kind of road, but better paved and better kept",
            "building","A strange building, it seems to emit a blue cold light",
            "strange building","A strange building to the east, it seems to emit a cold blue light",
            "house","A well decorated house",
            "houses","Well decorated houses surrounding you"
            });


 }
   smell = "The slight smell of ozone comes from the far east.\n";
}
