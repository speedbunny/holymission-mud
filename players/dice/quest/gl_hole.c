inherit "/obj/thing";

reset(arg) {
  if (arg) return 1;
  set_name("A red glowing hole");
   set_alias("hole");
   set_short("A red glowing hole");
    set_long("A red glowing hole.\n"+
             "It emanates an intense heat.\n");
  set_value(0);
   can_get = 0;
  set_weight(20000);
  return 1;
  }

init(){
  add_action("enter_hole","enter"); add_action("touch_hole","feel");
  add_action("down_hole","down"); add_action("down_hole","d");
  add_action("touch_hole","touch");
  }
enter_hole(str){
    if(!str){
    notify_fail("Enter what ?\n");
    return 0;
    }
if((str=="hole")||(str=="glowing hole")||(str=="red hole")){
 if(!this_player()->query_frog()){
   write("You are too large to enter this hole\n"+
         "You burn yourself while trying it\n");
      this_player()->hit_player(20,3);
      this_player()->show_hp();
      return 1;
 }
    write("You wiggle yourself through the hole, and feel an intense\n"+
          "heat spreading in your body.\n"+
          "The heat was almost too much for you.\n");
      this_player()->show_hp();
   this_player()->move_player("through a red glowing hole#players/dice/quest/q7");
  this_player()->hit_player(10,3);
   write("\n\n\nYou look behind you, and see that the hole has collapsed\n"+
           "You were lucky to get out of there in time.\n");
   call_out("collapse_hole",1);
   return 1;
   }
 }
touch_hole(str){
  if(!str){
  notify_fail("Touch what ?\n");
  return 0;
  }
   if((str=="red hole")||(str=="hole")||(str=="glowing hole")){
  write("\n\n\nYou attempt to touch the hole.\n"+
        "You feel an intense heat on your fingers,\n"+
        "and quickly you withdraw your hand from the hole\n"+
        "before any damage is done !\n"+
        "That was a close call !!\n\n\n\n");
  return 1;
  }
 }
down_hole(){
   this_player()->move_player("down#players/dice/quest/q7");
   call_out("collapse_hole",1);
   return 1;
   }
collapse_hole() {
   destruct(this_object());
   return;
   }
