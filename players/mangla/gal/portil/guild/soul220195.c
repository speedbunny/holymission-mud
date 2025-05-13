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
int no_but,bash;
int is_berzerk;                 /* Herp */
int gd;                         /* guildnumber (llort) */

/* the vars for timing the butt */
object xpl,xatt;
int xdam;
string xmsg;

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
  add_action("no_spell","missile");
  add_action("no_spell","shock");
  add_action("no_spell","fireball");
  add_action("fighter_line","fighters");
  add_action("fighter_line","fighter");
  add_action("emote","fighter/");
  add_action("guild_command","",1);
}

guild_command(str) {
	string verb;
	verb=query_verb();
	if(extract(verb,strlen(verb)-1)==".") return 0;
	if(file_size(BIN+verb+".c")<1) return 0;
	switch(verb) {
	    case "help": return ((BIN+"help.c")->help(str,GM,gd));
	    case "berzerk": return berzerk();
	    case "but": return but();
	    case "bash": return ((BIN+"bash.c")->bash(&bash,no_but));
	    case "block": return ((BIN+"block.c")->
		shield_block(&bloarm,is_berzerk,&bwho));
	    case "lower": return ((BIN+"lower.c")->lower(&bloarm));
	    default: return call_other(BIN+verb,verb,str);
	}
} 

berzerk() {
	object tp;
	if(((BIN+"berzerk.c")->berzerk(is_berzerk,bloarm))==1) return 1;
  /* Gladiator changed this so the higher the level the longer the berzerk
     lasts, could be shorter also 931013*/
	tp=TP;
	call_out("anti_berz",40+tp->query_level());
	is_berzerk=1;
	berz_where=ENV(tp);
	owner=tp->query_name();
	return 1;
}

anti_berz() {
        write("You get tired, and turn back normal.\n");
	is_berzerk=0;
	return 0;
}

but(str) {
  mixed *ret;
  ret=(BIN+"but.c")->but(bash,no_but);
  if(ret[0]==-1) return 1;
  xdam=ret[0];
  xmsg=ret[1];
  xatt=ret[2];
  xpl=TP;
  no_but = 1;
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

recognize_fight() {   /* Used to hit the monster twice */
   object enmy;

  if (!previous_object() || !(ENV(previous_object()))) {
     destruct(this_object());   /* Herp: probably in case of linkdeath */
     return;
  }
  enmy=TP->query_dex();
  enam=TP->query_name();
  eobj=TP->query_objective();
  epos=TP->query_possessive();
  po=previous_object();
  wp=po->query_wielded();       /* The player's weapon */

// multiattacks depending on the level 
  if (random(90) < enmy)
      TP->attack();
  if (random(50) < enmy)
      TP->attack();
  if (random(30) < enmy)
      TP->attack();
  if (random(20) < enmy)
      TP->attack();
  if (is_berzerk && enmy) {
//    write("++++ ");
    TP->attack();
    if (TP->query_level() > 23 ) {
//      write("#### ");
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
