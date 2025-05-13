inherit "obj/weapon";

reset(arg){
 ::reset(arg);
 if(!arg){
      set_name("hobbithammer");
      set_alias("hammer");
      set_class(7);
      set_short("A big hammer");
      set_long("It has a wooden shaft and an iron head, it looks like a workers hammer.\n");
      set_type(1);
      set_value(80);
      set_weight(2);
      set_hit_func(this_object());
  }
}
weapon_hit(ob) {
  write("You smash your hammer against "+ob->query_name()+"\n");
  say(this_player()->query_name()+" smashes the hammer against "+ob->query_name()+".\n");
return 1;
}
query_quest_item(){ return 1; }
query_quest_object() {
  return 1;
}

drop(silently){
 ::drop( silently );
   write( "As the hammer leaves your hands, it suddenly vanishes!\n" );
   destruct(this_object());
   return 1;
}
