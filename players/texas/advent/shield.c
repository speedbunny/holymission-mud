/* Shield spell for advent guild 
 * Costs 50 and adds 1 to the ac of the target
 * Standard Drain
 *
 * Written by Texas 
 */
#define COST 50 

int shield(string arg) {

  object ob;

  if(!arg) {
    write("You weave your hands in an intricate pattern. A shield appears"+
	  " surrounding you\n");
    say(this_player()->query_name()+
	" weaves an intricate pattern in the in the air.\n");
    this_player()->set_ac((this_player()->query_ac())+1);
    call_out("remove_shield",30,this_player()->query_real_name());
    if(this_player()->query_spell_points() < COST) {
      this_player()->hit_player(COST - this_player()->query_spell_points());
      this_player()->restore_spell_points(-this_player()->query_spell_points());
      write("You Cross your hands by mistake, draining yourself.\n");
    }
    else {
      this_player()->restore_spell_points(-COST);
    }
    return 1;
  }
  if(!present(arg,environment(this_player()))) {
    notify_fail(arg+" is not in the room with you\n");
    return 0;
  }
  if(ob = find_living(arg)) {
    if("/players/texas/master.c"->shield(arg)) {
      write("You intricately weave your hands and a shield appears"+
	    " surrounding "+ob->query_name()+".\n");
      say(this_player()->query_name()+
	  " weaves an intricate pattern around "+ob->query_name()+".\n");
      ob->set_ac((ob->query_ac())+1);
     call_out("remove_shield",600,arg);
    }
    else {
      write("You have already shield them before, today.\n");
      return 1;
    }
  }
  if(this_player()->query_spell_points() < COST) {
    this_player()->hit_player(COST - this_player()->query_spell_points());
    this_player()->restore_spell_points(-this_player()->query_spell_points());
    write("You mis-chanted the ancient texts. The spell backfires !\n");
  }
  else {
    this_player()->restore_spell_points(-COST);
  }
  return 1;
}

remove_shield(string arg) {
  object o;
  
  if(o=find_player(arg))
    if(o->query_ac()) {
      o->set_ac((o->query_ac()-1));
      tell_object(o,"Your Shield has worn off!\n");
    }
    else
      return 1;
}
