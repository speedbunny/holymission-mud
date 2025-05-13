/* G: Coded by Moonchild in the time he was with us */
/* G: Changed illegally later */
/* 15-DEC-1993 Galadriel: restored original Moonchild values, 2 locations */
#define E   environment()
#define ENV environment
#define TP  this_player()
#define EGS environment()->get_skill
#define TPN (string)environment()->query_name()

#define TPS 10+(int)this_player()->query_str()*3
#define TPD 10+(int)this_player()->query_dex()*2
#define QN  query_name()

mixed *data;
int tot_dam,time;
int *cmds_done;
string *attacks=({ "kick", "punch", "knee", "headbutt", "bodyslam" });

int id(string str) {
  return str=="combat_soul";
}

int drop() {
  return 1;
}

void init() {
  if(E==TP) {
    int skill;
   int skill2;
    int i;
    for(i=0;i<5;i++)
      add_action("_attack", attacks[i]);
    skill=(int)EGS("barbarian_combat")[0];
    skill2= (int)EGS("barb_toughness")[0];
    this_player()->set_n_ac((int)skill2/10);
/* 15-DEC-1993 Galadriel: Too strong
    call_out("destroy_me", 60 + skill*3/4 + random(skill*3/2), 0);
*/
    call_out("destroy_me", 60 + skill/2 + random(skill), 0);
    switch(skill) {
      case 1:
	data=({ ({ 1, 2 }), ({ 1, 1 }), ({ 1, 3 }), ({ 1, 3 }), ({ 1, 7 }) });
	break;
      case 2:
	data=({ ({ 1, 2 }), ({ 1, 1 }), ({ 1, 3 }), ({ 1, 3 }), ({ 1, 6 }) });
	break;
      case 3:
	data=({ ({ 1, 1 }), ({ 1, 1 }), ({ 1, 3 }), ({ 1, 3 }), ({ 1, 6 }) });
	break;
      case 4:
	data=({ ({ 1, 1 }), ({ 1, 1 }), ({ 1, 3 }), ({ 1, 2 }), ({ 1, 5 }) });
	break;
      case 5:
	data=({ ({ 1, 1 }), ({ 2, 1 }), ({ 1, 2 }), ({ 1, 2 }), ({ 1, 5 }) });
	break;
      case 6:
	data=({ ({ 2, 1 }), ({ 2, 1 }), ({ 1, 2 }), ({ 1, 2 }), ({ 1, 4 }) });
	break;
      case 7:
	data=({ ({ 2, 1 }), ({ 2, 1 }), ({ 1, 2 }), ({ 1, 1 }), ({ 1, 4 }) });
	break;
      case 8:
	data=({ ({ 2, 1 }), ({ 2, 1 }), ({ 1, 2 }), ({ 1, 1 }), ({ 1, 3 }) });
	break;
      case 9:
	data=({ ({ 2, 1 }), ({ 3, 1 }), ({ 1, 2 }), ({ 1, 1 }), ({ 1, 3 }) });
	break;
      case 10:
	data=({ ({ 2, 1 }), ({ 3, 1 }), ({ 1, 1 }), ({ 2, 1 }), ({ 1, 2 }) });
	break;
      default:
	data=({ ({ 1, 2 }), ({ 1, 2 }), ({ 1, 3 }), ({ 1, 4 }), ({ 1, 7 }) });
	break;
    }
    cmds_done=allocate(5);
  }
}

int _attack(string str) {
  object ob;
  int att_no,act_dam;
  string verb;
  if(str && !(ob=present(str, ENV(E)))) {
    write(capitalize(str) + " is not here.\n");
    return 1;
  }
  else {
    ob=(object)TP->query_attack();
    if(!ob || !present(ob, ENV(E))) {
      write(capitalize(query_verb()) + " whom?\n");
      return 1;
    }
  }
  if(ENV(E)->query_property("no_fight"))
    return (int)ENV(E)->try_attack(ob);
  verb=query_verb();
  att_no=member_array(verb, attacks);
  if(cmds_done[att_no] >= data[att_no][0])
    return 1;
  else {
    int dam;
    mixed mess;
    cmds_done[att_no] += data[att_no][1];
    switch(att_no) {
      case 0:
	switch((int)ob->query_size()) {
	  case 1:
	    mess=({
		"You kick the puny ", " hard!\n",
		" kicks the puny ", " hard!\n",
		" kicks you hard!\n" });
	    dam=random(TPD - 15);
	    break;
	  default:
	    dam=random(TPD - 25);
	    break;
        }
        break;
      case 1:
	switch((int)ob->query_size()) {
	  case 1:
	    dam=0;
	    break;
	  case 5:
            dam=random((TPD + TPS - 25)/3 - 15);
	    break;
          default:
	    dam=random((TPD + TPS)/3);
	    break;
	}
	break;
      case 2:
	switch((int)ob->query_size()) {
	  case 1:
	    dam=0;
	    break;
	  case 5:
	    dam=random(TPD - 10);
	    break;
          default:
	    dam=random(TPD - 20);
	    break;
	}
        break;
      case 3:
	switch((int)ob->query_size()) {
	  case 1:
	  case 5:
	    dam=0;
	    break;
	  case 3:
	    mess=({
		"You headbutt ", " viciously!\n",
		" headbutts ", " viciously!\n",
		" headbutts you viciously!\n" });
	    dam=random(TPS);
	    break;
	  default:
            dam=random(TPS - 20);
	    break;
	}
	break;
      case 4:
	switch((int)ob->query_size()) {
	  case 1:
	    dam=0;
	    break;
	  case 2:
	    dam=TPS+random(TPS * 3/2);
	    break;
	  case 3:
            dam=TPS+random(TPS - 20);
	    break;
	  case 4:
            dam=TPS;
	    break;
	  default:
            dam=random(TPS - 20);
	    break;
	}
	break;
    }
    act_dam=(int)ob->hit_player(dam);
    if(act_dam) {
      TP->add_exp(act_dam);
      if(!ob)
	return 1;
      else if(pointerp(mess)) {
	write(mess[0] + (string)ob->QN + mess[1]);
	say(TPN + mess[2] + (string)ob->QN + mess[3], ob);
	tell_object(ob, TPN + mess[4]);
      }
      else {
	string vp,how;
	switch(act_dam) {
	  case 1..4:   how=""; break;
	  case 5..9:   how=" quite hard"; break;
	  case 10..14: how=" hard"; break;
	  case 15..19: how=" very hard"; break;
	  case 20..29: how=" violently"; break;
	  case 30..39: how=" with great ferocity"; break;
	  default:     how=" and hear the sound of splintering bones"; break;
	}
	vp=verb=="punch" ? " " + verb + "es " : " " + verb + "s ";
	write("You " + verb + " " + (string)ob->QN + how + ".\n");
	say(TPN + vp + (string)ob->QN + how + ".\n", ob);
	tell_object(ob, TPN + vp + "you" + how + ".\n");
      }
    }
    else {
	write("You try to " + verb + " " + (string)ob->QN + ", but miss.\n");
	say(TPN + " tries to " + verb + " " + (string)ob->QN
	+ ", but misses.\n", ob);
	tell_object(ob, TPN + " tries to " + verb + " you, but misses.\n");
    }
  }
  return 1;
}

void heart() {
  int i;
  for(i=0;i<5;i++)
    if(cmds_done[i]>0)
      cmds_done[i]-=data[i][0];
}

void destroy_me() {
  tell_object(environment(), "You slip out of barbarian combat.\n");
   this_player()->set_n_ac( 10 );
  destruct(this_object());
}
