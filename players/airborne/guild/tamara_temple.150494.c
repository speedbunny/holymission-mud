#define RIGHT_AL ((int)this_player()->query_alignment() < -99)
#define TPN      (string)this_player()->query_name()
#define TPRN     (string)this_player()->query_real_name()

inherit "room/room";

string last_sac;

void reset(int arg) {
  if(arg)
    return;
  set_light(1);
  short_desc="Tamaran Temple";
  long_desc="This is an Tamaran temple. It's dimly lit and the walls are black as night.\n"
	+ "and there is a large sacrificial altar in the south wall. Perhaps you should\n"
	+ "sacrifice something on it?\n";
  dest_dir=({ "players/moonchild/guild/room", "northwest" });
  items=({ "temple", "A temple to the evil barbarian Goddess, Tamara",
	"walls", "They are very black indeed, and stink of evil",
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
	"A voice booms: You are too good to worship me.\n");
    destruct(ob);
    return 1;
  }
  if((int)ob->query_value()>=1000) {
    tell_room(this_object(), "A voice booms: Pray to me then, " + TPN + ".\n");
    last_sac=TPRN;
  }
  destruct(ob);
  return 1;
}

int pray_to_god() {
  if((string)this_player()->query_religion()=="Tamaran") {
    write("You pray to your Goddess.\n");
    say(TPRN + " prays to " + (string)this_player()->query_possessive()
	+ " Goddess.\n");
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
    tell_room(this_object(),
	"The Goddess Tamara says: Welcome, new believer.\n");
    this_player()->set_religion("Tamaran");
    last_sac=0;
  }
  return 1;
}
