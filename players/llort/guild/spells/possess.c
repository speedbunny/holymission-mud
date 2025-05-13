
/* ################################################################
   #								  #
   #    		Mage possess spell                        #
   #                                          		          #
   #   !!!!!!! this spell is not for use of players !!!!!!!!!!    #
   #                                          		          #
   # make sure that this spell will never be available to players #
   #                                          		          #
   ###############################################(C) Llort######## */

object victim;

possess(arg) {
int spnr;

  if(!E()->query_wizard()) return 0;  		/* !!!!!!!!! */

  if((!arg)&&victim) {
    input_to("poss");
    write(victim->query_name()+"> ");
    return 1;
  }

  if(victim) {
    write("You can't possess two at a time.\n");
    return 1;
  }
  if(!arg) {
    write("Possess whom ?\n");
    return 1;
  }    

  victim=find_living(arg);

  if((!victim) || !living(victim)) {
    write("You can't possess "+arg+".\n");
    victim=0;
    return 1;
  }  

  input_to("poss");
  if(!victim->query_npc())
    snoop(victim);
  write(victim->query_name()+"> ");

  return 1;
}

poss(arg) {
object ob;
int i;

  if(arg=="release") {
    release();
    return 1;
  }
  if(arg=="jump") {
    snoop();
    this_player()->move_player("X",environment(victim));
    victim=0;
    return 1;
  }
  if(arg=="cmd") {
    return 1;
  }

  command(arg,victim);
  if(victim->query_npc()) {
    environment(victim)->long();
    ob=all_inventory(environment(victim));
    for(i=0;i<sizeof(ob);i++)
      if((ob[i]!=victim)&&(ob[i]->short())) write(ob[i]->short()+"\n");
  }

  input_to("poss");
  write(victim->query_name()+"> ");
}

release() {
  if(!victim) return 0;
  write("You released "+victim->query_name()+".\n");
  snoop();
  victim=0;
  return 1;
} 
