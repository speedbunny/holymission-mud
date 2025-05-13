create(arg) {
  int i, pos_id, emptyslot, golemnum;
  for(i = 0; i < sizeof(golemarray); i++) 
    if(golemarray[i][0] == arg) {
      pos_id = 1;
      golemnum = i;
    }
  if(pos_id) {
    pos_id = 0;
    for(i = 0; i < MAXCREATURES; i++) {
      if(creatures[i]) {
	if(creatures[i]->query_creature() == "golem") {
	  write("You have already created a Golem.\n");
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
    CHECK_LEVEL(golemarray[golemnum][1]);
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_WEAP();
    CHECK_SP(golemarray[golemnum][2]);
    creatures[emptyslot] = clone_object(CRTS + "golem");
    creatures[emptyslot]->make_me(TP, golemnum);
    TRANS(creatures[emptyslot], ENV(TP));
    return 1;
  }
  write("Syntax: create <type>\n");
  return 1;
}
