
inherit "room/room";
query_no_teleport() {return 1;}


object agrabbit;

reset(arg) {
    ::reset(arg);
    if(!arg){
           if(!agrabbit)
           agrabbit=clone_object("/players/dice/obj/agrabbit");
           move_object(agrabbit,this_object());
           }

 if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Twilight Zone";
   long_desc =
     "You are walking on a track to the village. There\n"+
     "is green grass growing on the sides of the track.\n"+
     "To the north you can see the eastern side of the church.\n";
   dest_dir = ({
      "players/dice/2light/2l2","west",
      "players/dice/2light/mz1","north"
       });

   items =({
            "grass","Green grass",
            "green grass","Normal green grass, you can not smoke it",
            "church","A looks like a normal church",
            "ground","Seems like glass, you can see through it\n"+
                     "but can not regonize anything below it.\n"+
                     "It seems like strange figures are moving below your feet\n",
            "figures","You can not regonize them from here",
            "zone","The Twilight Zone",
            "twilight zone","A strange, bizar world between fantasy and reality"
            });


   smell = "Smells weird here.\n";

 }
