inherit "obj/weapon";
reset(arg){
 ::reset(arg);
 if (arg) return;
 set_name("long bow");
 set_alias("bow");
 set_class(3);
 set_short("A long bow");
 set_long("A long ebony bow with mystical arrows.\n");
 set_value(4000);
 set_weight(4);
 set_hit_func(this_object());
}

weapon_hit(attacker){
 if ((this_player()->query_race())=="outcasthood"){
  say("Robin shoots an arrow into your neck.\n");
  return 50;
  }
  else {
   write("You shoot a mystical arrow.\n");
   say(capitalize(this_player()->query_name())+" shoots a mystical arrow.\n");
   return random(15);
   }
 }
 
