shield_block(object *bloarm,int is_berzerk,object *bwho) {
	object att,tp;
	int ac;

	tp=this_player();

  if(!att=tp->query_attack()) {
	write("You are not fighting.\n");
	return 1;
	}

  if(!tp->query_armour()[tp->query_arm_types("shield")]) {
	write("You need a shield so that you can block.\n");
	return 1;
	}

  if(bloarm) {
	write("You are already blocking with all your might.\n");
	return 1;
	}

  if(is_berzerk) {
       write("You have little self control whilst you are berzerk.\n");
	return 1;
	}

  transfer(bloarm=clone_object("/players/portil/guild/armour/bloarm.c"),tp);
  write("You start to block.\n");
  ac=(tp->query_dex()/5)+3;
  bloarm->set_ac(ac);
  tp->wear(bloarm);
  bwho=tp->query_attack();
  return 1;
}
