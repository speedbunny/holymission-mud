inherit "room/room";

object lions, pear;
int pears, found;

reset(arg) {
    pears = 3;
    found = 0;
  if(!arg) {
    set_light(1);
    no_castle_flag = 1;
    short_desc = "Small Oasis on the Plains";
    long_desc =
"A line of hills rises to the west, while the open grasslands\n"+
"stretch as far as the eye can see in all other directions.\n"+
"A small cactus grows in the hot sunshine next to a small\n"+
"pool of water. The grass here looks different.\n";
    dest_dir = ({
"players/ted/quest1/plains6_1", "north",
"players/ted/quest1/plains8_1", "south",
"players/ted/quest1/hills7_9", "west",
"players/ted/quest1/plains7_2", "east"
    });
    items = ({
"hills","The hills start out low, but grow higher farther\n"+
        "to the west",
"pool","A shallow puddle, all muddy from animals drinking from it",
"water","A shallow puddle, all muddy from animals drinking from it"
    });
  }
  if(!present("female lion")) {
    move_object(clone_object("players/ted/monsters/female_lion"),this_object());
    move_object(clone_object("players/ted/monsters/female_lion"),this_object());
    move_object(clone_object("players/ted/monsters/male_lion"),this_object());
  }
}

id(str) {
  if(::id(str)) return 1;
  if(found && (str == "tuft" || str == "grass"))
    return 1;
  if(str == "cactus")
    return 1;
  return 0;
}

init() {
  ::init();
  add_action("search"); add_verb("search");
  add_action("do_pear"); add_verb("pick");
  add_action("down"); add_verb("down");
}

long(str) {
  ::long(str);
  if(found && !str)
    write("There is an overturned tuft of grass here.\n");
  if(found && (str == "tuft" || str == "grass")) {
    write("The grass and dirt has been moved, revealing a hole\n");
    write("leading down into the ground.\n");
  }
  if(str == "cactus") {
    write("The cactus has "+pears+" prickly pears growing on it.\n");
    write("It looks like you could pick one of them and eat it.\n");
  }
}

search(str) {
  say(capitalize(this_player()->query_name())+" searches.\n");
  if(!found) {
    write("You manage to overturn a lump of grass and dirt revealing\n");
    write("a hole leading down into the ground.\n");
    found = 1;
  } else
    write("You find nothing new.\n");
  return 1;
}

down() {
  if(found) {
    if(this_player()->query_size() == "large" ||
       this_player()->query_size() == "medium") {
      write("You are much to large to fit in the hole. Only someone\n");
      write("who was small could fit in such a hole.\n");
      return 1;
    }
    write("You descend into the dark hole.\n");
    this_player()->move_player("down into the hole#players/ted/quest1/hole");
    return 1;
  }
}

do_pear(str) {
  if(str == "pear" || str == "prickly pear" || str == "prickly pears") {
    if(pears == 0) {
      write("There are no more prickly pears on the cactus.\n");
      return 1;
    }
    if(random(20) > this_player()->query_dex()) {
      write("You prick you finger on the thorns!\n");
      this_player()->hit_player(5);
      write("However, you still manage to knock a prickly pear onto the ground.\n");
    } else
      print("You avoid the cactus thorns and manage to knock a prickly pear onto the ground.\n");
    move_object(clone_object("players/ted/items/prickly_pear"),
                environment(this_player()));
    pears -= 1;
    return 1;
  }
}
