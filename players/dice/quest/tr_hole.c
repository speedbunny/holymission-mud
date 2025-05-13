inherit "/obj/thing";

reset(arg) {
  if (arg) return 1;
   set_name("A black hole");
   set_alias("hole");
  set_short("A hand-size hole in the floor");
  set_long("The hole is big enough to reach into it, and search it with your hand.\n");
  set_value(0);
  set_weight(20000);
  can_get = 0;
  return 1;
  }

query_objmaker() { return 1; }
init(){
  add_action("search_hole","search");
  add_action("enter_hole","enter");
  add_action("pull_lever","pull");
  }
search_hole(str){
 if(!str){
  notify_fail("Search what ?\n");
  return 0;
  }
if((str=="hole")||(str=="black hole")){
  write("You put your hand in the hole, and feel something.\n"+
        "It feels like some sort of lever.\n");
  return 1;
  }
}
pull_lever(str){
  if(!str){
  notify_fail("Pull what ?\n");
  return 0;
  }
if((str=="lever")||(str=="lever in hole")){
   write("You pull the lever and hear a strange sound.\n"+
         "It sounds like stone scrubbing over stone.\n");
    this_player()->move_player("pulling a lever#players/dice/quest/q12a");
   return 1;
   }
 }
enter_hole(str){
 if(!str){
 notify_fail("Enter what ?\n");
 return 0;
 }
 if(str=="hole"||str=="black hole"){
  notify_fail("This hole is too small to enter\n");
 return 0;
 }
}
