// 011092: Torches added (but no long desc - due to std.h)
// 030294: Airborne: Added no_sneak to the properties
// Ethereal Cashimor: "has_fire" property from torches...
// 020794: Airborne: Added exit to the mentor boards
// 140394: Uglymouth: debugged up and south exits.
// 160195: Mangla reformatting and making funcitons static
// 140396: Sauron: Added stuff to banish (on Mangla's request).

#include <tune.h>
#include <sys_sheriffs.h>
#include <lw.h>

#define GUILD	0	// adventurers guild
#define GM	"/guild/master"
#define TP	this_player()

static variables inherit "/guild/guild_room";

string banished_by, reason, time;
int level;
static object quest, quest2, board;

void make_quest() {
  if(!quest) {
    quest = clone_object("/obj/quest_obj");
    quest->set_name("orc_slayer");
    quest->set_weight(1);
    quest->set_killing(3);
    quest->set_short_hint("Get the Orc slayer");
  quest->set_hint("Find and retrieve the mighty orc slayer Orcrist from the\n\
evil Orc Shaman. The Shaman is rumored to have a temple somewhere \n\
southwest of the village in a deep, dark forest. Return Orcrist to Leo \n\
so that it might once again protect the village from raiding orcs.\n");
    quest->add_quest();
  }

  if(!quest2) {
    quest2 = clone_object("/obj/quest_obj");
    quest2->set_name("ask_god");
    quest2->set_compulsory(1);
    quest2->set_weight(0);
    quest2->set_killing(0);
    quest2->set_short_hint("Seek permission to wiz");
    quest2->set_hint("Start asking an archwizard for permission to become \
an immortal.\n");
    quest2->add_quest();
  }

  return;
}

int _banish(string str) {
  string whom;
  object pl;

  if(!TP || !interactive(TP))
    return 0;
  if(!TP->query_wizard())
    return 0;
  if(!str || sscanf(str, "%s %s", whom, reason)!=2) {
    write("Syntax: banish <whom> <reason>\n");
    return 1;
  }
  if(file_size("/banish/"+whom+".o") > 0 ||
     file_size("/banish2/"+whom+".o") > 0) {
    write("That name is already banished.\n");
    return 1;
  }
  if(restore_object("/p/"+whom[0..0]+"/"+whom)) {
    if(member_array((string)TP->query_real_name(), SHERIFFS) == -1
       && !TP->query_archwiz()) {
      write("That name is already used.\n");
      return 1;   
    }
    else if(level >= (int)TP->query_level()) {
      write("You can't banish someone who's level is higher than your own.\n");
      return 1;
    }
  }
  banished_by = capitalize(this_player()->query_real_name());
  time = ctime();
  save_object("/banish2/"+whom);
  if(pl = find_player(whom) && pl != TP) {
    tell_object(pl, sprintf("You were just banished by %s, the reason \
being: %s\n", banished_by, reason));
    pl->save_me();
    destruct(pl);
  }
  printf("%s has been banished in '/banish2/'\n", whom);
  return 1;
}

int listBoards() {
    return (int)"/tools/bboots"->newNotes();
}

int move(string str) {
  if(!str)
    str = query_verb();
  if(str == "south" && !this_player()->query_immortal()) {
    write("A strong magic force stops you.\n");
    say(sprintf("%s tries to go through the field, but fails.\n",
                this_player()->query_name()));
    return 1;
  }
  if(str == "up" && !this_player()->query_archwiz()) {
    write("You can't go up there - you're not an archwizard!!!!\n");
    return 1;
  }
  return ::move(str);
}  

int try_attack(object ob) {
  return (int)"/room/church"->try_attack(ob);
}

int light_text(string str) {
  printf("You light your %s with the torches on the wall.\n",str);
  say(sprintf("%s uses the torches on the wall to light a %s.\n",
              this_player()->query_name(),str));
  return 1;
}

void reset(int arg) {
  object ob;

  if(!arg) { 
    set_light(1);
    set_guild(GUILD);

    short_desc = "The adventurers guild";
    long_desc = "\
You have to come here when you want to advance your level. You can also \
buy points for a new level. There is an opening to the south, and some \
shimmering blue light in the doorway. Below you, you can see the entrance \
to the players' flame room. To the southwest is the players bug room. In \
the corner you notice a translucent staircase leading up to the Guild \
of the Archwizards. There are a few burning torches attached to the wall, \
giving this guild a dark and smoky appearance.\n\
Commands: cost, list, list [number], list all and advance.\n";

    dest_dir = ({
      "/room/vill_road1b",   "north",
      "/room/player/mudads", "east",
      "/room/wiz/mentor",    "southeast",
      "/room/player/bug",    "southwest",
      "/room/arch/general",  "up",
      "/room/player/flame",  "down",
    });

    hidden_dir = ({
      "/room/wiz/general","south",
    });

    items = ({
      "stair",     "It is translucent",
      "staircase", "It is translucent",
      "torch",     "It is fixed to the wall",
      "torches",   "They are fixed to the wall",
    });

    property = ({
        "no_fight",
        "no_sneak",
        "no_steal",
        "has_fire"
    });

    clone_list = ({
      1, 1, "board", "/boards/guilds/adv_guild", 0,
      2, 1, "book",  "/obj/book", 0,
    });
  }
  ::reset(arg);
}

void init() {
    ::init();
    add_action("_banish","banish");
    add_action("listBoards", "newnotes");
    add_action("listBoards", "nn");
}
