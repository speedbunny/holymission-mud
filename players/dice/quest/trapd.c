inherit "/obj/thing";
int open;

reset(arg) {
  if (arg) return 1;
  set_name("A small trapdoor");
   set_alias("trapdoor");
   open = 0;
    set_short("A small trapdoor (closed)");
    set_long("A small trapdoor (closed), it seems to be leading down.\n");
  set_value(0);
   can_get = 0;
  set_weight(20000);
  return 1;
  }

init(){
  add_action("open_trap","open"); add_action("close_trap","close");
  add_action("enter_trap","enter"); add_action("do_down","down");
  add_action("do_down","d");
  }
open_trap(str){
  if(!str){
  notify_fail("Open what ?\n");
  return 0;
  }
if(str=="trapdoor"){
   if(open == 1){
   write("But it's already open.\n");
   return 1;
   }
   else{
  write("You open the trapdoor.\n");
  open = 1;
environment(this_object())->set_trapd(open);
  set_short("A small trapdoor (open)");
  set_long("A small trapdoor (open), it seems to be leading down.\n");
  return 1;
  }
 }
}
close_trap(str){
  if(!str){
  notify_fail("Close what ?\n");
  return 0;
  }
if(str=="trapdoor"){
   if(open == 0){
   write("But it's not open.\n");
   return 1;
   }
   else{
   write("You close the trapdoor.\n");
   open = 0;
  environment(this_object())->set_trapd(open);
set_short("A small trapdoor (closed)");
set_long("A small trapdoor (closed), it seems to be leading down.\n");
   return 1;
   }
 }
}
enter_trap(str){
   if(!str){
   notify_fail("Enter what ?\n");
   return 0;
   }
if(str=="trapdoor"){
    if(open == 0){
    write("You can't do that, the trapdoor is closed.\n");
    return 1;
    }
    else{
    write("You walk down the stairs of the trapdoor.\n");
    this_player()->move_player("down the trapdoor#players/dice/quest/q12");
    return 1;
    }
  }
 }
do_down(){
  if(open == 0 ){
  write("The trapdoor is not open.\n");
  return 1;
  }
  else{
  this_player()->move_player("through the trapdoor#players/dice/quest/q12");
  return 1;
  }
 }

query_open() { return open; }
set_open(i) { open=i; }
