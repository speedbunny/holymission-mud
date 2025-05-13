inherit "obj/monster";

int scalps;
string function,type,match,function2,type,match,chat,hero;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("hermit");
  set_race("human");
  set_short("The old hermit");
  set_long("This is an old hermit. He looks very depressed.\n");
  set_level(13);
  set_ep(100);
  set_hp(80);
  set_wc(1);
  set_al(100);
  chat=({ "Hermit says: I wish someone would kill those horrible goblins for me.\n",
	"Hermit says: I hate goblins.\n", "Hermit holds his head in his hands.\n",
	"Hermit sighs deeply.\n", "Hermit says: I wish someone would help me.\n",
	"Hermit says: If those goblins were dead I could go back home.\n",
	"Hermit looks depressed.\n", "Hermit looks beggingly at you.\n",
	"Hermit says: I'll never be able to go back to my home in the forest.\n", });
  load_chat(15,chat);
  function=({ "handle_say", 0, "handle_gives", });
  type=({ "says:", "tells you:", "gives", });
  match=({ "", " ", "", });
  set_match(this_object(), function, type, match);
}

handle_say(str) {
  string who,phrase,hero,tmp,tmp2,heroname;
  if((sscanf(str, "%s says: %s\n", who, phrase) != 2
	&& sscanf(str, "%s tells you: %s\n", who, phrase) !=2)) return;
  phrase=lower_case(phrase);
  hero=present(lower_case(who), environment(this_object()));
  if(!hero) return;
  if(phrase!="quest" && phrase!="goblin" && phrase!="goblins") {
    if(!(sscanf(phrase, "%s quest %s", tmp, tmp2))
	&& !(sscanf(phrase, "%s goblin %s", tmp, tmp2))
	&& !(sscanf(phrase, "%s goblins %s", tmp, tmp2))) return;
  }
  heroname=hero->query_real_name();
  scalps="players/moonchild/goblins/handler"->restore(heroname);
  if(scalps>19) {
    tell_room(environment(this_object()),
	"Hermit says: I've taken up enough of your time already.\n"); return; }
  if(scalps!=-1) {
    tell_room(environment(this_object()),
	"Hermit says: You promised to help me before. Have you done anything yet?\n");
    return; }
  tell_room(environment(this_object()),
	"Hermit says: Oh could you please help me. I just want you to prove to me\n"
	+ "Hermit says: that someone is trying to kill those horrible creatures.\n"
	+ "Hermit says: I will reward you well if you can kill twenty of them.\n");
  "players/moonchild/goblins/handler"->save(heroname);
  return 1;
}

handle_gives(str) {
  string who, what, tmp, heroname;
  object it, hero;
  int no;
  if(sscanf(str, "%s gives %s to Hermit.\n", who, what) == 2) {
    if(what=="corpse" || what=="remains" || sscanf(what, "corpse of %s", tmp)
	|| sscanf(what, "remains of %s", tmp)) {
      tell_room(environment(this_object()),
	"Hermit says: Ugh!\n"
	+ "Hermit screams loudly.\nHermit collapses on the floor.\n"
	+ "Hermit throws the corpse out the window.\n"
	+ "Hermit says: Sorry, but I'm terrified of corpses.\n");
      it=present("corpse",this_object());
      if(it) destruct(it);
      return;
    }
  if(what=="scalp" || what=="scalp of yellow goblin") {
    it=present("scalp of yellow goblin",this_object());
    if(!it) {
      tell_room(environment(this_object()),
	"Hermit says: Sorry, that's not what I'm looking for.\n");
      return;
    }
    if(creator(it)!="moonchild") {
      log_file("QUESTS.CHEAT", this_player()->query_real_name() + ": by" +
      file_name(it) + ": goblin_quest " + ctime(time()) + "\n");
      destruct(it);
      tell_room(environment(this_object()),
	"Hermit says: Don't try faking, I'll spot it!\n");
      return 1;
    }
    hero=present(lower_case(who), environment(this_object()));
    if(!hero) return;
    heroname=hero->query_real_name();
    no="players/moonchild/goblins/handler"->add(heroname);
    destruct(it);
// 181197: Sauron: Changed as if ppl have >20 scalps, they can't solve the quest.
    if(no >= 20) {
      tell_room(environment(this_object()),
	"Hermit says: Ah, you have convinced me that my home is safe now.\n");
      write("Hermit thanks you.\nHermit gives you 1000 coins.\n");
      hero->add_money(1000);
      hero->set_quest("goblin_quest");
      say("Hermit thanks " + capitalize(heroname) +
	"\nHermit gives 1000 coins to " + capitalize(heroname) + ".\n");
      tell_room(environment(this_object()),"Hermit waves.\n");
      move_player("east#room/void");
      destruct(this_object());
      return;
    }
      no=no*10;
      tell_room(environment(this_object()),
	"Hermit says: Thank you for killing that horrible creature.\n");
      write("Hermit gives you " + no + " coins.\n");
      hero->add_money(no);
      say("Hermit gives " + no + " coins to " + capitalize(heroname) + ".\n");
      return;
    }
    tell_room(environment(this_object()), "Hermit says: Thank you.\n");
    return;
  }
  return;
}
