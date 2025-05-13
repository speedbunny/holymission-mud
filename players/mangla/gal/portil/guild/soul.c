/* This is the heroic soul of a fighter                                     */

/* Gladiator 13-10-93 : Changed berzerking so higher players have a chance to
                        berzerk longer.                                     */
/* Gladiator 13-10-93 : Changed check-function, His into query_possessive
                         and he into query_pronoun                          */
/* Herp 171093: remove guild-talk, replaced by chat daemon */
/* Portil 081293: Spilt soul up so that each player clones less */

#define TP      this_player()
#define TPN     this_player()->query_name()
#define TPRN    this_player()->query_real_name()
#define ENV     environment
#define GM      "guild/master"
#define GUILD   "fighter"
#define BIN     "/players/portil/guild/bin/"
id(str) { return str=="fighter_soul" || str=="fightersoul"; }

string enam,eobj,epos;
string owner;
object wp,po,berz_where,bloarm,bwho;
int lev,level,no_but,bash;
int is_berzerk;                 /* Herp */
int gd;                         /* guildnumber (llort) */

/* the vars for timing the butt */
object xpl;
int xdam;
string xmsg;
object xatt;

get() { return 1; }
drop() { return 1; }

reset(arg) {
  if(arg) return;
  gd=GM->query_number(GUILD);
}

init() {
  object gem;
  if(gem=present("gem",TP)) {
    write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nYour guild emoter is of no use anymore and so has been removed.\nIt has been replaced by `fighter/` which has the same effect.\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    destruct(gem);
}
  "sys/chatd.c"->do_chat(gd,"You suddenly feel the blood rushing strongly through your veins.\n");
  add_action("compare","compare");
  add_action("home","stronghold");
  add_action("no_spell","missile");
  add_action("no_spell","shock");
  add_action("no_spell","fireball");
  add_action("tick","query");
  add_action("fighter_line","fighters");
  add_action("fighter_line","fighter");
  add_action("emote","fighter/");
  add_action("help","help");
  add_action("head_but","but");
  add_action("munch","munch");
  add_action("berzerk","berzerk");
  add_action("check","check");
  add_action("rescue","rescue");
  add_action("calm","calm");
  add_action("shield_bash","bash");
  add_action("shield_block","block");
  add_action("lower","lower");
  add_action("fshout","fshout");
//  add_action("track","track");
  add_action("guild_command","",1);
}

guild_command(str) {
	string verb;
	verb=query_verb();
	if(file_size(BIN+verb+".c")<1) return 0;
	return call_other(BIN+verb,verb,str);
} 

// track(str) { return ((BIN+"track.c")->track(str)); }

fshout(str) { return ((BIN+"fshout.c")->fshout(str)); }

help(arg) { return ((BIN+"help.c")->help(arg,GM,gd)); }


tick(str) { return ((BIN+"tick.c")->tick(str)); }

head_but(str) {
  string str1;
  object att,helmet;
  att = TP->query_attack();
  level = TP->query_level();
  lev = (level/2 + 15);

  if(TP->query_ghost()) {
      write("Your immaterial head is useless!\n");
      return 1;
  }
  if(bash==5) { write("You dont have the self control to bash and but at the same time.\n");
		return 1;
		}
/* 920122 now we HAVE to use helmets -- LLort */
  if(!(helmet=TP->query_armour()[TP->query_arm_types("helmet")])) {
      write("You need a helmet to do that!\n");
      return 1;
  }

/*  920914 capa    head but funktioniert auch in no_fight area        */
  str1 = ENV(this_player())->query_property();
  if(ENV(this_player())->query_property("no_fight")) {
    ENV(this_player())->try_attack(att);
    return 1;
  }
/* to quick butts can hurt ;-)                        */
  if(no_but) {
   if(random(2)) {
      write("Ouch, that was to early! You hurt yourself!\n");
      TP->reduce_hit_point(random(4)-helmet->armour_class());
   } else write ("You have to wait a while !\n");
   return 1;
  }

  if ((att) && (ENV(TP)==ENV(att)) && (living(att))) {
   if (random((30-level)*20) < 1) {
       xmsg="VICIOUS HIT !!\n";
    lev = lev + level * 20;
    } else xmsg="";
    xpl=TP;
    xdam=lev;
    xmsg+="You smash your head in the opponents face.\n";
    xatt=att;

    no_but = 1;
    return 1;
  }
  write("You are not fighting!\n");
  return 1;
}

time_guild_soul() {
    if(bash) bash--;
    if(bloarm && (!bwho || (ENV(TP)!=ENV(bwho)))) {
		destruct(bloarm);
		write("You stop blocking.\n");
		}
    if(!no_but) return;
    if(xatt && living(xatt) && ENV(xatt)==ENV(TP)) {
     write(xmsg);
     tell_object(xatt,xpl->query_name() + " smashes "+xpl->query_possessive()+
                 " head in your face.\n");
     say(xpl->query_name() + " smashes "+xpl->query_possessive()+
                 " head in "+xatt->query_name()+"'s face.\n");
     if (xpl) xpl->add_exp( xatt->hit_player(xdam) );
    }
    no_but=0;
}

munch() { return (BIN+"munch.c")->munch(); }

compare(str) { return (BIN+"compare.c")->compare(str); }

berzerk() {
  if(TP->query_ghost()) {
    write("You suddenly realize that this was a great mistake.\n" +
          "The whole room is spinning around you.\n" +
          "You decide to run as far as you can to leave this place.\n");
    TP->run_away();
    TP->run_away();
    write("As you feel your mind clearing you decide to rest for a moment.\n");
  }
	
  if(TP->query_level() < 18) {
    write("You are not strong enough.\n");
    return 1;
  }
  if (!TP->query_attack()) {
      write("You are not fighting anyone.\n");
      return 1;
  }
  if (is_berzerk) {
     write("You are as berzerk as anyone can be.\n");
     return 1;
  }
  if(bloarm) {
	write("You cannot berzerk whilst you are blocking.\n");
	return 1;
	}

  if (TP->query_spell_points()<40) {
     write("You are too tired to go berzerk.\n");
     return 1;
  }
  /* Gladiator changed this so the higher the level the longer the berzerk
     lasts, could be shorter also 931013*/
  call_out("anti_berz",40+TP->query_level());
  write("You turn into a rampaging frenzy.\n");
  is_berzerk=1;
  berz_where=ENV(this_player());
  TP->restore_spell_points(-40);
  owner=TPN;
  return 1;
}

anti_berz() {
  write("You get tired, and turn back normal.\n");
  is_berzerk=0;
  return 1;
}

recognize_fight() {   /* Used to hit the monster twice */
object enmy;

  if (!previous_object() || !(ENV(previous_object()))) {
     destruct(this_object());   /* Herp: probably in case of linkdeath */
     return;
  }

  enmy=TP->query_attack();
  enam=enmy->query_name();
  eobj=enmy->query_objective();
  epos=enmy->query_possessive();
  po=previous_object();
  wp=po->query_wielded();       /* The player's weapon */

  if (is_berzerk && enmy && (ENV(TP)==ENV(enmy))) {
    write("++++ ");
    TP->attack();
    if (TP->query_level() > 23) {
        write("#### ");
        TP->attack();
    }
    return;
  }
  if (is_berzerk && enmy) {
    if(ENV(TP)!=berz_where)
        write("You cowardly run away from battle ! You stop being berzerk.\n");
    else
        write("You calm down as your enemy flees.\n");
    remove_call_out("anti_berz");
    is_berzerk=0;
    return;
  }
}

no_spell() {
  write("You don't think a Fighter could cast a spell ????\n");
  return 1;
}

emote(str) { 
  "sys/chatd.c"->do_chat(gd,"[*Fighter*] "+TP->query_name()+" "+str+"\n");
  return 1;
}

fighter_line(str) { return TP->guild_line(str); }       /*171093 HERP*/

check(str) { return (BIN+"check.c")->check(str); }

rescue(arg) { return (BIN+"rescue.c")->rescue(arg); }

calm() {
	if(!is_berzerk) {
		write("You are not berzerking at the moment.\n");
		return 1;
		}
	if(TP->query_spell_points()<5) {
		write("You no longer have the mental energy to stop");
		return 1;
		}
	call_out("calm_stop",6);
	TP->restore_spell_points(-5);
	write("You start to calm yourself down.\n");
	return 1;
	}

calm_stop() {
	if(is_berzerk) {
		remove_call_out("anti_berz");
		is_berzerk=0;
		write("You feel that your are completely calm once again.\n");
		}
	return;
	}

shield_bash() {
	object att;
	int dex;

  if(!att=TP->query_attack()) {
	write("You are not fighting.\n");
	return 1;
	}
  if(!TP->query_armour()[TP->query_arm_types("shield")]) {
	write("You need a shield to bash with.\n");
	return 1;
	}
  if(ENV(TP)!=ENV(att)) {
	write("But your attacker is not here.\n");
	return 1;
	}
  if(ENV(this_player())->query_property("no_fight")) {
    ENV(this_player())->try_attack(att);
    return 1;
	}
  if(bash) {
	write("You loose your balance as you try to attack too soon.\n");
/*	The monster gets a free attack
	att->attack();   
	That was a bit nasty!   Its punishment enough that they cannot but or
	bash for another 3 rounds   */
	bash+=3;
	return 1;
	}
  if(no_but) {
	write("You dont have the self control to bash and butt at the same time.\n");
	return 1;
	}
	
	bash=2;
        dex=TP->query_dex();
        tell_object(att,TPN+" hits you with "+TP->query_possessive()+" shield.\n");
        TP->add_exp(att->hit_player(random(dex)+dex+5));
	write("You thump your opponent with your shield.\n");
	return 1;
	}

shield_block() {
	object att;
	int ac;

  if(!att=TP->query_attack()) {
	write("You are not fighting.\n");
	return 1;
	}

  if(!TP->query_armour()[TP->query_arm_types("shield")]) {
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

  transfer(bloarm=clone_object("/players/portil/guild/armour/bloarm.c"),TP);
  write("You start to block.\n");
  ac=(TP->query_dex()/10)+1;
  bloarm->set_ac(ac);
  TP->wear(bloarm);
  bwho=TP->query_attack();
  return 1;
}

lower() {
    if(!bloarm) {
	notify_fail("You are not blocking.\n");
	return 0;
	}

	destruct(bloarm);
	write("You lower your block.\n");
	return 1;
}
