inherit "room/room";

string *name, *punct;
mapping users = ([ ]);
mapping wrong = ([ ]);
mapping read  = ([ ]);
mapping noticed = ([ ]);
string *name = ({
  ({ "a",   "cog", "fl", "ll",  "ss", "cc",  }),
  ({ "er",  "kw",  "pp", "z",   "aa", "da",  }),
  ({ "fol", "mm",  "sh", "abl", "de", "g'g", }),
  ({ "n'n", "th",  "ae", "dh",  "gz", "o",   }),
  ({ "thl", "ak",  "dh", "hh",  "oa", "tl",  }),
  ({ "an",  "du",  "hl", "oe",  "u",  "ao",  }),
  ({ "e",   "i",   "oo", "ul",  "ar", "ee",  }),
  ({ "ii",  "ow",  "uu", "bh",  "eo", "il",  }),
  ({ "rh",  "y",   "io", "eu",  "ir", "ph",  }),
  ({ "yy",  "ch",  "ff", "ks",  "q'", "zh",  })
});

string *punct = ({
  "'", "`", " ", "-",
});  

void reset(int arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "The magicians study";
  long_desc = "You are in what looks like a magicians study. Tall "
    + "bookcases line the walls, and ornate lamps lie suspended in "
    + "midair. A large stone fireplace dominates the northern wall"
    + "@@notice_secret_door@@.\n";
  dest_dir = ({
    "players/paris/house/inside1", "south",
  });
  items = ({
    "air", "Motes of dust dance in the light.",
    "dust", "Ooooh, no one looks as if they have cleaned in here for years.",
    "fire", "Doesn't seem to have been a fire burning in many years",
    "fireplace", "@@look_close@@",
    "bookcases", "Tall bookcases, filled with old books",
    "books", "They look quite old and a little worn",
  });
  smell = "All the dust in the air makes you want to sneeze\nAcchoooo!\n";
  ::reset(arg);
}

init() {
  ::init();
  add_action("_search", "search");
  add_action("_doMove", "move");
}

string notice_secret_door() {
  if (!random(6)) {
    noticed[this_player()->query_real_name()] = "yes";
    return ", you notice something strange about it";
  } else 
    return "";
}

string look_close() {
  if (noticed[this_player()->query_real_name()]) 
    return "One of the stones on the fireplace looks like it can move";
  return "A large stone fireplace";
}

int _search(string str) {
  if (str == "fireplace" && noticed[this_player()->query_real_name()]) {
    printf("You think you can move one of the stones in the fireplace.\n");
    say(capitalize(this_player()->query_name())
	+ " looks closely at the fireplace.\n", this_player());
    return 1;
  } else
    return 0;
}

int _doMove(string str) {
  if (str == "stone in the fireplace" || str == "stone in fireplace") {
    if (!noticed[this_player()->query_real_name()]) 
      return 0;
    printf("You push against the stone and it slowly moves, sliding"
	   + " in, as the entire fireplace quickly rotates.\n");
    say(capitalize(this_player()->query_name())
	+ " moves a stone in the fireplace, causing the entire fireplace"
	+ " to revolve around, the next time you look, they aren't there.\n",
	this_player());
    this_player()->move_player("through the fireplace#players/paris/house/tunnel1");
    return 1;
  } else
    return 0;
}


string gen_str() {
  int i;
  string s;
  
  s="";
  i=4+random(3);
  
  while(i--) {
    s += (string)name[random(10)][random(6)];
    if (!random(5))
      s += punct[random(sizeof(punct))];
  }
  return s;
}

string query_pass() {
  int i;
  string s, user;
  
  user = (string)this_player()->query_real_name();
  if (users[user]) 
    return users[user]; 
  else {
    users[user] = gen_str();
    return users[user];
  }
}

int readpaper() {
  /*
   * how many times have they tried to read the papers on the 
   * desk
   */
  return read[this_player()->query_real_name()]++;
}

int times_wrong(int arg) {
  /*
   * how many times have they got the password 
   * wrong?
   */
  write("Times wrong: "+wrong[this_player()->query_real_name()]+".\n");
  if (arg)
    return wrong[this_player()->query_real_name()]++;
  return wrong[this_player()->query_real_name()];
}
