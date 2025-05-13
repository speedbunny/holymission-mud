

inherit "room/room";
object bee;
int i;

reset(arg){::reset(arg);
   if (arg) return;
  if (!bee){
    for (i=0;i<5;i++) {
    bee = clone_object("/players/dice/obj/bee");
    move_object(bee,this_object());
    }
  }

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Tree";
   long_desc =
     "You find yourself in the middle of a bee colony, this place\n"+
     "is covered with bees.\n"+
     "They are crawling all over the place.\n";
   dest_dir = ({
      "players/dice/rooms/tree1","down"
       });

   items =({
            "tree","A HUGE hollow tree with no exits yet.",
            "gods","If they were here, you might not even see them",
            "place","A really rustique place to be"
            });


   smell = "The smell of old woods is VERY strong here.\n";
 }
