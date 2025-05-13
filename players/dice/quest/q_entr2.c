inherit "room/room";
int has_started;
object qst;
reset(arg) {
    if (arg) return;
    has_started = 0;

    set_light(1);
    property = "no_teleport";
    short_desc = "Wood";
    no_castle_flag = 1;
    long_desc=
              "You are standing in the middle of some strange woods.\n"+
              "The trees are surrounding this place completely.\n"+
              "To the far east you see the outlines of a small village.\n"+
              "One tree is standing alone in the middle of this plain.\n";
       dest_dir =({ "players/dice/rooms/e_city","east" });
          items = ({
                    "woods","Lots of trees surrounding you",
                    "trees","Large trees",
                    "tree","One single tree, with a large crack in it",
                    "village","A small village",
                    "plain","An open place in the woods",
                    "crack","A crack in the tree, large enough to enter",
              });

    smell ="The smell of fresh woods is strong.";
}
init(){  
    ::init(); 
 add_action("enter_tree","enter"); add_action("climb_tree","climb");
 }
enter_tree(str){
  if(!str){
   notify_fail("Enter what ?\n");
   return 0;
   }
if((str=="crack")||(str=="crack in tree")||(str=="tree")){
   if(has_started == 1 && !present("qst",this_player())){
     write("The crack is too small to enter.\n"+
           "You hear strange noises coming from inside the tree.\n");
   return 1;
   }
  if(present("qst",this_player())){
  this_player()->move_player("into the tree#players/dice/quest/q1");
  say(this_player()->query_name()+
  " steps into the tree, the crack closes immediately.\n");
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
