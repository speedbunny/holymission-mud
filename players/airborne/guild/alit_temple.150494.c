#define RIGHT_AL ((int)this_player()->query_alignment() > 99)
#define TPN      (string)this_player()->query_name()
#define TPRN     (string)this_player()->query_real_name()

inherit "room/room";

string last_sac;

void reset(int arg) {
  if(arg)
    return;
  set_light(1);
  short_desc="Alitist Temple";
  long_desc="This is an Alitist temple. It's well lit from a glowing in the walls,\n"
	+ "and there is a large sacrificial altar in the south wall. Perhaps you should\n"
	+ "sacrifice something on it?\n";
  dest_dir=({ "players/moonchild/guild/room", "northeast" });
  items=({ "temple", "A temple to the good barbarian God, Alit",
	"walls", "They glow with the light of good",
	"altar", "You should probably sacrifice something on it" });
}

void init() {
  ::init();
  add_action("sacrifice_something", "sacrifice");
  add_action("pray_to_god", "pray");
}

int sacrifice_something(string str) {
  object ob;
  if(!str || (!(ob=present(str, this_player()))
	&& !(ob=present(str, this_object())))) {
    notify_fail("Sacrifice what?\n");
    return 0;
  }
  if(living(ob) || transfer(ob, this_object())) {
    write("I don't think you can sacrifice that.\n");
    return 1;
  }
  write("You sacrifice the " + str + " on the altar.\n");
  say(TPN + " sacrifices " + (string)ob->short() + " on the altar.\n");
  if(!RIGHT_AL) {
    tell_room(this_object(),
	"A voice booms: You are too evil to worship me.\n");
    return 1;
    destruct(ob);
  }
  if((int)ob->query_value()>=1000) {
    tell_room(this_object(), "A voice booms: Pray to me then, " + TPN + ".\n");
    last_sac=TPRN;
  }
  destruct(ob);
  return 1;
}

int pray_to_god() {
  if((string)this_player()->query_religion()=="Alitist") {
    write("You pray to your God.\n");
    say(TPRN + " prays to " + (string)this_player()->query_possessive()
	+ " God.\n");
    if(this_player()->query_ghost())
      this_player()->remove_ghost();
    return 1;
  }
  if(!RIGHT_AL) {
    tell_room(this_object(),
	"A voice booms: You are too evil to worship me.\n");
    return 1;
  }
    write("You pray devoutly.\n");
    say(TPN + " prays devoutly.\n");
  if(last_sac==TPRN) {
    tell_room(this_object(), "The God Alit says: Welcome, new believer.\n");
    this_player()->set_religion("Alitist");
    last_sac=0;
  }
  return 1;
}
