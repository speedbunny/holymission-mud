summon(arg) {
  int i, pos_id, crnum, emptyslot;
  switch(arg) {
    case "roc":
      CHECK_LEVEL(0);
      CHECK_GHOST();
      CHECK_INTOX();
      CHECK_ARM();
      CHECK_WEAP();
      if(ENV(TP)->query_property("no_teleport")) {
	write("You raise your hands and shout towards the sky.\n");
	write("This area muffles your cry; the Roc cannot hear you.\n");
	say(TP->NAME + " raises " + TP->POS + " hands to the sky and " +
	    "calls out:\n");
	say("'Te arcesso ut feras me ad incolumitatem!'\n");
	say("Nothing further happens.\n");
	return 1;
      }
      CHECK_SP(ROC_SUM_SP);
      write("You raise your hands and shout towards the sky.\n");
      write("A huge Roc swoops down and picks you up in its claws!\n");
      write("The Roc carries you to your Guild and sets you down,\n");
      write("then flaps its mighty wings and returns to its home.\n");
      say(TP->NAME + " raises " + TP->POS + " hands to the sky and " +
	  "calls out:\n");
      say("'Te arcesso ut feras me ad incolumitatem!'\n");
      say("A huge shadow shrouds the area in darkness as a giant Roc\n");
      say("swoops down and carries " + TP->SNAME +
	  " away in its claws!\n");
      TRANS(TP, sanctuary);
      say("A huge Roc spirals down from the sky and sets down " +
	  TP->NAME + ",\n");
      say("then flaps its mighty wings and returns to its home.\n");
      return 1;
      break;

    case "raven":
      CHECK_LEVEL(0);
      CHECK_ATTACK();
      CHECK_GHOST();
      CHECK_INTOX();
      CHECK_ARM();
      CHECK_WEAP();
      if(!raven) {
	CHECK_SP(RAVEN_SUM_SP);
	raven = clone_object(crdir + "raven");
	write("You chant the words of Summoning.\n");
	write("A black Raven materializes on your shoulder.\n");
	say(TP->NAME + " traces burning symbols in the air and " +
	    "calls out:\n");
	say("'Te arcesso ut sis mea vox!'\n");
	say("A black Raven materializes on " + TP->SNAME +
	    "'s shoulder.\n");
	TRANS(raven, TP);
	return 1;
      }
      write("You have already summoned a Raven.\n");
      return 1;
      break;

    default:
      for(i = 0; i < sizeof(specialarray); i++)
	if(specialarray[i][0] == arg) {
	  pos_id = 1;
	  crnum = i;
	}
      if(pos_id) {
	pos_id = 0;
	for(i = 0; i < MAXCREATURES; i++) {
	  if(creatures[i]) {
	    if(creatures[i]->query_creature() == arg) {
	      write("You have already summoned a Creature of that type.\n");
	      return 1;
	    }
	  }
	  else {
	    emptyslot = i;
	    pos_id = 1;
	  }
	}
	if(!pos_id) {
	  write("You already control " + MAXCREATURES + " Creatures.\n");
	  return 1;
	}
	CHECK_LEVEL(specialarray[crnum][1]);
	CHECK_ATTACK();
	CHECK_GHOST();
	CHECK_INTOX();
	CHECK_ARM();
	CHECK_SP(specialarray[crnum][2]);
	creatures[emptyslot] = clone_object(crdir + arg);
	creatures[emptyslot]->make_me(TP);
	TRANS(creatures[emptyslot], ENV(TP));
	return 1;
      }
    }
  pos_id = 0;
  for(i = 0; i < sizeof(attackerarray); i++)
    if(attackerarray[i][0] == arg) {
      pos_id = 1;
      crnum = i;
    }
  if(pos_id) {
    pos_id = 0;
    for(i = 0; i < MAXCREATURES; i++) {
      if(creatures[i]) {
	if(creatures[i]->query_creature() == "attacker") {
	  write("You have already summoned a Creature of that type.\n");
	  return 1;
	}
      }
      else {
	emptyslot = i;
	pos_id = 1;
      }
    }
    if(!pos_id) {
      write("You already control " + MAXCREATURES + " Creatures.\n");
      return 1;
    }
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_WEAP();
    CHECK_NO_FIGHT();
    CHECK_SP(attackerarray[crnum][1]);
    creatures[emptyslot] = clone_object(crdir + arg);
    creatures[emptyslot]->make_me(TP, crnum);
    TRANS(creatures[emptyslot], ENV(TP));
    return 1;
  }
  write("Syntax: summon <creature>\n");
  return 1;
}
