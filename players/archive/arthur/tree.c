inherit "room/room";

void reset(int arg) {
   if (arg) return;
   set_light(1);
   short_desc = "A corner of the forest, there is a tree here";
   long_desc =
        "You are in a corner of the forest. There is a tree here that seems to\n" +
        "attract your attention.\n";
   items=({"tree","The tree seems to have a crack in it",
        "crack","It seems to have been formed from lightning, the is a piece of wood in it",
        "wood","The wood is very sturdy, perhaps you could break it off?"
        "forest","It looks like your ordinary forest"});
   dest_dir=({"players/tanthalas/area/f11","northeast"});
 }
init () {
        ::init();
        add_action("break","get");
        add_action("break","take");
        add_action("break","break");
 }
break(str) {
   if(!str)
        return;
     {
      if(str == "wood off of tree" || str == "wood from tree" 
         str == "wood off" || str == "wood")
       {
        write("You break the wood off of the tree.\n");
        move_object(clone_object("players/tanthalas/objs/wood"),this_player());
        return 1;
       }
      if(str == "tree" || str == "crack")
       {
        write("Try phrasing that in another way.\n");
        return 1;
       }
      return 0;
     }
     return 0;
 }

