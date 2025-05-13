inherit "room/room";
string crack_desc;
status has_started;
object qst;
 reset(arg){
 has_started = 0;
    crack_desc = "A crack in the tree, large enough to enter";
    set_light(1);
    property = "no_teleport";
    short_desc = "Wood";
    long_desc=
              "You are standing in the middle of some strange woods.\n"+
              "The trees are surrounding this place completely.\n"+
              "To the far east you see the outlines of a small village.\n"+
              "One tree is standing alone in the middle of this plain.\n";
    dest_dir = ({ "players/avatar/room/room24.c","north" });
    items = ({
      "woods","Lots of trees surrounding you",
      "trees","Large trees",
      "tree","One single tree, with a large crack in it",
      "village","A small village",
      "plain","An open place in the woods",
      "crack", "@@query_crack_desc@@",
    });

    smell ="The smell of fresh woods is strong.";
}
init(){  
  ::init(); 
 add_action("step","step");
  add_action("enter","enter");
  add_action("climb_tree","climb");
}

enter(str){
  if(!str){
 notify_fail("Enter what ?\n");
    return 0;
  }
if((str=="crack")||(str=="tree")){
    if(has_started == 1 && !present("qst",this_player())){
      write("The crack is too small to enter.\n"+
	    "You hear strange noises coming from inside the tree.\n");
      return 1;
    }
  if(!this_player()->query_frog()){ write("You are too big to enter this tree\n");
  return 1;
 }
    if(present("qst",this_player())){
      this_player()->move_player("into the tree#players/dice/quest/q1");
      say(this_player()->query_name()+
	  " steps into the tree, the crack closes immediately.\n");
      has_started = 1;
      return 1;
    }
    else{
      write("You step into the tree and are transferred to another world.\n");
      say(this_player()->query_name()+
	  " steps into the tree, the crack closes immediately.\n");
      qst=clone_object("players/dice/quest/qst");
      move_object(qst,this_player());
      this_player()->move_player("into the tree#players/dice/quest/q1");
      has_started = 1;
      return 1;
    }
  }
}

climb_tree(str){
  if(!str){
    notify_fail("Climb what ?\n");
    return 0;
  }
  if((str=="single tree")||(str=="tree")){
    write("With great effort you climb up the tree.\n");
    this_player()->move_player("up the tree#players/dice/quest/tr");
    return 1;
  }
}

query_crack_desc() {
  if (has_started) {
    return "The crack is too small to enter.\n" +
      "You hear strange noises coming from inside the tree";
  }
  else
    return crack_desc;
}
/* this room works with a good definition for the open and closed crack thanx
   to the efford of both Helenette and Dancer !!!
   I really appreciated the help they gave me !!!
*/
