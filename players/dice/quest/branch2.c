inherit "/obj/thing";

reset(arg) {
  if (arg) return 1;
  set_alt_name("branch");
  set_short("A branch laying over the river");
  set_long("A branch laying over the river.\nIt fits very well.\n");
  can_get = 0;
  set_weight(2);
  return 1;
}

query_objmaker() { return 1; }
init(){
  add_action("lay_branch","lay"); add_action("lay_branch","put");
  add_action("walk_over","walk"); add_action("walk_over","step");
   add_action("walk_over","cross");
  }
lay_branch(str){
   if(!str){
    notify_fail("Lay what where ?\n");
    return 0;
    }
if((str=="branch over river")||(str=="branch over water")){
   write("It's already placed over the river.\n");
   return 1;
   }
 }
walk_over(str){
   if(!str){
    notify_fail("Walk where ?\n");
   return 0;
   }
if((str=="over branch")||(str=="over water")||(str=="over river")){
  write("You carefully walk over the branch across the river.\n");
  call_out("een_funktie",1);
  call_out("een_funktie",2);
  call_out("nog_een_funktie",3);
  return 1;
  }
}
een_funktie() {
write("You carefully walk over the branch.\n"+
      "The branch makes a cracking sound ! \n\n\n");
return;
}

nog_een_funktie() {
write("The branch breaks with a SNAPP, what's left\n"+
  "of the branch falls in the river, and is flushed away on the stream.\n"+
  "You manage to jump to the other side of the river.\n"+
  "You are please you did not fall into the water.\n"+
   "Probably you would not have survived a dip in that cold water.\n");
say(this_player()->query_name()+" jumps over the last pieces of the branch.\n")
;
say("The branch falls to pieces and falls in the river.\n"+
 "What's left of it, falls in the river and is flushed away.\n");
this_player()->move_player("over the branch#players/dice/quest/q5");
destruct(this_object());
return;
}
