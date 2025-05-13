inherit "room/room";

#include "/room/room_defs.h"

status door_is_open, door_is_locked;

void reset(int arg) {
  clone_list = ({
    1, 1, "guard", "obj/monster", ({
      "set_name", "guard",
      "set_race", "human",
      "set_short", "A guard",
      "set_long", "A big and sturdy guard.\n",
      "set_level", 11,
      "set_al", 100,
      "set_size", 3,
    }),
    -1, 1, "shortsword", "obj/weapon", ({
      "set_name", "shortsword",
      "set_class", 12,
      "set_type", 2,
      "set_weight", 3,
      "set_value", 700,
      "set_alt_name", "sword",
      "set_short", "A shortsword",
      "set_long", "It is a professional looking short sword, used by "+
        "warriors and guards.\n",
    }),
    -1, 1, "key", "obj/treasure", ({
      "set_id", "key",
      "set_name", "bank key",
      "set_short", "A bronze bank key",
      "set_value", 10,
      "set_weight", 1,
    }),
  });

  door_is_open = 0;
  door_is_locked = 1;

  ::reset(arg);
  if(arg) return;
  set_light(1);

  short_desc="The bank";

  long_desc=
    "You are in the old part of the bank. " +
    "To the east is a low counter. The counter is covered " +
    "with heavy iron bars. On the wall beside the counter, " +
    "a door leads further east.\n";

  dest_dir=({
    HM_VILLAGE + "bankroom","east",
    HM_VILLAGE + "newbroker","south",
  });

  items=({
    "counter","There is a sign in the counter that says\n"+
      "CLOSED FOR RECONSTRUCTION",
    "door","@@door_desc",
  });
}

string door_desc() {
  if(door_is_open) 
    return("The door is open");
  else
    return("The door is closed");
}

void init() {
  ::init();
  add_action("_open", "open");
  add_action("_unlock", "unlock");
}

status _open(string str) {
  if(str && str != "door")
    return 0;
  if(door_is_open)
    return 0;
  if(door_is_locked) {
    write("The door is locked.\n");
    return 1;
  }
  door_is_open = 1;
  write("Ok.\n");
  say(TP->NAME + " opened the door.\n");
  return 1;
}

status _unlock(string str) {
  if(str && str != "door")
    return 0;
  if(door_is_open || !door_is_locked)
    return 0;
  if(!present("bank key", TP)) {
    if (present("key", TP))
      write("You don't have the right key.\n");
    else
      write("You need a key.\n");
    return 1;
  }
  door_is_locked = 0;
  write("Ok.\n");
  say(TP->NAME + " unlocked the door.\n");
  return 1;
}

status move(string str) {
  if(!str)
    str = query_verb();
  if(str == "east") {
    if(!door_is_open) {
      write("The door is closed.\n");
      return 1;
    }
    if(present("guard", TO)) {
      write("The guard bars the way.\n");
      return 1;
    }
  }
  return ::move(str);
}

int query_door() {
  return !door_is_open;
}

int open_door_inside() {
    door_is_locked = 0;
    door_is_open = 1;
}
