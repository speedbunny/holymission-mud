/*Changed on 271093 by Portil*/
/*"/players/kelly/guild/ben.c"*/
inherit "obj/monster"; 

string func,match,type;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("ben");
  set_alias("kenobi");
  set_alt_name("obiwan");
  set_level(50);
  set_al(1000);
  set_race("human");
  set_male();
  set_size(3);
  set_short("Ben Kenobi");
  set_long("He is dressed in white, has a friendly look on his face.\n"+
  "Maybe you know him as Obiwan Kenobi.\n");

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
      move_object(clone_object("players/kelly/guild/soul"),this_object());
}

/* 101292 Llort: just a 'notbremsn' */
init() {
  ::init();
  if(this_player() && !this_player()->query_invis())
     handle_arrive(capitalize(this_player()->query_real_name())+
        " arrives.");
}

hit_player(ob) {
  if(attacker_ob->query_wielded()) 
    write("Your weapon seems to have no effect on Ben Kenobi.\n");
  else 
    write("You cannot reach Ben Kenobi.\n");
  ::hit_player(0);
}

reduce_hit_point(dam) {
  if(attacker_ob->query_real_name()=="kelly") 
    write("Damn: "+dam+".\n"); 
  ::reduce_hit_point(0);
}

attack(ob) {
  if(!attacker_ob) return;
 
  if(!present("lightsaber",this_object()))  {
    move_object(clone_object("players/kelly/guild/lightsaber"),this_object());  
    say("Ben fetches something.\n");            
    init_command("wield handle");
    init_command("press button");
  }
  if(!random(10)) init_command("bolt"); 

  ::attack(ob);
}

query_guild() { return 4; }

query_spell_points() { return 200; }

handle_arrive(str) {
  string who,what;
  object talker,obj;

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
  tell_room(environment(this_object()),"Ben says: Hi, "+talker->query_short_name()+".\n");
  if(!present("lightsaber",talker)) {
    tell_object(talker,"Ben says: I suppose you have come here for a light"+
                "saber.\n");
    obj=clone_object("players/kelly/guild/lightsaber");
    if(!transfer(obj,talker))
      tell_object(talker,"Ben says: Here you are.\nBen gives you a simple handle.\n");
    else
      tell_object(talker,"You cannot carry anymore.\n");
  } 
  if(!present("jedicloak",talker)) {
    tell_object(talker,"Ben says: Do you want a cloak as well?\n");
    obj=clone_object("players/kelly/guild/cape");
    if(!transfer(obj,talker))
      tell_object(talker,"Ben says: Here you are.\nBen gives you a cloak.\n");
    else
      tell_object(talker,"You cannot carry anymore.\n");
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
