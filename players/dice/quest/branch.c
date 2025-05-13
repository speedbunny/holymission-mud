inherit "/obj/treasure";
object branch2;
reset(arg) {
  if (arg) return 1;
  set_id("branch");
  set_short("A broken branch");
 set_long("A broken branch, it looks strong enough to carry your weight.\nMaybe you should put it somewhere.\n");
  set_value(0);
  set_weight(2);
  return 1;
}

query_objmaker() { return 1; }
init(){
  add_action("lay_branch","lay"); add_action("lay_branch","put");
 add_action("break_branch","break");
  }
lay_branch(str){
   if(!str){
    notify_fail("Lay what where ?\n");
    return 0;
    }
 if((str=="branch over water")||(str=="branch over river")||(str=="branch across river")){
   write("You lay the branch over the river, and see that it perfectly\n"+
         "fits between the two shores.\n"+
         "Maybe now you can walk over it to the other side of the river.\n");
        say(this_player()->query_name()+" lays a branch over the river.\n");
         branch2=clone_object("players/dice/quest/branch2");
          move_object(branch2,"/players/dice/quest/q4");
         destruct(this_object());
   return 1;
   }
  }
break_branch(str){
  if(!str){
    notify_fail("Break what ?\n");
   return 0;
   }
if((str=="branch")||(str=="broken branch")){
write("You don't want to break the branch.\n");
 return 1;
  }
  }
