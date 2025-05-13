

inherit "/players/dice/rooms/sleep";
reset(arg){::reset(arg);
  if(!arg){
 if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Tree";
   long_desc =
     "You stand in the middle of a hollow tree, it's peaceful,\n"+
     "and quiet here, you feel the gods with you.\n"+
     "This is a comforting place and you'd like to stay here forever. \n";
   dest_dir = ({
      "players/dice/rooms/vill12","out",
       "players/dice/rooms/tree2","up"
       });

   items =({
            "tree","A HUGE hollow tree",
            "gods","If they were here, you might not even see them",
            "place","A really rustique place to be"
            });


   smell = "The smell of old woods is VERY strong here.\n";
 }
}
