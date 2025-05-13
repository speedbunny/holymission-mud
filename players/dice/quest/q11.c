inherit "room/room";
object trapd;
status is_trapd_open;
reset(arg) {
   if(arg)
    { if(trapd) destruct(trapd); }

    set_light(1);
    property = "no_teleport";
    short_desc = "House";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
             "You are standing in a small one-room house.\n"+
             "The owner must be a really small guy, you barely fit\n"+
             "under the ceiling.\n"+
             "A small chair is standing here in the middle of the room.\n"+
             "And a small bed is standing in the corner.\n";
          items = ({
                     "room","A small cosy room",
                     "owner","He is not here at the moment",
                     "ceiling","The ceiling of the house",
                     "chair","A small chair with floral print, it looks movable",
               "small chair","A small chair with floral print, it looks moveable",
                     "bed","A small bed",
                "small bed","A normal bed",
              });

     smell = "You don't smell anyting special.";
}
init(){  
    ::init(); 
 add_action("sleep","sleep"); add_action("move_chair","move");
 add_action("move_chair","push");
 add_action("sit_chair","sit");
 add_action("leave_house","leave");
add_action("enter_bed","enter");
  }
sleep(str){
  if(!str){
  notify_fail("Sleep where ?\n");
  return 0;
  }
if((str=="in bed")||(str=="on bed")){
  write("You lie down on the bed, and close your eyes.\n"+
        "You attempt to get some sleep.\n"+
        "However, you aren't successful.\n"+
        "So you decide to get up, and move on.\n");
  return 1;
  }
}
move_chair(str){
  if(!str){
  notify_fail("Move what ?\n");
  return 0;
  }
if((str=="chair")||(str=="small chair")){
  if(trapd){
  if(trapd->query_open())
    { 
      write("You can't!, the trapdoor is open!\n");
      return 1;
    }
  write("You place the chair back on the trapdoor.\n");
  destruct(trapd);
  return 1;
  }
  else{
  write("You carefully move the small chair, and discover a trapdoor.\n");
  trapd= clone_object("players/dice/quest/trapd");
  trapd->set_open(is_trapd_open);
  move_object(trapd,this_object());
   return 1;
  }
 }
}
sit_chair(str){
  if(!str){
  notify_fail("Sit where ?\n");
  return 0;
  }
if((str=="in chair")||(str=="on chair")){
   write("You carefully sit down in the small chair,\n"+
       "it seems to be strong enough to carry your weight.\n");
   return 1;
   }
 if((str=="on bed"||str=="in bed")){
 write("You sit on the bed, it feels pretty comfortable,\n"+
      "but you don't think the owner would appreciate it when you sit on \n"+
   "his bed, so you get up again.\n");
say(this_player()->query_name()+" sits down on the bed, thinks for a while, and then decides to get up again.\n");
 return 1;
 }
}
leave_house(str){
 if(!str||str=="house"){
  write("You leave the house\n");
  this_player()->move_player("out of the house#players/dice/quest/q10");
  return 1;
  }
}
enter_bed(str){
 if(!str||str==!"bed"){
 notify_fail("Enter what ?\n");
 return 0;
 }
 if((str=="bed"||str=="small bed")){
 write("You carefully step on the bed, and try to get some sleep.\n"+
 "However, the sleep won't come, so you decide to get up again.\n");
say(this_player()->query_name()+" lays down on the small bed and closes "+this_player()->query_possessive()+" eyes.\nAfter a while "+this_player()->query_pronoun()+" opens "+this_player()->query_possessive()+" eyes, and gets up again.\n");
return 1;
 }
}
set_trap(i) { is_trapd_open=i; }
