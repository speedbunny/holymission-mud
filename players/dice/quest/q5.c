inherit "room/room";
object q_hole;
int has_drunk;
reset(arg) {
   has_drunk = 0;
    if (arg) return;
    set_light(1);
    property = "no_teleport";
    short_desc = "Trees";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
        "You have walked over the river and are standing on the other side.\n"+
        "You don't think that you would have survived a dip in the cold water.\n"+
"In front of you there is a big forest.\n"+
        "One tree is standing all alone here.\n"+
         "Behind the forest you see a small volcano.\n";
          items = ({
              "river","A small river, flowing very fast",
              "side","The other side of the river",
              "shore","The other shore of the river",
              "water","Cold water",
               "volcano","A small restless volcano",
               "black hole","It looks like a dark black hole",
              "cold water","Really cold water",
              "forest","A big forest which looks impossible to enter",
              "big forest","A big forest, it look impossible to enter",
              "tree","An old tree, the roots look damaged",
              "trees","Old trees, the roots look damaged",
              "roots","It looks like someone dug around them",
              "root","It looks like someone dug around it",
              "sound","It's quiet",
              });

     smell = "The air smells fresh here.";
}
init(){  
    ::init(); 
    add_action("enter_forest","enter");
    add_action("dig","dig");
    add_action("swim","swim"); add_action("swim","jump");
    add_action("feel_water","feel"); add_action("feel_water","touch");
   add_action("drink_water","drink");
   add_action("climb_tree","climb");
   }
enter_forest(str){
    if(!str){
     notify_fail("Enter what ?\n");
     return 0;
     }
     if((str=="forest")||(str=="big forest")){
      this_player()->move_player("into the forest#players/dice/quest/fo1");
     return 1;
    }
  }
dig(str){
   if(!str){
   notify_fail("Dig where ?\n");
   return 0;
   }
if((str=="under roots"||str=="roots"||str=="at roots")){
      if(q_hole){
      write("There already is a hole, there is no need to dig further.\n");
      return 1;
      }
       if(!q_hole){
  write("You dig under the roots of the tree, and discover a black hole.\n"+
        "This hole is dark and frightening.\n");
     say(this_player()->query_name()+" has dug a hole.\n");
        q_hole=clone_object("players/dice/quest/q_hole");
        move_object(q_hole,this_object());
        return 1;
        }
     }
 }
swim(str){
  if(!str){
  notify_fail("Swim where ?\n");
  }
if((str=="in water")||(str=="in river")){
   write("You jump into the water, not realising how cold the water was.\n"+
         "You jump out of the water, and dry yourself as fast as you can.\n");
         this_player()->hit_player(20,3);
   return 1;
   }
  } 
feel_water(str){
  if(!str){
  notify_fail("Feel what ?\n");
  return 0;
  }
if((str=="water")||(str=="river")){
   write("You reach out, and touch the water.\n"+
         "It's extremely cold and fresh.\n");
   return 1;
   }
  }
drink_water(str){
if(!str){
 notify_fail("Drink what ?\n");
 return 0;
 }
 if((str=="water")||(str=="water from river")){
 if(has_drunk ==1){
 notify_fail("The water is too cold to drink more.\n");
 return 0;
 }
 write("You bend over and drink from the cold refreshing water.\n");
 this_player()->heal_self(20);
 this_player()->show_hp();
 say(this_player()->query_name()+" drinks from the water.\n");
 has_drunk = 1;
 return 1;
}
}
climb_tree(str){
 if(!str){
 notify_fail("Climb what ?\n");
 return 1;
 }
if((str=="tree")||(str=="old tree")){
 write("You try to climb up the tree, but fail.\n");
 say(this_player()->query_name()+" tried to climb up the tree, but fails.\n");
 return 1;
 }
 }
