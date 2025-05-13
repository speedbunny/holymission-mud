inherit "/guild/prac_monster";

#define SPELLS ([\
  "light":                   1,\
  "magic missile":           1,\
  "shield":                  1,\
  "faerie fire":             2,\
  "armor":                   3,\
  "colorspray":              3,\
  "detect invisibility":     3,\
  "invisibility":            4,\
  "mirror image":            5,\
  "continual light":         6,\
  "infravision":             7,\
  "strength":                7,\
  "knock door":              8,\
  "lightning bolt":          8,\
  "fireball":                9,\
  "stoneskin":              10,\
  "scry":                   10,\
  "calm":                   11,\
  "fear":                   12,\
  "teleport":               13,\
  "fireshield":             14,\
  "pose":                   15,\
  "chainlightning":         16,\
  "haste":                  17,\
  "true sight":             25,\
  "gate":                   22,\
  "portal":                 30,\
  "meteor swarm":           43,\
])
#define NEW_SPELLS ({ \
  "light", "magic missile", "shield", "faerie fire", "armor", "colorspray", \
  "detect invisibility", "invisibility", "mirror image", "continual light", \
  "infravision", "strength", "knock door", "lightning bolt", "fireball", \
  "stoneskin", "scry", "calm", "fear", "teleport", "fireshield", "pose", \
  "chainlightning", "haste", "true sight", "gate", "portal", "meteor swarm", \
})

#define TP this_player()

#define ROOM "players/llort/guild/cellar/room/"

string quester;
int in;

// --------------------------------------------------------------------------
int advance_spell( object who, string sn, string fn, int max_sk )
{
   int res;

   if ( who->query_guild() != 5 ) {
      ltell("says:","You have to enroll in the Colleg of Magii,\n"+
            "            to be able to improve your knowledge here.\n",
            this_object());
      lsay( "says:","You have to enroll in the Colleg of Magii,\n"+
            "            to be able to improve your knowledge here.\n",
            this_object(), this_object());
      return( 1 );
   }

   if ( !SPELLS[sn]) {
      write("You can find no library-entry about this field of knowledge.\n");
      return( 1 );
   }

   res = ::advance_spell( who, sn, fn, 95 );
   switch ( res )
   {
      case -1:
          ltell( who, "says:", 
  "You already know as much in this skill, as you ever can learn here\n",
                  this_object() );
          break;
      case -2:
          ltell( who, "says:",
  "You have to go out to earn experience before comming here again!\n",
                  this_object() );
          break;
      default:
          write("You improve your knowledge in this field.\n");
          if(who->get_spell_skill(sn) == 95)
             write("You are now learned in this field.\n");
   }

   return( res );
}

int learn_spell( object who, string sn, string fn, int max_sk )
{
   int res, idx;

   if ( who->query_guild() != 5 ) {
      ltell("says:","You have to enroll in the Colleg of Magii,\n"+
            "            to be able to improve your knowledge here.\n",
            this_object());
      lsay( "says:","You have to enroll in the Colleg of Magii,\n"+
            "            to be able to improve your knowledge here.\n",
            this_object(), this_object());
      return( 1 );
   }

   if ( !SPELLS[sn] ) {
      write("You can find no library-entry about this field of knowledge.\n");
      return( 1 );
   }
   if ( SPELLS[sn] > (TP->query_level()+TP->query_legend_level()) ) {
      write("After studing for a while, you're sure, to be too unexperienced\n"+
            "to master this field of knowledge.\n");
      return( 1 );
   }

   res = ::learn_spell( who, sn, fn, 95 );
   switch ( res )
   {
      case -1:
         ltell(who,"says:","Somehow I cannot teach you this spell !\n",
               this_object() );
         break;
      case -2:
          ltell( who, "says:",
  "You have to go out to earn experience before comming here again!\n",
                  this_object() );
          break; 
      default:
         write("You start to understand a totally new field of knowledge.\n");
   }

   return( res );
}

_sort_spells(sp1,sp2)
{
    if(SPELLS[sp2] < SPELLS[sp1]) return 1;
    if(SPELLS[sp2] == SPELLS[sp1]) return sp2<sp1;
    return 0;
}

void list_prac( object who )
{
   string res, *sps, tmp;
   int    i, max, sk, mylev, actsk;

   if ( who->query_guild() != 5 ) {
      ltell("says:","You have to enroll in the Colleg of Magii,\n"+
            "            to be able to improve your knowledge here.\n",
            this_object());
      lsay( "says:","You have to enroll in the Colleg of Magii,\n"+
            "            to be able to improve your knowledge here.\n",
            this_object(), this_object());
      return;
   }

   max = m_sizeof( SPELLS );
   sps = m_indices( SPELLS );
   mylev = who->query_level()+who->query_legend_level();

   sps = sort_array(sps, "_sort_spells", this_object());

   res = "Your library-research reveals tomes to the following fields:\n"+
         "------------------------------------------------------------\n"+
         sprintf("Level %-20s %s\n",
                 "Name of field","Knowledge")+"\n";
   for ( i = 0; i < max && SPELLS[sps[i]] <= mylev; i++) {
      tmp=sps[i];
      actsk = who->get_spell_skill( tmp );
      res += sprintf( "[%2d]  %-20s %3d%%\n", SPELLS[tmp],
                        tmp, actsk < 0 ? 0 : actsk );
   }
   res += "-------------------------------\n";
   res += "You have "+who->practice_sessions()+
          " practice sessions left.\n";

   who->more_string( res );
}

reset(arg) {
object ob;

  ::reset(arg);

  if(!arg) {
    set_alt_name("advisor");
    set_name("yorel");
    set_alias("guild advisor");
    set_short("Lord Yorel the guild advisor");
    set_long("An old robed man, looking in your direction.\n");
    set_race("human");
    set_level(35);
    set_al(200);
    set_aggressive(0);
  }
  if (sizeof(explode(file_name(this_object()),"#"))==2 &&
      !present("portal",find_object("room/church")))
  {
     say("Yorel says: Ohh, I have to cast a new portal at the church.\n");
     say("Yorel utters the words 'pwgwcyep'\n");
     call_out("_tel_church",2,environment());
  }

   set_spells( NEW_SPELLS );
}

_tel_church(object env)
{
     move_player("X#room/church");
     say ("Yorel utters the words 'irlwyq'\n");
     call_out("_do_portal",6,env);
}

_do_portal(object env)
{
     object p;
     p = clone_object("players/llort/guild/obj/mportal");
     move_object(p,environment());
     p->set_portal("players/llort/guild/room");
     say("Yorel utters the words 'pwgwcyep'\n");
     call_out("_tel_home",2,env);
}

_tel_home(object env)
{
     move_player("X#players/llort/guild/room");
}

hit_player(dam) {
  return 0;
}

attack() {
  if(attacker_ob) query_ghost();
}

query_ghost() {
  object o;
  int i;

  tell_room(environment(),"Yorel makes a gesture and stops the fight.\n");
  o=all_inventory(environment());
  for(i=0;i<sizeof(o);i++) {
    o[i]->stop_fight();
    o[i]->stop_fight();
    o[i]->stop_hunter(1);
  }
  return 1;
}

SAY(who,arg) {
  tell_object(who,"Lord Yorel tells you: "+arg+".\n");
}

catch_tell(arg) {
  string dummy,who,what,a;
  object ob;

  arg = process_string( arg );                /* pat */

  if(sscanf(arg,"%s tells you: %s\n",who,what)!=2) {
    if(sscanf(arg,"%s says: %s\n",who,what)!=2) 
      return;
    else {
      what=lower_case(what);
      who=lower_case(who);
      who=find_living(who);
      if(!who) return;
      dummy=explode(what," ");
      if(member_array("yorel",dummy)!=-1 || member_array("advisor",dummy)!=-1) {
        if(member_array("quest",dummy)!=-1 || member_array("help",dummy)!=-1) {
          SAY(who,"The quest is to clean the cellar from the rats");
          SAY(who,"You'll get 500 coins if you finish it");
          SAY(who,"If you want to start the quest tell me: start quest");
          return;
        } else {
        tell_object(who,"Lord Yorel tells you: Sorry?\n");
        return;
        }
      }
      return;
    }
  }
  dummy=explode(who," "); 
  who=dummy[sizeof(dummy)-1];
  what=lower_case(what);
  who=lower_case(who);
  who=find_living(who);
  if(!who) return;
  switch(what) {
    case "start quest":
    case "start quest\n":
      if(quester && (ob=find_living(quester)) && !ob->query_linkdeath()) {
        SAY(who,"Sorry, but "+capitalize(quester)+" is already working on the "+
            "quest");
        return;
      }
      if(count_rats()<15) {
        SAY(who,"Sorry, we don't need you right now. Please try later");
        return;
      }
      SAY(who,"Ok, you're hired for the quest");
      SAY(who,"Tell me: finished quest, if you are");
      SAY(who,"Tell me: end quest, if you want to cancel");
      SAY(who,"Tell me to move you in if you want to enter the cellar");
      SAY(who,"Tell me to move you out if you want to leave the cellar");
      quester=who->query_real_name();
      break;
    case "finished quest":
      if(who->query_real_name()!=quester) {
        SAY(who,"Sorry, you are not hired");
        return;
      }
      if(count_rats()>0) {
        tell_object(who,
              "Yorel closes his eyes and concentrates for a while.\n");
        SAY(who,"Oh, you forgot "+count_rats()+" rats.\n"+  
            "Did you look at the rat hole? "+
            "Tell me if you finished them");
        return;
      }
      SAY(who,"Ok, you solved the quest");
      SAY(who,"I sent you 500 coins for clearing the cellar");
      who->set_quest("ratsquest");
      who->add_money(500);
      quester=0;  
      break;
    case "end quest":
      if(who->query_real_name()!=quester) {
        SAY(who,"Sorry, you are not hired");
        return;
      }
      SAY(who,"Ok, you're canceled");
      quester=0;
      break;
    case "move out":
    case "move me out":
      if(who->query_real_name()!=quester) {
        SAY(who,"Sorry, you are not hired");
        return;
      }
      if(!in) {
        SAY(who,"Sorry, I didn't move you in, i won't move you out");
        return;
      }
      if(!environment(who)->query_cellar()) {
        SAY(who,"Sorry, but I can't move you out of the cellar if are not in");
        return;
      }
      in=0;
      who->move_player("X",environment());
      break;
    case "move in":
    case "move me in":
      if(who->query_real_name()!=quester) {
        SAY(who,"Sorry, you are not hired");
        return;
      }
      if(!present(quester,environment())) {
        SAY(who,"Sorry, you have to come here if I shall move you in");
        return;
      }
      in=1;
      who->move_player("X#players/llort/guild/cellar/room/c1");
      break;
    default:
      dummy=explode(what+" "," ");
      if(member_array("quest",dummy)!=-1 ||member_array("help",dummy)!=-1) {
        SAY(who,"The quest is to clean the cellar from the rats");
        SAY(who,"If you want to start the quest tell me: start quest");
      } else {
        tell_object(who,"Lord Yorel tells you: Sorry?\n");
        return;
      } 
  }
}

count_rats() {
  int i,rnr;
  object ob;

  call_other(ROOM+"c1","???");
  call_other(ROOM+"c2","???");
  call_other(ROOM+"c3","???");
  call_other(ROOM+"c4","???");
  call_other(ROOM+"c5","???");
  call_other(ROOM+"c6","???");
  call_other(ROOM+"c7","???");
  ob=all_inventory(find_object(ROOM+"c1"));
  ob+=all_inventory(find_object(ROOM+"c2"));
  ob+=all_inventory(find_object(ROOM+"c3"));
  ob+=all_inventory(find_object(ROOM+"c4"));
  ob+=all_inventory(find_object(ROOM+"c5"));
  ob+=all_inventory(find_object(ROOM+"c6"));
  ob+=all_inventory(find_object(ROOM+"c7"));

  for(i=rnr=0;i<sizeof(ob);i++) if(ob[i]->id("rat")) rnr++;
  return rnr;
}

query_no_summon() { return 1; }

_notify_destruct(ob)
{
   object ad,en;
   query_ghost();
   ad=clone_object("/players/llort/guild/monster/advisor");
   en=environment(this_object());
   move_object(ad,en);
}

run_away()
{
    return 0;
}

hand_wscrolls(n)
{
    object sc; 
    int i;

    for(i=0;i<n;i++)
    {
        sc=clone_object("players/llort/secure/wscroll");
        transfer(sc,this_interactive());
        write("Yorel hands you a scroll.\n");
    }
    write(
"Yorel says: To get information about the scrolls find the secret library\n"+
"            and search for Elminsters Tome of Wonders!\n");
}

hand_lwscrolls(n)
{
    object sc; 
    int i;

    for(i=0;i<n;i++)
    {
        sc=clone_object("players/llort/secure/lwscroll");
        transfer(sc,this_interactive());
        write("Yorel hands you a scroll.\n");
    }
    write(
"Yorel says: To get information about the scrolls find the secret library\n"+
"            and search for Elminsters Tome of Wonders!\n");
}

init()
{
    ::init();
}

_ask(a)
{
    int i;
    if(a!="yorel for scrolls") return;
    if(!(i=this_player()->query_legend_level())) return;
    if(this_player()->queryenv("gotwishes")) return;
    write(
"Yorel says: Hello, I have to give you the scrolls you earned for you legend\n"+
"            levels.\n");
    this_player()->setenv("gotwishes",1);
    if(i>10)
    {
        hand_lwscrolls(10);
        hand_wscrolls(i-10);
    }
    else
    {
        hand_lwscrolls(i);
    } 
    log_file("asks",this_player()->query_real_name()+
             " asked for his scrolls\n");
    return 1;
}
