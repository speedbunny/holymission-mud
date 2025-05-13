inherit "obj/monster";
#include "/players/mangla/defs.h"

string func,match,type;
string *gotten;

_give(str) {

    if(!str && str != "return" && str != "return trip") {
        notify_fail("What are you requesting?\n");
        return 0;
    }
    else if(member_array(TP->RNAME,gotten) != -1) {
        printf("You have already recieved your bonus for the day.\n");
        return 1;
    }
    else {
        if(!present("return",TP)) {
        printf("You feel you have gained something.\n");
        write("Something being a return trip home.\n");
        transfer(clone_object("/players/mangla/guild/obj/return"),TP);
        gotten += ({ TP->RNAME });
        }
    }
    return 1;
}

reset(arg) {
  ::reset(arg);
  if(arg) return;
  gotten = allocate(0);
  set_name("ben");
  set_alias("kenobi");
  set_alt_name("obiwan");
  set_level(50);
  set_al(1000);
  set_race("human");
  set_gender(1);
  set_size(3);
  set_short("Ben Kenobi");
  set_long("He is dressed in white, has a friendly look on his face.\n"+
  "Maybe you know him as Obiwan Kenobi.\n" +
  "If you request a return trip to the guild he might grant you one.\n");

  load_chat(5, ({
      "Ben says: How can I help you?\n",
      "Ben says: Nice to see you.\n",
      "Ben says: Hi, how are you?\n",
      "Ben smiles merrily.\n",
    }) );
  load_a_chat(20, ({
      "Ben frowns.\n",
      "Ben says: Who has put you up to that ?\n",
      "Ben says: Leave before it is too late, I don't want to kill you.\n",
      "Ben doesn't seems to be very happy.\n",
    }) );
    set_array();
    set_match(this_object(),func,type,match);

    if(!present("jedisoul"))
      MOVE(clone_object("players/mangla/guild/soul"),TO);
}

init() {
  ::init();
  if(TP && TP->query_invis() < 30)
     handle_arrive(capitalize(this_player()->query_real_name())+
        " arrives.");
    add_action("_give","request");
}

query_guild() {
    return 4;
}

hit_player(ob,i,j) {
    write("You cannot reach Ben Kenobi.\n");
}

reduce_hit_point(dam) {
  if(attacker_ob->query_real_name()=="kelly")
    write("Damn: "+dam+".\n");
  ::reduce_hit_point(0);
}

attack(ob) {
  if(!attacker_ob) return;

  if(!present("lightsaber",this_object()))  {
    MOVE(clone_object("players/mangla/guild/lightsaber"),TO);
    say("Ben fetches something.\n");
    init_command("wield handle");
    init_command("press button");
  }
  if(!random(10)) init_command("bolt");

  ::attack(ob);
}

handle_arrive(str) {
  string who,what;
  object talker,obj;
    int wcnew;

  if(sscanf(str,"%s arrives%s",who,what)!=2) {
     say("Ben looks confused.\n");
     return 1;
  }

/*Corrected by Portil 271093 removed !talker error*/
  talker=find_player(lower_case(who));
  if(!talker) {
    say("Ben looks confused.\n");
    return 1;
  }

/*Corrected by Portil 271093...
It didn`t say `Hi` to the player who had just entered the room*/
tell_room(environment(this_object()),"Ben says:"+
  "Hi, "+talker->query_short_name()+".\n");

  if(talker->query_real_guild() != 4) return 1;
  if(!present("lightsaber",talker) && !talker->query_immortal()) {
    tell_object(talker,"Ben says: I suppose you have come here for a light"+
                "saber.\n");
    obj=clone_object("players/mangla/guild/lightsaber");
    wcnew = talker->query_level();
    if(wcnew > 20) wcnew = 20;
    else if(wcnew < 5) wcnew = 5;
    obj->set_class(wcnew);
    if(!transfer(obj,talker))
  tell_object(talker,"Ben says: Here you are.\nBen gives you a simple handle.\n");
   else
      tell_object(talker,"You cannot carry anymore.\n");
   
  if(!present("jedicloak",talker) && !talker->query_immortal()) {
    tell_object(talker,"Ben says: Do you want a cloak as well?\n");
    obj = clone_object("players/mangla/guild/cloak");
    if(!transfer(obj,talker))
      tell_object(talker,"Ben says: Here you are.\nBen gives you a cloak.\n");
    else
      tell_object(talker,"You cannot carry anymore.\n");
  }
}
  return 1;
}

/*Altered by Portil 271093... No point in having handle_say at all
nevermind twice??!!*/

set_array() {
  func = ({"handle_arrive"});
  type = ({"arrives"});
  match = ({""});
}

run_away() {
  return 0;
}
