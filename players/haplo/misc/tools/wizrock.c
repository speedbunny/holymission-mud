/* Coded by Arthur mainly for New and Appr wizes on Holy Mission */
/* But, it also saves the hassle for those lazy wizes when they wanna change
somthing on themselves :) - Arthur */
inherit "/obj/treasure";
string let,which,what,name;
int amm,invis;
#define TP this_player
#define QN query_name()
#define CP capitalize
#define WR write
#define TO this_object
#define AA add_action
#define PATH "/players/arthur/wiz/"

reset(arg) {
  if(arg) return;
  name=TP()->query_real_name();
    set_id("wizards rock");
    set_alias("rock");
    set_long("This very sturdy looking rock looks like it was coded by Arthur.\nIt has many neat functions built into it. To find out what\njust type 'help rock'.\n");
    set_value(0);
    set_weight(0);
  }
short() {
    if(invis) return;
    else return capitalize(TP()->query_real_name())+"'s wiz rock";
    }

init() {
/* This next line is commented because it doesn't work with the mages soul */
/*if(!TP()->query_immortal()) { WR("You're not supposed to have me. BYE!\n");destruct(TO()); return 1; } */
   AA("add","add");
   AA("set","set");
   AA("help","help");
   ::init();
}
help(str) {
 if(str != "rock") return 0;
  
  WR("The current functions of Arthurs wiz rock are:\n\n"+
   "set <argument> <number or string>\n"+
    "\nThis is the list of current <argument>'s for the set function.\n"+
     "str <number> - sets the strength to between 1 and 40\n"+
     "wis <number> - sets the wisdom to between 1 and 40\n"+
     "int <number> - sets the intellegence to between 1 and 40\n"+
     "dex <number> - sets the dexterity to between 1 and 40\n"+
     "chr <number> - sets the chrisma to between 1 and 40\n"+
     "con <number> - sets the constitution to between 1 and 40\n"+
     "al <number> - sets your alignment\n"+
     "n_ac <number> - sets your natural armour class\n"+
     "n_wc <number> - sets your natural weapon class\n"+
     "religion <string> - sets your religion to <string>\n"+
     "race <string> - sets your race to <string>\n"+
     "smell <string> - sets your smell to <string>\n"+
     "gender <str> - <str> can be male, female or other\n"+
     "rock <str> - <str> can be invisible or visible\n"+
    "\nadd <argument> <num>\n\n"+
   "This is the list of current <argument>'s for the add function.\n\n"+
     "hp <num> - adds <num> ammount of hit-points to you\n"+
     "money <num> - adds <num> ammount of money to you\n"+
     "xp <num> - adds <num> ammount of experience to you\n");
  return 1;}
      
add(str) {
  if(!TP()->query_immortal()) {
   destruct(this_object());
   return 1;
  }
  if(TP()->query_real_name() != name) {
   WR("This is not your rock, you must seek your own!\n");
   destruct(this_object());
   return 1;}
 if(!str) return 0;
 if(sscanf(str,"%s %d",which,amm)!=2) return 0;

   switch(which) {
         case "money": 
             TP()->add_money(amm);
             done2();
             return 1;
             break;
         case "xp": 
             TP()->add_exp(amm);
             done2();
             return 1;  
             break;
         case "hp":
             TP()->reduce_hit_point(-amm);
             done2();
             return 1;
             break;
         default: return 0; break;
   } 
}

set(str) {
  if(!TP()->query_immortal()) {
    destruct(this_object());
    return 1;
   }
   if(TP()->query_real_name() != name) {
    WR("This is not your wiz rock! Go get your own.\n");
    destruct(this_object());
    return 1;}
  if(!str) {WR("what do you want to set, and to what?\n"); return 1;}
   if(sscanf(str,"%s %s",which,what) == 2) {
      switch(which) {
       case "rock":
             if(what =="invisible") invis = 1;
             else invis = 0;
             write("Your rock is now "+what+".\n");
             return 1;
             break;
       case "race":
            TP()->set_race(what);
            done3();
            return 1;
            break;
       case "religion":
            TP()->set_religion(what);
            done3();
            return 1;
            break;
       case "gender":
            if(what =="male") TP()->set_gender(1);
            else if(what =="female") TP()->set_gender(2);
            else TP()->set_gender(0);
            done3();
            return 1;
       case "smell":
             TP()->set_smell(what);
             done3();
             return 1;
            break;
       default:
             break;
      }
   }


   if(sscanf(str,"%s %d",which,amm) !=2) {WR("What do you want set and to what\n");
     return 1;}
     switch(which) {
       case "dex": 
            TP()->set_dex(amm);
            done();
            return 1;
            break;
       case "con":
            TP()->set_con(amm);
            done();
            return 1;
            break;
       case "str":
            TP()->set_str(amm);
            done();
            return 1;
            break;
       case "wis":
            TP()->set_wis(amm);
            done();
            return 1;
            break;
       case "chr": 
            TP()->set_chr(amm);
            done();
            return 1;
            break;
       case "int": 
            TP()->set_int(amm);
            done();
            return 1;
            break;
       case "al":
            TP()->set_al(amm);
            done();
            return 1;
            break;
       case "n_ac":
            TP()->set_n_ac(amm);
            done();
            return 1;
            break;
       case "n_wc":
            TP()->set_n_wc(amm);
            done();
            return 1;
            break;
       default:  
            return 0;
            break;
    }
}
done(){
   WR("I set your "+which+" to: "+amm+".\n");
   log_file("arthur.rock",TP()->query_real_name()+" used the rock to set "+
   which+" to: "+amm+".\n");
   return 1;
}
done2() {
   WR("I added "+amm+" to your "+which+".\n");
   log_file("arthur.rock",TP()->query_real_name()+" used the rock to add "+
   amm+" to "+which+".\n");
   return 1;
}
done3() {
   WR("I Changed "+which+" to: "+what+".\n");
   log_file("arthur.rock",TP()->query_real_name()+" used the rock to change "+
   which+" to "+what+".\n");
   return 1;
}
drop() {WR("You would never want a player to get their grubby hands on your wiz rock!\n");
return 1;}
query_auto_load() { return PATH+"wizrock:"+invis;}
init_arg(arg) {invis=arg;}
// Coded by Arthur mainly for New and Appr wizzes on Holy Mission
// But, it also saves the hassle for those lazy wizzes when they want 
// to change something on themselves :) - Arthur
// Mangla: checked for consistency and reformatting
// Mangla: typedeffed all functions and placed some precautions
//         on some of the sets.
// Mangla: added a clone to appr command

#pragma strict_types;

inherit "/obj/treasure";

string let,which,what,name;
int amm,invis;

#define TP this_player()
#define TPRN this_player()->query_real_name()
#define QN query_name()
#define CP capitalize
#define WR write
#define TO this_object
#define AA add_action
#define PATH "/tools/"

int done();
int done2();
int done3();
void reset(int arg) {

    if(arg) return;
    name=TPRN;
    set_id("wizards rock");
    set_alias("rock");
    set_long("This very sturdy looking rock was probably coded by Arthur.\nIt has many neat funtions built into it. To learn more about the set function\nType 'help set', and to learn more about the add function type 'help add'.\n");
    set_value(0);
    set_weight(0);
}

string short() {
    if(invis) return "";
    else return environment(TO())->query_real_name()+"'s wiz rock";
}

void init() {
    /* Arthur: These next lines are commented because they do not 
	       work with the mages soul
       if(!TP()->query_immortal()) {
	   WR("You're not supposed to have me. BYE!\n");
	   destruct(TO());
	   return 1;
       }
    */   
    AA("_add","add");
    AA("_set","set");
    AA("_help","help");
    AA("_move","rockto");
    ::init();
}

int _help(string str) {

    if(str == "set") {

	WR("The current functions of Arthurs wiz rock are:\n\n"+
	  "set <argument> <number or string>\n"+
	  "\nThis is the list of current <argument>'s for the set function.\n"+
	  "str <number> - sets the strength to between 1 and 40\n"+
	  "wis <number> - sets the wisdom to between 1 and 40\n"+
	  "int <number> - sets the intellegence to between 1 and 40\n"+
	  "dex <number> - sets the dexterity to between 1 and 40\n"+
	  "chr <number> - sets the chrisma to between 1 and 40\n"+
	  "con <number> - sets the constitution to between 1 and 40\n"+
	  "al <number> - sets your alignment\n"+
	  "n_ac <number> - sets your natural armour class\n"+
	  "n_wc <number> - sets your natural weapon class\n"+
	  "religion <string> - sets your religion to <string>\n"+
	  "race <string> - sets your race to <string>\n"+
	  "smell <string> - sets your smell to <string>\n"+
	  "rock <str> - <str> can be invisible or visible\n");
	return 1;
    }
    if(str =="add") {
	WR("The current add functions for Arthur's Wiz rock are:\n\n"+
	  "This is the list of current <argument>'s for the add function.\n\n"+
	  "hp <num> - adds <num> ammount of hit-points to you\n"+
	  "xp <num> - adds <num> ammount of experience to you\n");
	return 1;
    }
    if(str == "rock") {
	WR("The wiz rock says: I have two functions. Set and add. You can\n\
get help on either of them. Use 'rockto <appr>' to send rock\n\
to an appr wiz.\n");
	return 1;
    }
    else
	return 0;
}

int _add(string str) {

    if( !TP->query_immortal() ) {
	destruct(this_object());
	return 1;
    }
    if(TPRN != name) {
	WR("This is not your rock, you must seek your own!\n");
	destruct(this_object());
	return 1;
    }
    if(!str) return 0;
    if(sscanf(str,"%s",which) == 1)
	amm = 0;
    sscanf(str,"%s %d",which,amm);

    switch(which) {
    case "xp": 
	if(!amm) {
	    WR("To add xp type 'add xp <number>'.\n");
	    return 1;
	}
	// Mangla: limit placed in here to stop ridiculous XP             
	if((int)TP->query_exp() > 10000000) break;
	TP->add_experience(amm);
	done2();
	return 1;  
	break;
    case "hp":
	if(!amm) {
	    WR("To add hp it would be 'add hp <number>'.\n");
	    return 1;
	}
	if(TP->query_hp() >= TP->query_max_hp()) break;
	if( (TP->query_max_hp()) - (TP->query_hp()) < amm) break;
	TP->reduce_hit_point(-amm);
	done2();
	return 1;
	break;
    default:
	return 0;
    } 
}

int _set(string str) {

    if( !TP->query_immortal() ) {
	destruct(this_object());
	return 1;
    }
    if(TPRN != name) {
	WR("This is not your wiz rock! Go get your own.\n");
	destruct(this_object());
	return 1;
    }
    if(!str) {
	WR("what do you want to set, and to what?\n");
	return 1;
    }
    if(sscanf(str, "%s", which) == 1)
	what = 0;
    sscanf(str,"%s %s",which,what);
    switch(which) {
    case "rock":
	if(!what) {
	    WR("To set the rock invisible type 'set rock invisible', for it to be visible\ntype 'set rock visible'.\n");
	    return 1;
	}
	if(what =="invisible") invis = 1;
	else invis = 0;
	write("Your rock is now visible.\n");
	return 1;
	break;
    case "race":
	if(!what) {
	    WR("To set your race type 'set race <string>'.\n");
	    return 1;
	}
	TP->set_race(what);
	done3();
	return 1;
	break;
    case "religion":
	if(!what) {
	    WR("To set your religion type 'set religion <string>'.\n");
	    return 1;
	}
	TP->set_religion(what);
	done3();
	return 1;
	break;
    case "smell":
	if(!what) {
	    WR("To set your smell type 'set smell' <string>'.\n");
	    return 1;
	}
	TP->set_smell(what);
	done3();
	return 1;
	break;
    default:
	which = 0;
    }


    if(sscanf(str, "%s", which) == 1)
	amm=0;
    sscanf(str,"%s %d",which,amm);
    switch(which) {
    case "dex": 
	if(!amm) {
	    WR("To set your dex type 'set dex <number>'.\n");
	    return 1;
	}
	if(amm < 41)
	    TP->set_dex(amm);
	done();
	return 1;
	break;
    case "con":
	if(!amm) {
	    WR("To set your con type 'set con <number>'.\n");
	    return 1;
	}
	if(amm < 41)
	    TP->set_con(amm);
	done();
	return 1;
	break;
    case "str":
	if(!amm) {
	    WR("To set your str type 'set str <number>'.\n");
	    return 1;
	}
	if(amm < 41)
	    TP->set_str(amm);
	done();
	return 1;
	break;
    case "wis":
	if(!amm) {
WR("To set your wis type 'set wis <number>'.\n");
	    return 1;
	}
	if(amm < 41)
	    TP->set_wis(amm);
	done();
	return 1;
	break;
    case "chr": 
	if(!amm) {
	    WR("To set your chr type 'set chr <number>'.\n");
	    return 1;
	}
	if(amm < 41)
	    TP->set_chr(amm);
	done();
	return 1;
	break;
    case "int": 
	if(!amm) {
	    WR("To set your int type 'set int <number>'.\n");
	    return 1;
	}
	if(amm < 41)
	    TP->set_int(amm);
	done();
	return 1;
	break;
    case "al":
	if(!amm) {
	    WR("To set your al type 'set al <number>'.\n");
	    return 1;
	}
	if( (amm < 1000)  &&  (amm > -1000) )
	    TP->set_al(amm);
	done();
	return 1;
	break;
    case "n_ac":
	if(!amm) {
	    WR("To set your n_ac type 'set n_ac <number>'.\n");
	    return 1;
	}
	if(amm < 20)
	    TP->set_n_ac(amm);
	done();
	return 1;
	break;
    case "n_wc":
	if(!amm) {
	    WR("To set your n_wc type 'set n_wc <number>'.\n");
	    return 1;
	}
	if (amm < 20)
	    TP->set_n_wc(amm);
	done();
	return 1;
	break;
    default:  
	return 0;
	break;
    }
}

int done(){
    WR("I set your "+which+" to: "+amm+".\n");
    log_file("arthur.rock",TPRN+" used the rock to set "+
      which+" to: "+amm+".\n");
    return 1;
}

int done2() {
    WR("I added "+amm+" to your "+which+".\n");
    log_file("arthur.rock",TPRN+" used the rock to add "+
      amm+" to "+which+".\n");
    return 1;
}

int done3() {
    WR("I Changed "+which+" to: "+what+".\n");
    log_file("arthur.rock",TPRN+" used the rock to change "+
      which+" to "+what+".\n");
    return 1;
}

int drop() {
    WR("You would never want a player to get their "+
      "grubby hands on your wiz rock!\n");
    return 1;
}

string query_auto_load() {
    return PATH+"wizrock:"+invis;
}

#if 0
init_arg(int arg) {
    invis=arg;
}
#endif

int _move(string arg) {

    object ob;
    object dest;

    dest = find_living(arg);
    if(dest && interactive(dest)
      && dest->query_level()==30
      && !present("wizrock",dest) ) {
	ob = clone_object("/tools/wizrock");
	ob->reset_name(dest->query_real_name());
	transfer(ob,dest);
    }
    else {
	write("You can only give a rock to an apprentice wizard.\n");
    }
    return 1;
}

void reset_name(string str) {
    name = str;
}

