

inherit "room/room";

object litrat;

reset(arg){
  if(!litrat){
   litrat=clone_object("/players/dice/obj/litrat");
   move_object(litrat,this_object());
   }


if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Alley";
   long_desc =
     "You have entered a small alley.\n"+
     "This place smells like rotten eggs, as you see a few garbage cans\n"+
     "lying around.\n"+
     "They were probably thrown aside by some little boys.\n";

   dest_dir = ({
      "players/dice/rooms/vill2","south",
      "players/dice/rooms/alley2","north"
             });
   items = ({
           "trashcan","A small trascan thrown aside by a coalminer boy",
           "trashbin","A small trashbin thrown aside by a coalminer boy",
           "can","a small trashcan",
           "bins","Small trashcans thrown aside by a coalminer kid",
           "trashcans","Small trashcans thrown aside by a coalminer boy",
           "trashbins","Small trashcans thrown aside by a coalminer kid",
           "kid","He left after doing this evil thing",
           "boy","He left after doing this evil thing",
           "cans","Small trashcans thrown aside by a coalminer kid",
           "bin","a small trashbin",
           "alley","a small alley leading further north"
           });


   smell = "The smell of rotten eggs fills your nose.\n";

 }
