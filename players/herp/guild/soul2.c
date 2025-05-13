/* 920228 mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith	 */

/*-----------------------------*/
/* The black soul of a thief   */
/*-----------------------------*/

/* The following actions are valid for a thief:			*/
/*								*/
/* hide		...  hide in the shadows
   unhide	...  appear from the shadows
   steal	...  steal from a monster or player
   sneak	...  sneak (monsters don't block)
   picklock	...  use picklocks to open doors
   weave	...  confuses your attacker		REMOVED
   hideout	...  go to the thieves hideout
   leave	...  go back from the hideout
   backstab	...  do immense damage to a monster
   help		...  help file display
*/

#define GM	"guild/master"
#define GUILD	"thief"
#define TP	this_player()
#define TO	this_object()
#define TPN	TP->query_name()
#define TPR	TP->query_real_name()
#define TPS	TP->query_short_name()
#define TPL	TP->query_level()
#define TPDX	TP->query_dex()
#define env	environment
#define SAY(x)	tell_room(env(TP),x)

#define CHK_ATT(); \
if ((att=TP->query_attack()) && present(att,env(TP))) {\
   write("You are much too busy to do that.\n");\
   return 1;\
}

#define MIN_HIDDEN	60			/* 1 minute */
#define MAX_HIDDEN	900			/* 15 minuten */
#define MAX_UNHIDDEN	300			/* 5 minuten  */
#define BE_HIDDEN (MIN_HIDDEN+(MAX_HIDDEN-MIN_HIDDEN)*(TPDX-1)/(max_stats))
#define	AL_STEALMONEY	-10			/* aligment: steal money */
#define AL_STEALITEM	-50			/*	     steal item */
#define SP_WEAVE	30			/* weave spell cost */
#define LV_STBAG	25			/* level for bag stealing */

int stay_hidden;
int dont_hide;
int max_stats;
int gd;

int is_hideout;					/* 1 if in hideout */

string name;					/* Whos soul is it */
string pronoun;
string id;					/* guild soul */	
string dir;					/* guild directory */
string helpdir;					/* guild helpdir */
string hideout;					/* guild hideout */
string room;					/* guild room */

object att;					/* Global: attacker */
object hide;					/* return from hideout */

int has_stolen;					/* Moonchild stop macro abuse */

id(str) { return str==id; }

get() { return 1; }

drop() { return 1; }				/* don't drop */

reset(arg) {
  if (arg) return;
  gd=GM->query_number(GUILD);
  max_stats=GM->query_levels(gd);
  id=GM->query_id(gd);
  dir=GM->query_dir(gd);
  helpdir="/"+dir+"/helpdir";
  hideout=dir+"/hideout";
  room=GM->query_room(gd);
}

extra_look() { return capitalize(pronoun)+ " has just sneaked into the city."
			     + " Yet "+pronoun+" is robbing you blind."; }

#if 0
short() { return "A black shadow"; }
#endif

init() {
  add_action("hide","hide");
  add_action("unhide","unhide");
  add_action("steal","steal"); 
  add_action("sneak","sneak");
  add_action("picklock","picklock");
  add_action("weave","weave");
  add_action("hideout","hideout");
  add_action("leave","leave");
  add_action("backstab","backstab");
  add_action("help","help");
  add_action("thief","thief");
  add_action("thief","guild");

  stay_hidden=0;
  if (TPR) name=capitalize(TPR);
  pronoun=TP->query_pronoun();

}

/* ################	hide	################## */

hide() {

  if (TP->query_invis()) {
     write("You are already hidden in the shadows.\n");
     return 1;
  }
  if (!TP->query_wizard() && dont_hide) {
     write("You have to wait longer before you can do that again.\n");
     return 1;
  }

  if (TP->query_ghost()) {
     write("You cannot hide more than you are hidden now.\n");
     return 1;
  }

  CHK_ATT();
  write("You hide in the shadows.\n");
  say(TPN+" leaves suddenly.\n");
  TP->set_invis();
  if (TP->query_wizard()) return 1;	/* Wiz stay hidden infinitely */
  
  stay_hidden+=BE_HIDDEN-remove_call_out("timer"); /* delta t */
  stay_hidden--;				/* -1 falls nicht am stack */ 

  if (stay_hidden>BE_HIDDEN) stay_hidden=BE_HIDDEN; 
  call_out("unhide",stay_hidden);
  return 1;
}

/* ##############	unhide	################### */

unhide() {

  if (TP->query_ghost()) {
     write("You try to show yourself to mortal men.\n");
     return 1;
  }
 
  if (!TP->query_invis()) {
     write("You are not hiding !\n");
     return 1;
  }
  stay_hidden=remove_call_out("unhide");
  if (stay_hidden==-1) {	 	/* darf sich nicht mehr verstecken */
      dont_hide=1;
      call_out("allow_hide",MAX_UNHIDDEN);
  }
  else call_out("timer",BE_HIDDEN);	/* hide stellt dann fest wie lange */
					/* unhidden war.		   */

  TP->set_vis();
  move_object(TP,env(TP));
  SAY(TPN+" "+TP->query_msgin()+".\n"); 
  return 1;
}

allow_hide() {
   stay_hidden=0;
   dont_hide=0;		/* wieder erlauben */
}

timer() {
}

/* ##############	steal	############### */

steal(str) {
string what,whom; 
object obji,objp;
int i,ddex;
int coins;

  if (has_stolen) return 1; /* Moonchild stop macro abuse */

  if (TP->query_ghost()) {
     write("You are not interested in the material world.\n");
     return 1;
  }
  
  CHK_ATT();
  if (!str || !(sscanf(str,"%s from %s",what,whom)==2)) return;
  if (!(objp=present(whom,environment(this_player())))) {
     write("There is no "+whom+" present.\n");
     return 1;
  }
  if (!living(objp)) {
     write("You try to steal "+str+".\n");
     write("Not very effective.\n");
     return 1;
  }
  if (what=="money") what=="coins";
  if (what!="coins" && !(obji=present(what,objp))) {
     write(capitalize(whom)+" doesn't posses such an item.\n");
     return 1;
  }
  
  if (objp->query_immortal()) { /* changed by Moonchild, could steal from 31 */
     write("You cannot steal from wizards.\n");
     return 1;
  }
  if (objp->query_linkdeath()) {
     write("You cannot steal from "+objp->query_name()+", "+
	   objp->query_pronoun()+" is stoned.\n");
     return 1;
  }

  if (what=="bag" && TP->query_dex()<=LV_STBAG) {  /* Ok if high enough */
     write(objp->query_name()+" would notice if you steal that.\n");
     return 1;
  }

  else if (env(TP)->query_property("no_steal")) {
     write("Your stealing would be recognized in this room.\n");
    return 1;
  }
  else if (objp->query_property("no_steal")) {
     write(objp->short()+" doesn't look like one whom you can steal from.\n");
     return 1;
  }

  /* Compute the random value according to the following rules:
     if two players are of the same level, the thief gets a change of
     50:50 that he can success in stealing.
     if the thief is GM->max_levels - 1 dex-levels above his victim, he
     gets a chance of 99 % that he will succeed in stealing.
  */

  has_stolen=1;
  call_out("has_stolen",1,0); /* Moonchild stop macro abuse */
  ddex=(TP->query_dex()-objp->query_dex())*50/(max_stats-1)+50;
  if (random(101)>=ddex) {	/* Steal fails */
     say(TP->query_name()+" tried to steal "+what+" from "+objp->query_name()+".\n",objp);
     write(objp->query_name()+" notices your steal !\n");
     if (objp->query_npc()) {
	write(objp->query_name()+" attacks !\n");
	objp->attack_object(TP);
	return 1;
     }
     tell_object(objp,TP->query_name()+" tried to steal "+what+" from you !\n");
     return 1;
  }

  if (what=="coins") { 			/* Geld fladern */
     coins=objp->query_money();
     if (coins>TPL*100) coins=TPL*100;
     if (!coins) {
	write(objp->query_name()+" doesn't posess even a single coin.\n");
	return 1;
     } 
     coins=random(coins)+1;
     TP->add_money(coins);
     objp->add_money(-coins);
     write("You have stolen "+coins+" coins from "+objp->query_name()+".\n");
     i=random(4);
     if (!TP->query_invis()) switch (i) {
     case 0:tell_object(objp,"There is a rustling noise in your purse.\n");
	    break;
     case 1:tell_object(objp,"You feel your purse is getting lighter.\n");
	    break;
     case 2:tell_object(objp,"You feel a hand in your pocket.\n");
	    break;
     case 3:tell_object(objp,"You feel a soft touch in your pocket.\n");
	    break;
     }
     TP->add_alignment(AL_STEALMONEY); /* Thieves are mostly nasty persons */ 
     return 1;
  }

  if (obji->query_wielded(obji)) {
     write("You can't steal wielded stuff, you omit that silly action.\n");
     return 1;
  }
  if (obji->query_worn(obji)) {
     write("You can't undress "+objp->query_name()+".\n");
     return 1;
  }
  if (!(i=transfer(obji,this_player()))) {
     i=random(4);
     if (!TP->query_invis()) switch (i) {
     case 0 : tell_object(objp,"You feel like you are missing something.\n");
	      break;
     case 1 : tell_object(objp,"You seem to have lost a "+what+".\n");
	      break;
     case 2 : tell_object(objp,"You feel a soft touch on your body.\n");
	      break;
     case 3 : tell_object(objp,"You are just missing a "+what+".\n");
	      break;
     }
     write("You have stolen "+what+" from "+objp->query_name()+".\n");
     TP->add_alignment(AL_STEALITEM);	/* They ARE nasty ... */
     return 1;
  }
  else {
     if (i==1) write("You can't carry any more.\n");
     else write("You cannot steal the "+what+" from "+objp->query_name()+".\n");
     return 1;
  } 
}

has_stolen() { has_stolen=0; }

/* ##############	sneak	################ */

sneak(str) {
object ob;

  if (TP->query_ghost()) {
     write("You would move through walls, you don't need to sneak.\n");
     return 1;
  }

  CHK_ATT();
  if (!str) return;
  switch (str) {
  case "n" : str="north";	break;
  case "s" : str="south";	break;
  case "w" : str="west";	break;
  case "e" : str="east";	break;
  case "u" : str="up";		break;
  case "d" : str="down";	break;
  case "nw": str="northwest";	break;
  case "ne": str="northeast";	break;
  case "sw": str="southwest";	break;
  case "se": str="southeast";	break;
  }
  if (!TP->query_invis()) {
     write("You would be discovered.\n");
     return 1;
  }
  if (env(TP)->move(str)) return 1;
  /* if we can't go in it's probably a castle ? */
  ob=present("castle",env(TP));
  if (ob=present("castle",env(TP)) && ob->move(str)) return 1;
  write("You bang your head.\n");
  TP->reduce_hit_point(random(20)+1);	/* That hurts !!! */
  return 1;

}

/* #############	picklock	############ */

picklock(str) {
object pl,door; 
int i,num_doors;
string dest;

  if (TP->query_ghost()) {
     write("You could move through they keyhole ...\n");
     return 1;
  }

  CHK_ATT();
  if (!str) return;
  if (str!="door" && sscanf(str,"%s door",dest)!=1) return;
  if (!(pl=present("picklock",TP))) {
     write("You don't have a picklock.\n");
     return 1;
  }
  if (pl->query_broken()) {	/* It was broken ... get the next one */
     pl=next_inventory(pl);
     while (pl) {
	if (pl->id("picklock") && !pl->query_broken()) break; /* unbroken */
	pl=next_inventory(pl);
     }
     if (!pl) {
	write("Your picklock is broken.\n");
	return 1;
     }
  }

  if (!(door=present(str,env(TP)))) return;
  if (str=="door" && (num_doors=door->number_of_doors())!=1) {
     door->which_door();
     return 1;
  }
  if (!door->query_locked()) {
     write("Don't waste your picklock on an unlocked door.\n");
     return 1;
  }
  i=TP->query_dex()*100/max_stats;
  if (random(101)>=i) {
     pl->set_broken();
     write("CRACK ! You brake the picklock with your greedy fingers.\n"); 
     return 1;
  }

  write("You use the picklock and open the "+str+".\n");
  door->set_locked(0);
  door->query_partner_door()->set_locked(0);
  if (random(101)>=i) {
     pl->set_broken();
     write("But your picklock broke.\n");
  }
  return 1;
   
}

#if 0
/* ###############	weave	################# */

weave(str) {		/* Costs 30 spellpoints */
object wat,*ob;
int nwat;
int i,j,sz;

  if (!str) {
     write("Weave at whom ?\n");
     return 1;
  }

  if (!(wat=present(str,env(TP)))) return;	/* Weave at what ? */
  if (!living(wat)) {
     write("The "+str+" seems to ignore you.\n");
     return 1;
  }
  if (TP->query_ghost()) {
     write("You cry BOOOH at "+str+".\n");
     tell_object(wat,TPN+" cries BOOOH at you.\n");
     return 1;
  }

  if (TP->query_spell_points()<30) {
     write("You are too braindamaged now to do that.\n");
     return 1;
  }
  TP->restore_spell_points(-SP_WEAVE);		/* Subtrace BEFORE random */
  write("You concentrate your psychic energies.\n");
  i=TP->query_chr()*100/max_stats;
  if (random(101)>i) {
     write("You lose your concentration.\n");

     /* If losing concentration, the attacker can hit back ! */
     if (random(2)) {
	write(wat->short()+" hits you another time !\n");
	wat->attack();
     }
     recognize_fight();
     return 1;
  }
 
  /* Search a new victim for "wat" to attack :-) */
 
  ob=all_inventory(env(TP));
  sz=sizeof(ob);
  nwat=allocate(sz);
  j=-1;
  for (i=0;i<sz;i++)
      if (living(ob[i]) && ob[i]!=TP && ob[i]!=wat && !ob[i]->query_ghost() && !ob[i]->query_wizard())
	nwat[++j]=i;
  
  if (j<0)		/* Couldn't find an other attacker */
     wat->attack_object(TP);
  else {
    i=random(j+1);	/* This now is the new attacked object */
    wat->attack_object(ob[nwat[i]]);
    SAY(name+" confused "+wat->query_name()+".\n");
    SAY(wat->query_name()+" suddenly starts to attack "+ob[nwat[i]]->query_name()+" !\n");
  }
  return 1; 

}
#endif

/* ########	hideout		###### */

hideout() {

  if (is_hideout) {
     write("You don't want to do that.\n");
     return 1;
  }
  if (env(TP)->has_drink(TP)) {
     write("You are not allowed to leave with drinks!\n");
     return 1;
  }
  if (env(TP)->query_property("no_teleport")) {
    write("As you try to run to the hideout you bang against an "+
	  "invisible wall of force.\n");
    return 1;
  }
  hide=env(TP);
  is_hideout=1;
  TP->move_player("X#"+hideout);
  return 1;
}

/* #########	leave		####### */

leave(str) {

  if (str) return;
  if (!is_hideout) {
     write("You are not in the hideout !\n");
     return 1;
  }
  if (hide) TP->move_player("X",hide);
  else TP->move_player("X#"+room);		/* object was destructed */
  write("You have returned.\n");
  is_hideout=0;
  return 1;
  }

/* #########	backstab ######## */

backstab(str) {
object ob;

  if (!str) {
     write("Backstab whom ?\n");
     return 1;
  }

  if (!(ob=present(str,env(TP))) || !living(ob)) {
     write("No "+str+" here !\n");
     return 1;
  }
  if (!TP->query_invis() || (ob->query_hp()<ob->query_max_hp())) {/*Moonchild*/
     write("You run towards "+ob->query_name()+".\n");
     write(ob->query_name()+" recognises you !\n");
     ob->attack_object(TP);
     ob->attack();
     return 1;
  }
  CHK_ATT();
  if (TP==ob->query_attack()) {
     write(ob->query_name()+" is ready for you.\n");
     return 1;
  }
  write("You sneak past "+ob->query_name()+" and backstab "+ob->query_objective()+".\n");
  ob->attack_object(TP);
  TP->add_exp(ob->hit_player(TPL*3*(TPDX/10+1)));
  return 1;
}

/* #########	help	######### */

help(str) {

  if (str=="guild") str="thief";
  switch (str) {
  case "levels":
  case "thief":
  case "hide":
  case "unhide":
  case "sneak":
  case "steal":
  case "picklock":
  case "hideout":
  case "leave":
  case "backstab":break;
#if 0
  case "weave": break;
#endif
  default: return 0;
  }

  if (str!="levels") cat(helpdir+"/"+str);
  else list_levels();
  return 1; 
}

/* ##########	thief		############# */

thief(str) {
string msg,na;
object *u;
int i;

  u=users();
  msg="Thieves online:\n\n";
  if (str) na=TPS;
  for (i=0;i<sizeof(u);i++)
      if (u[i]->query_guild()==gd)
	 if (str) tell_object(u[i],"[*Thief "+na+"*] "+str+"\n");
	 else if (!str) msg+=u[i]->query_name()+"\n";
  if (!str) write(msg);
  return 1;
}
       

  
/* ##########	list_levels	############# */

list_levels() { return GM->list_levels(gd); }

/* ##########	recognize_fight() ########### */

recognize_fight() {

  if (TP->query_invis()) {
     write("You come out of the shadows.\n");
     TP->set_vis();
     move_object(TP,env(TP));
  }
}
  
