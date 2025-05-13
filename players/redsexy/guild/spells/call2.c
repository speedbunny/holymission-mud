call(arg) {
  int i, pos_id, flag, callnum;
  object temp, inv;
  for(i = 0; i < sizeof(callarray); i++)
    if(callarray[i][0] == arg) {
      pos_id = 1;
      callnum = i;
    }

  if(pos_id) {
      CHECK_LEVEL(callarray[callnum][1]);
      CHECK_GHOST();
      CHECK_INTOX();
      CHECK_ARM();
      CHECK_WEAP();
      CHECK_FIGHT();
      CHECK_SP(callarray[callnum][2]);
      switch(arg) {
        case "ice":
	  if(att) {
	    write("You pelt " + att->NAME + " with an Ice Storm.\n");
	    say(TP->NAME + " combines Water and Wind.\n");
	    TELL(att, TP->SNAME + " calls an Ice Storm down upon you!\n");
	    TELLS(TP->SNAME + " calls an Ice Storm down upon " +
		  att->NAME + "!\n", TP, att);
	    att->HIT(ICE_DAM);
	  }
        return 1;
	  break;
	  
	case "mud":
	  say(TP->NAME + " combines Water and Earth.\n");
	  inv = all_inventory(ENV(TP));
	  for(i = 0; i < sizeof(inv); i++)
	    if((inv[i]->query_attack() == TP) ||
	       (TP->query_attack() == inv[i])) {
	      flag = 1;
	      write("You create Mud at the feet of " +
		    inv[i]->NAME + ".\n");
	      TELL(inv[i], TP->SNAME + " calls up Mud from the ground " +
		   "to engulf you!\n");
	      TELLS(TP->SNAME + " calls up Mud from the ground, " +
		    "engulfing " + inv[i]->NAME + "!\n", TP, inv[i]);
	      inv[i]->hold(TO, MUD_TIME);
	    }
	  if(!flag) write("No one is attacking you.\n");
        return 1;
	  break;
	  
	case "cyclone":
	  if(att) {
	    write("You blast " + att->NAME + " with a whirling burst " +
		  "of wind.\n");
	    say(TP->NAME + " combines Wind and Earth.\n");
	    TELL(att, TP->SNAME + " calls a Cyclone down upon you!\n");
	    TELLS(TP->SNAME + " calls a Cyclone down upon " +
		  att->NAME + "!\n", TP, att);
	    att->HIT(CYCLONE_DAM);
	  }
	  return 1;
	  break;
	  
	case "smoke":
	  if(present("smokeobject", TP)) {
	    write("You are already engulfed in Smoke.\n");
	    return 1;
	  }
	  write("You surround yourself with a smoky haze.\n");
	  say(TP->NAME + " combines Water and Fire.\n");
	  say(TP->SNAME + " calls Smoke to surround " +
	      TP->OBJ + "self.\n");
	  temp = clone_object(OBJS + "smokeobj");
	  transfer(temp, TP);
	  temp->set_master();
	  return 1;
	  break;
	  
	case "blaze":
	  inv = all_inventory(ENV(TP));
	  say(TP->NAME + " combines Wind and Fire.\n");
	  for(i = 0; i < sizeof(inv); i++)
	    if((inv[i]->query_attack() == TP) ||
	       (TP->query_attack() == inv[i])) {
	      flag = 1;
	      write("You scorch " + inv[i]->NAME + " with a blast " +
		    "of flame.\n");
	      TELL(inv[i], TP->SNAME + " calls a Blaze down upon you!\n");
	      TELLS(TP->SNAME + " calls a Blaze down upon " +
		    inv[i]->NAME + "!\n", TP, inv[i]);
	      inv[i]->HIT(BLAZE_DAM);
	    }
	  if(!flag) write("No one is attacking you.\n");
	  return 1;
	  break;
	  
	case "magma":
	  if(att) {
	    write("You burn " + att->NAME + " with Magma.\n");
	    say(TP->NAME + " combines Earth and Fire.\n");
	    TELL(att, TP->SNAME + " calls up Magma from the ground and " +
		 "burns you!\n");
	    TELLS(TP->SNAME + " calls up Magma from the ground and burns " +
		  att->NAME + "!\n", TP, att);
	    att->HIT(MAGMA_DAM);
	  }
	  return 1;
	  break;
	  
	case "bolt":
	  if(att) {
	    write("You strike " + att->NAME + " with a Bolt of Power.\n");
	    say(TP->NAME + " brings forth raw Power.\n");
	    TELL(att, TP->SNAME + " calls down a Bolt from the sky to " +
		 "strike you!\n");
	    TELLS(TP->SNAME + " calls down a Bolt from the sky to strike " +
		  att->NAME + "!\n", TP, att);
	    att->HIT(BOLT_DAM);
	  }
	  return 1;
	  break;
	  
	default:
	  write("Syntax: call <combination>\n");
	  return 1;
	  break;
      }
    }
  write("Syntax: call <combination>\n");
  return 1;
}

hold_end(obj) {
  if(obj) {
    TELL(obj, "You free yourself from the Mud!\n");
    TELLRS(ENV(obj), obj->NAME + " frees " + obj->OBJ +
	   "self from the Mud!\n", obj);
    return 1;
  }
  return 1;
}

