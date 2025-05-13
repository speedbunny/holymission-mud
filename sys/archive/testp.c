
/* mud@mud.edvz.uni-linz.ac.at Herp aka Herbert Rosmanith */

/*-------------------------*
 * Using object oriented   *
 * class concept           *
 *-------------------------*/

inherit "/sys/appr";

#define GM	"guild/master"
#define TESTP	"/sys/bin/testp/"

string name_of_friend;	/* to whom do we belong to */

static void testp_commands() {
    add_action("_filter","",1);
    add_action("remove_ghost","pray");
    add_action("tp_heal", "heal");
    add_action("tp_home","home");
    add_action("tp_set_guild","setguild");
    add_action("tp_set_level","setlevel");
    add_action("tp_set_stat","setstat");
    add_action("teleport","goto");  /* Matt 5-20-94 */
    add_action("tp_set_exp","setexp");  // Llort 9-2-95
}

void logon(string n,int quiet) {
  ::logon(n,quiet);
  testp_commands();
}

int _filter(string str) {

  string theverb;

  theverb=(string)query_verb();

  if(theverb[0..0]=="'" || member(theverb,'.')!=-1)
    return 0;

  if(file_size(TESTP+theverb+".c")>0) 
    if((TESTP+theverb)->main(str))
      return 1;

  return ::_filter(str);
}

int set_friend(string str) {
  string rn;

  if(str!=(rn=this_player()->query_real_name()) || /* 1) set for another wiz */
      (name_of_friend && rn!=name_of_friend))      /* 2) other wiz's testp */
    return 0;

  name_of_friend=str;
  save_me(1);
  tell_object(this_object(),"You now are "+capitalize(rn)+"'s testplayer.\n");
  return 1;
}

string query_testchar() { return name_of_friend; }

static int tp_heal(string str) {
  if (str && str!=name) {
     notify_fail("You are only allowed to heal yourself.\n");
     return 0;
  }
  heal_self(10000);
  write("You are healed.\n");
  return 1;
}

static int tp_home() {
  string str;

  str="players/"+name_of_friend+"/workroom";
  if (file_size(str+".c")<0) write("Your master hasn't got a workroom.\n");
  else move_player("home#"+str);
  return 1;
}

static int tp_set_guild(string str) {
  int i;

  if (!str) {
     write("Active guilds:\n");
     GM->dump();
     return 1;
  }
  if (sscanf(str,"%d",i)!=1 && (i=GM->query_number(str))==-1) {
     notify_fail("Error in argument.\n");
     return 0;
  }
  ::set_guild(i);
  write("Ok.\n");
  return 1;
}

static int tp_set_level(string str) {
  int i;

 /* changed to allow testie's to function properly- haplo 8-20-96 */
  if (!str || to_int (str)<1 || to_int (str) > 99) {
     notify_fail("To what level ?\n");
     return 0;
  }
  if (sscanf(str,"%d",i)!=1) {
     notify_fail("Error in argument.\n");
     return 0;
  }
  ::set_level(i);
  return 1;
}

static int tp_set_stat(string str) {
    string stat;
    int val,snr,i;

    if(!str) {
	write("Useage: setstat <statname|all> <level>\n");
	return 1;
    }
    if(sscanf(str,"%s %d",stat,val)!=2) {
	write("Error in arguments!\n");
	return 1;
    }
    if ( val > 40 ) val = 40;
    snr=0;
    switch(stat) {
	case "chr": snr++;
	case "wis": snr++;
	case "int": snr++;
	case "con": snr++;
	case "dex": snr++;
	case "str": break;
        case "all": 
            for(i=0;i<6;i++) ::set_stats(i,val); 
            write("Ok.\n");
            return 1;
	default:
	    write(stat +" not defined!\n"); 
	    return 1;
    }
    ::set_stats(snr,val); 
    write("Ok.\n");
    return 1;
}

/* Matt 5-20-94: Goto rooms for testing purposes (but not people) */
int teleport(string dest) {
  dest = valid_read(dest);
  if(!dest || file_size("/" + dest + ".c") <= 0) {
    write("Invalid file name: " + dest + "\n");
    return 1;
  }
  move_player("X#" + dest);
  return 1;
}

static int tp_set_exp(string arg) {
  if(!arg || to_int(arg)<1) {
    write("Give experience value. (has to be >0)\n");
    return 1;
  }
  add_experience(to_int(arg)-query_exp());
  write("Experience set to "+arg+".\n");
  return 1;
}
