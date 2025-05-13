/* This is the heroic soul of a fighter */
 
#define TP 	this_player()
#define TPN	this_player()->query_name()
#define	WRPRV(x)	tell_object(previous_object(),x)
#define TLOB(x)		tell_object(ob,x)
#define env 	environment
#define cap	capitalize
#define GM  	"guild/master"
#define GUILD 	"fighter"
 
id(str) { return str=="fighter_soul" || str=="fightersoul"; }

string enam,eobj,epos;
string owner; 
object wp,po;
int lev,level,no_but;
int is_berzerk;			/* Herp */
int gd;				/* guildnumber (llort) */

/* the vars for timing the butt */
object xpl;
int xdam;
string xmsg;
object xatt;
 
get() { return 1; }
drop() { return 1; }

reset(arg) {
  if(arg) return;
 /*
  gd=GM->query_number(GUILD);
 /*
}
 
init() {
  add_action("compare","compare");
 add_action("rescue","rescue");
  add_action("home","stronghold");
  add_action("no_spell","missile");
  add_action("no_spell","shock");
  add_action("no_spell","fireball");
  add_action("fighters","fighters");
  add_action("fhelp","fhelp");
  add_action("help","help");
  add_action("head_but","but");
  add_action("munch","munch");
  add_action("berzerk","berzerk");
  add_action("check","check");
}
 
   rescue(arg) {
    object friend, victim;

   friend=present(arg,environment(this_player()));
   victim=environment(friend);

    if (!arg) {
       write("Rescue whom ?\n");
       }
    else if (!friend) {
       write("A player must be present to rescue !\n");
     }
    else if (!living(friend)) {
      write("You can only rescue a living !\n");
      }
    else if (victim=friend->query_attack() && victim!=this_player()) {
      victim->attacked_by(this_player());
      write("You rescue "+friend->query_name()+" heroically.\n");
      tell_object(friend,this_player()->query_name()+" rescues you heroically.\
");
    return 1;
   }
   return 1;
  }

fhelp() {
  write("This command is replaced by 'help guild' now.\n");
  return 1;
}

help(arg) {
  switch(arg) {
    case "guild":
      TP->more ("/players/capablanca/guild/fhelp.txt");
      break;
    case "levels":
      GM->list_levels(gd);
      break;
    case "spell":
    case "spells":
      write("Fighters are not able to use spells.\n");
      break;
    default:
      return 0;
  }
  return 1;
}
 
home() {
  
  if(TP->query_ghost()) {
    write("Your home is situated in the hell. Go there if you don't wanna " +
          "stay there for ever!\n");
  }

  if(TP->query_level() < 10) { return; }
  if(TP->query_spell_points() < 10) { return; }
  if(environment(TP)->query_property("no_teleport")) {
    write("As you try to leave this place you bang your head an a "+
          "invisible wall of force.\n");
    return 1;
  }
  write("You use all you mental and physical powers to return to your " +
  "guild.\n\n");
  call_other(TP,"move_player","home#" +
  "players/capablanca/guild/restroom.c");
/*  "players/capablanca/guild/guild.c"); 030592 Llort auf restroom geaendert */
  TP->restore_spell_points(-10);
  return 1;
}
 
head_but(str) {
  string str1; 
  object att,helmet;
  att = TP->query_attack();
  level = TP->query_level();
  lev = (level/2 + 15);

  if(TP->query_ghost()) {
      write("Which head do you want to use ?\n");
      return 1;
  }
/* 920122 now we HAVE to use helmets -- LLort */
  if(!(helmet=TP->query_armour()[TP->query_arm_types("helmet")])) {
      write("You need a helmet to do that!\n");
      return 1;
  }
  
/*  920914 capa    head but funktioniert auch in no_fight area        */
  str1 = environment(this_player())->query_property();
  if(environment(this_player())->query_property("no_fight")) {
    environment(this_player())->try_attack(att);
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

if ((att) && (env(TP)==env(att)) && (living(att))) {
   if (random((30-level)*40) < 1) {
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
    if(!no_but) return;
    write(xmsg);
    if(xatt && living(xatt)) {
     tell_object(xatt,xpl->query_name() + " smashes "+xpl->query_possessive()+
                 " head in your face.\n");
     say(xpl->query_name() + "smashes "+xpl->query_possessive()+
                 " head in "+xatt->query_name()+"'s face.\n");
    }
    no_but=0;
    xpl->add_exp(xatt->hit_player(xdam));
}
 
munch() {
  object ob;
  int heal;

  if(TP->query_ghost()) {
    write("You wouldn't even be able to lick some blood from the corpse.\n");
  }

  ob = present("corpse",environment(TP));
  if(!ob) ob=present("corpse",TP);
  if(!ob) {
    write("Which corpse do you want to eat ?\n");
    return 1;
  }
/* changed by Llort 050592 */
  heal=random(ob->query_weight()+1);
  if(TP->eat_food(heal/2)) { 
     TP->heal_self(heal);
     write("You munch the corpse.\n");
     say(TP->query_name() + " munches the corpse.\n");
     destruct(ob);
  }
  return 1;
}
 
compare(str) {
  string wp1,wp2;
  object ob1,ob2;
  if(TP->query_spell_points() < 20 || TP->query_level() < 16) {
  return;
  }
  if(sscanf(str,"%s to %s",wp1,wp2) !=2)  {
    return 0;
  }
  if (!present(wp1,TP) || !present(wp2,TP)) {
  write("You don't have that stuff.\n");
  return 1;
  }
  ob1 = present(wp1,TP);
  ob2 = present(wp2,TP);
  if(ob1->weapon_class()+ob1->armour_class() > 
     ob2->weapon_class()+ob2->armour_class()) {
    write(wp1 + " glows in a strange red light.\n");
    return 1;
  } else if(ob1->weapon_class()+ob1->armour_class() == 
     ob2->weapon_class()+ob2->armour_class()) {
       write("Both things glow dim.\n");
  } else write(wp2 + " glows in a strange red light.\n");
  TP->restore_spell_point(-20);
  return 1;
}
 
berzerk() {
  if(TP->query_ghost()) {
    write("You suddenly realize that this was a great mistake.\n" +
          "The whole room is spinning around you.\n" +
          "You decide to run as far as you can to leave this place.\n");
    TP->run_away();
    TP->run_away();
    write("As you feel that your mind is clearing you decide to rest for a" +
          " moment.\n");
  }

  if(TP->query_level() < 20) {
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
  if (TP->query_spell_points()<40) {
     write("You are too tired to go berzerk.\n");
     return 1;
  }
  call_out("anti_berz",60);
  write("You turn into a rampaging frenzy.\n");
  is_berzerk=1;
  TP->restore_spell_points(-40);
  owner=TPN;
  return 1;
}
 
anti_berz() {
  write("You get tired, and turn back normal.\n");
  is_berzerk=0;
  return 1;
}

do_berz(ob) {
int i,j;

  i=0; j=0;
  if (wp) i=wp->hit(ob);
  if (i!="miss") {
     i=((po->query_wc()+i)*2+po->stat_dam())/3;
     if (i==0) i=1;
     if (ob) j=ob->hit_player(random(i));
  }
  if (!ob) return;	/* The enemy died */

  if (j==0) {
    WRPRV("*You missed "+enam+".\n");
    mysay("*"+owner+" missed "+enam+".\n",ob);
    TLOB("*"+owner+" missed you.\n");
    return;
  }
  if (j<=5) {
    WRPRV("You swing towards "+enam+".\n");
    mysay(owner+" swings towards "+enam+".\n",ob);
    TLOB(owner+" swings towards you.\n");
    return;
  }

  if (j<=10) {
    WRPRV("You hit "+enam+" with a mighty WHACK !\n");
    mysay(owner+" hits "+enam+" with a mighty WACK !\n",ob);
    TLOB(owner+" hits you with a mighty WHACK !\n");
    return;
  }

  if (j<=15) {
    WRPRV("You give "+enam+" a nose bleed.\n");
    mysay(owner+" gives "+enam+" a nose bleed.\n",ob);
    TLOB(owner+" gives you a nose bleed.\n");
    return;
  }

  if (j<=20) {
    WRPRV("You punch the nose of "+enam+". Blood sputters out.\n");
    mysay(owner+" punches the nose of "+enam+". Blood sputters out.\n",ob);
    TLOB(owner+" punches your nose. Blood sputters out.\n");
    return;
  }

  if (j<=25) {
    WRPRV("You knock "+enam+" down on the floor.\n");
    mysay(owner+" knocks "+enam+" down on the floor.\n",ob);
    TLOB(owner+" knocks you down on the floor.\n");
    return;
  }

  if (j<=30) {
    WRPRV("You punch "+enam+" into "+epos+" stomach. "+cap(eobj)+" coughs terribly.\n");
    mysay(owner+" punches "+enam+" into "+epos+" stomach. "+cap(eobj)+" coughs terribly.\n",ob);
    TLOB(owner+" punches you into the stomach. You cough terribly.\n");
    return;
  }
 
  if (j<=35) {
    WRPRV("You hit "+enam+" right into "+epos+" face. "+cap(eobj)+" loses some teeth.\n");
    mysay(owner+" hits "+enam+" right into "+epos+" face. "+cap(eobj)+" loses some teeth.\n",ob);
    TLOB(owner+" hits you right into your face. You lose some teeth.\n");
    return;
  }

  if (j<=40) {
    WRPRV("You hit "+enam+"'s forehead, beating out parts of "+epos+" brain.\n");
    mysay(owner+" hits "+enam+"'s on the forehead, beating out parts of "+epos+" brain.\n",ob);
    TLOB(owner+" hits you on the forehead, you feel like losing parts of your brain.\n");
    return;
  }

  if (j<=45) {
    WRPRV("You hit "+enam+"'s chest. There is a sound of braking ribs.\n");
    mysay(owner+" hits "+enam+"'s chest. There is a sound of breaking ribs.\n",ob);
    TLOB(owner+" hits your chest. You feel some of your rips breaking.\n");
    return;
  }

  if (j<=50) {
    WRPRV("You kick "+enam+"'s head. "+cap(eobj)+" nearly loses "+epos+" conscious.\n");
    mysay(owner+" kicks "+enam+"'s head. "+cap(eobj)+" nearly loses "+epos+" conscious.\n",ob);
    TLOB(owner+" kicks you on the head. You feel like losing your mind.\n");
    return;
  }

    WRPRV("You slam "+enam+" against the ground, makeing "+epos+" beg for mercy.\n");
    mysay(owner+" slams "+enam+" against the ground, makeing "+epos+" beg for mercy.\n",ob);
    TLOB(owner+" slams you against the ground, makeing you beg for mercy.\n");


}

recognize_fight() {   /* Used to hit the monster twice */
object enmy;

  if (!previous_object() || !(environment(previous_object()))) {
     destruct(this_object());	/* Herp: probably in case of linkdeath */
     return;
  }

  enmy=TP->query_attack();
  enam=enmy->query_name();
  eobj=enmy->query_objective();
  epos=enmy->query_possessive();
  po=previous_object();
  wp=po->query_wielded();	/* The player's weapon */

  if (is_berzerk && enmy && (env(TP)==env(enmy))) {
    if (TP->query_level() > 24) do_berz(enmy);
    do_berz(enmy);
    return;
  }
  if (is_berzerk && enmy) {
    write("You cowardly run away from battle ! You stop being berzerk.\n");
    remove_call_out("anti_berz");
    is_berzerk=0;
    return;
  }
}

no_spell() {
  write("You don't think a Fighter could cast a spell ????\n");
  return 1;
}

fighters(str) {
  string msg;
  object *u;
  int i;
  u = users();
  if(str) {
    for(i=0;i<sizeof(u);i++)
      if(u[i]->query_guild()==gd)
        tell_object(u[i],"[*"+TPN+"*] "+str+".\n");
        tell_object(TP,"Ok.\n");
        return 1;

     }
    msg = "Fighter's online:\n\n";
    for(i=0;i<sizeof(u);i++)
    if(u[i]->query_guild()==gd)
      if(!u[i]->query_invis()) {
      msg+=u[i]->query_name()+"\n";
      }
    write(msg);
    return 1;
}

mysay(str,opt) {
object *ob;
int i;

  ob=all_inventory(environment(previous_object()));
  if (opt)
    for (i=0;i<sizeof(ob);i++)
      if (ob[i]!=previous_object() && ob[i]!=opt) tell_object(ob[i],str);
  else
    for (i=0;i<sizeof(ob);i++)
      if (ob[i]!=previous_object()) tell_object(ob[i],str);
}

check(str) {
  object ob;
  int i; 
  if(!str) { return; }
  ob = present(str,environment(TP));
  if(!ob || !ob->query_npc()) {
    write("Check what ?\n");
    return 1;
  }  
  write("You check " + capitalize(str) + ".\n\n");
  if(TP->query_ac() > ob->query_ac()) {
    write("His armour is not as good as yours.\n");
  }
  else {     
    write("You think his armour is better.\n");
  }
  if(TP->query_wc() > ob->query_wc()) {
    write("Your weapon seems to be better.\n");
  }
  else {
    write("His weapon looks better than yours.\n");
  }
  if(TP->query_hp() < ob->query_hp()) { /* < not > - Moonchild */
    write("He is in better shape than you.\n");
  }
  else {
    write("You seem to be healthier.\n");
  }
  if(TP->query_level() < ob->query_level()) { /* < > */
    write("You think you can take him.\n");
  }
  else {
    write("A mighty opponent ...... be on guard, he could be able to kill you"+
          ".\n");
  }
  return 1;
}
