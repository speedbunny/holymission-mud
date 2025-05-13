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
  call_out("een_funktie",2);
  call_out("een_funktie",4);
  call_out("nog_een_funktie",6);
  return 1;
  }
}
een_funktie() {
write("The branch makes a cracking sound ! \n\n\n");
return;
}

nog_een_funktie() {
write("The branch breaks with a SNAPP, what's left\n"+
      "of the branch fall in the river and gets flushed away.\n\n\n");
this_player()->move_player("over the branch#players/dice/quest/q5");
destruct(this_object());
return;
}
