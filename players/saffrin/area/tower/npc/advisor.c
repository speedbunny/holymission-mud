inherit "obj/monster";
#define ROOM "/players/saffrin/area/tower/quest/"

string quester;
int in;

reset(arg) {
    object ob;

    ::reset(arg);

    if(!arg) {
	set_alt_name("master");
	set_name("yorel");
	set_alias("mage master");
	set_short("Mage-Master Yorel the guild advisor");
	set_long("An old robed man, looking in your direction.\n");
	set_race("human");
	set_level(35);
	set_al(200);
	set_aggressive(0);
    }
    if (sizeof(explode(file_name(this_object()),"#"))==2 &&
      !present("portal",find_object("room/church")))
    {
/*
	"players/saffrin/guild/rooms/mshop"->_aa_();
	if(find_living("wuntvor")) 
	{
*/
	    say("Mage-Master Yorel says: Ohh, I have to cast a new portal at the church.\n");
	    say("Mage-Master Yorel utters the words 'pwgwcyep'\n");
	    call_out("_tel_church",2,environment());
/*
	}
*/
    }
}

_tel_church(object env)
{
    move_player("X#room/church");
    say ("Mage-Master Yorel utters the words 'irlwyq'\n");
    call_out("_do_portal",6,env);
}

_do_portal(object env)
{
    object p;
    p= clone_object("/players/saffrin/area/tower/obj/mportal");
    move_object(p,environment());
    p->set_portal(find_living("wuntvor"),10000);
    say("Mage-Master Yorel utters the words 'pwgwcyep'\n");
    call_out("_tel_home",2,env);
}

_tel_home(object env)
{
    move_player("X#players/saffrin/area/tower/room/oldstart");
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

    tell_room(environment(),"Mage-Master Yorel makes a gesture and stops the fight.\n");
    o=all_inventory(environment());
    for(i=0;i<sizeof(o);i++) {
	o[i]->stop_fight();
	o[i]->stop_fight();
	o[i]->stop_hunter(1);
    }
    return 1;
}

SAY(who,arg) {
    tell_object(who,"Mage-Master Yorel tells you: "+arg+".\n");
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
		    tell_object(who,"Mage-Master Yorel tells you: Sorry?\n");
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
	      "Mage-Master Yorel closes his eyes and concentrates for a while.\n");
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
	who->move_player("X#players/saffrin/area/tower/quest/c1");
	break;
    default:
	dummy=explode(what+" "," ");
	if(member_array("quest",dummy)!=-1 ||member_array("help",dummy)!=-1) {
	    SAY(who,"The quest is to clean the cellar from the rats");
	    SAY(who,"If you want to start the quest tell me: start quest");
	} else {
	    tell_object(who,"Mage-Master Yorel tells you: Sorry?\n");
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
    ad=clone_object("/players/saffrin/area/tower/npc/advisor");
    en=environment(this_object());
    move_object(ad,en);
}
run_away()
{
    return 0;
}
