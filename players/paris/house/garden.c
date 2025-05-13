#define _tellroom(str) \
  tell_room(this_object(), "The gargoyle says: "+str+"\n");
#define SAY_CHANCE 2
#pragma strict_types

inherit "room/room";

/*
 * what does the door knocker say?
 * (Hint: he has a big iron ring in his mouth ;-)
 */
string *gsays = ({
  "Oi! Whappffh Youf Doinph?",
  "Ey wouldnpff phry pho geph im 'ere.",
  "Da gufph'nor, dompffh liphf peefphle breapfhin in.",
});
static int chalk;

void reset(int arg) {
  ::reset(arg);
  if (arg)
    return;
  set_light(1);
  short_desc = "A garden";
  long_desc = "You are in a small, tidy garden. All around you lie flower "
    + "beds containing a wide variety of flowers and rare herbs from the "
    + "furthest reaches. A large white path leads west is a large studded, oak door; a "
    + "sturdy drainpipe leads up the wall to the roof.\n"
    + "A large sign sits in the before the door.\n";
  dest_dir = ({ 
    "players/paris/workroom", "east"
  });
  chalk = random(3);
  items = ({
    "door", 
    "A heavy oak door, held in place with large steel bands. An ornate "
    + "door knocker is its only decoration, perhaps you can knock on it.",
    "flowers", "Some flowers in bloom",
    "herbs", "Wild herbs, some are quite rare",
    "beds", "Some pretty flowers and herbs, they all look a little unkempt",
    "knocker", "A small metallic gargoyle holding a ring in its mouth\n"
    + "It winks at you",
    "flower beds", "Some pretty flowers and herbs, they all look a little "
    + "unkempt",
    "door knocker" ,"A small metallic gargoyle holding a ring in its mouth\n"
    + "It winks at you",
    "gargoyle", "A small gargoyle on the door, he has a large ring held in "
    + "his mouth. \n"
    + " which is probably why he speaks with a lisp.\nHe winks back at you",
    "drainpipe", "An iron drainpipe, perhaps you could scale it",
    "pipe", "A solid looking pipe, you might be able to climb it",
    "path", "It's made of chalk, you might want to look closer at the garden",
    "garden", "A pretty, if overgrown, garden" + 
    ((chalk) ? ". Some pieces of chalk line the path" : ""),
    "sign", "A large sign, you might want to try reading it",
    "chalk", "@@check_chalk@@",
  });
  smell = "The delightful scent of flowers and wild herbs.";
  enable_commands();
  call_out("gsay", random(10)+5, 0);
}

void init() {
  ::init();
  add_action("_pick", "pick");
  add_action("_pick", "pry");
  add_action("_open", "open");
  add_action("_goClimb", "climb");
  add_action("_goClimb", "scale");
  add_action("_goKnock", "knock");
  add_action("_read", "read");
  add_action("_goTake", "take");
}
string check_chalk() {
  string str;
  if (chalk) {
    str = "There are "+chalk;
    if (chalk == 1) 
      str += " piece ";
    else 
      str += " pieces ";
    str += "of chalk";
    return str;
  }
  return "Doesn't seem to be any for you to take"
}

int _goTake(string str) {
  object ob;
  
  if (str == "chalk" || str == "piece of chalk") {
    if (!chalk) {
      printf("There isn't any pieces of chalk to take.\n");
    } else {
      ob = clone_object("players/paris/house/chalk");
      if (transfer(ob, this_player())) {
	destruct(ob);
	printf("You are carrying too much.\n");
	return 1;
      }
      chalk--;
      say(this_player()->query_name()
	  + " takes a piece of chalk.\n", this_player());
      printf("You take a piece of chalk.\n");
    }
    return 1;
  }
  return 0;
}

int _read(string str) {
  if (str == "sign" || str == "the sign") {
    printf("The sign reads:\n\nPrivate Property, do not trespass.\n"
	   + "Offenders will be punished.\n\n"
	   + "                   Tensor.\n");
    say(capitalize((string)this_player()->query_name())
	+ " reads the sign.",this_player());
    return 1;
  }
  return 0;
}

int _open(string str) {
  if (str == "door" || str == "iron door") {
    write("You try to open the door, but it's locked!\n");
    say(capitalize((string)this_player()->query_name())
	+ " tries to open the door and fails.\n", this_player());
    _tellroom("OIFFPHH!! Whafph youfh doin?");
    return 1;
  }
  return 0;
}

void catch_tell(string str) {
  string p, s;
  
  if(sscanf(str, "%s says: the password is %s\n", p, s) != 2)
    return;
  call_out("query_correct_pass", 2, s);
}

void query_correct_pass(string str) {
  if ("players/paris/house/study"->times_wrong() <= SAY_CHANCE) 
    if (str == (string)"players/paris/house/study"->query_pass()) {
      _tellroom("Sounfpph good to mephf.");
      printf("The door opens far enough for you to slip through, before closing"+
	     " behind you.\n");
      this_player()->move_player("through the door#players/paris/house/inside1");
    } else {
      "players/paris/house/study"->times_wrong(1);
      _tellroom("Fphtoph tryin' phto yanhkf my chain");
    }
  else 
    _tellroom("Youfpph alread' triefffph to pffhaay da paphfword, Gaaa Awayy!");
}

void gsay(int i) {
  _tellroom(gsays[i]);
  if (i < sizeof(gsays))
    call_out("gsay", random(10)+25, i+1);
  return;
}

int _pick(string str) {
  /*
   * doesnt do anything yet, but it gives us something to add later
   */
  string verb, o, o2;
  
  verb=query_verb();
  if (sscanf(str, "%s with %s", o, o2) != 2) {
    return 0;
  }
  if (o != "door") {
    printf("Can't find a %s here.\n", o);
    return 1;
  }
  if (o2 == "bar" && present(o2, this_player())) {
    printf("you try to %s the %s with your %s.\n", verb, o, o2);
    say(capitalize((string)this_player()->query_name())
	+ " tries to "+verb+" the "+o+" with their "+o2+".\n");
  }  else
    printf("You don't have a %s.\n", o2);
  return 1;
} 

int _goClimb(string str) {
  string verb;

  verb=query_verb();
  if (str == "pipe" || str == "drainpipe") {
    if ((int)this_player()->query_size() > 3) {
      printf("You try to %s the %s but it doesn't look like it"
	     + " will support your weight.\n", verb, str);
      say(capitalize((string)this_player()->query_name())
	  + " looks appreciatively at the "+str+" but thinks "
	  + "better of it.\n", this_player());
    } else {
      printf("You slowly %s the %s.\n", verb, str);
      this_player()->move_player("up the drainpipe#players/paris/house/updrain");
    }
    return 1;
  } else
    return 0;
}

int _goKnock(string str) {
  /*
   * Dont know what to do with this yet, but we can 
   * prolly do something ...
   */
  if (str == "on door" || str == "on the door") {
    printf("You take the ring firmly in your hand and knock on the door.\n");
    say(capitalize((string)this_player()->query_name())
	+ " knocks on the door.\n", this_player());
    return 1; 
  } else
    return 0;
}









