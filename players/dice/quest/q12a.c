inherit "room/room";
object tr_hole2;
reset(arg) {
    if (arg) return;

       if(!tr_hole2){
       tr_hole2=clone_object("players/dice/quest/tr_hole2");
         move_object(tr_hole2,this_object());
         }
    set_light(0);
    short_desc = "Cellar";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
           "You are standing in the middle of the cellar under the house.\n"+
           "You can see strange walls surrounding the cellar.\n"+
           "These walls must form the foundation of the house.\n"+
           "The floor is covered with stones.\n";
          items = ({
             "cellar","A small cellar under the house",
    "walls","Walls forming the foundation of the house, there seems to be a large crack in it",
             "crack","A crack in the wall, it looks like the wall is broken",
              "wall","A solid wall with a huge crack in it",
             "floor","It's covered with big solid stones",
  "stones","Stones lying all over the place after getting them from the floor",
              "foundation","The stuff the house was built upon",
              });

    smell = "The air smells dull here.";
}
init(){  
    ::init(); 
  add_action("move_stone","move");
  add_action("break_walls","break");add_action("break_walls","tear");
  add_action("break_walls","kick"); add_action("break_walls","smash");
  }
move_stone(str){
  if(!str){
  notify_fail("Move what ?\n");
  return 0;
  }
if((str=="stone")||(str=="stones")){
  if(tr_hole2){
  write("You don't want to cover the hole again.\n"+
       "it might be your only way out.\n");
  return 1;
  }
  else{
  write("With great effort you move the stones and discover a hole.\n");
  tr_hole2=clone_object("players/dice/quest/tr_hole2");
  move_object(tr_hole2,this_object());
  return 1;
  }
 }
}
break_walls(str){
 if(!str){
 notify_fail("Break what ?\n");
 return 0;
 }
if((str=="walls")||(str=="wall")){
  write("You break down the wall and fall right through it.\n");
  this_player()->move_player("through the wall#players/dice/quest/q13");
  return 1;
  }
}
