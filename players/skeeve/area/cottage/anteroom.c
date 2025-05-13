inherit "room/room";

#include "/players/skeeve/area.h"
#include "/players/skeeve/door.h"

  object key;
  int door_o, door_n, door_e, door_w;

#define ID_D_O (d=="out door")||(d=="south door")||(d=="front door")
#define NAME_D_O "front door"
#define KEY_D_O "skeleton"
#define KEY_CODE_D_O "skeeve1"
#define ROOM_O (LAND+"clearing")

query_door_o() { return door_o; }
set_door_o(i)  { door_o = i; }

long_o () {
  string s;
  s = "The front door is a heavy wooden door with a skeleton lock.\n";
  if (query_door_o()) s += "It's closed";
  else                s += "It's open";
  return s;
}

#define ID_D_N (d=="north door")||(d=="crafted door")||(d=="crafted wooden door")
#define NAME_D_N "crafted wooden door"
#define KEY_D_N "crafted"
#define KEY_CODE_D_N "skeeve2"
#define ROOM_N (COTTAGE+"sittingroom")

query_door_n() { return door_n; }
set_door_n(i)  { door_n = i; }

long_n () {
  string s;
  s = "It's a finely crafted wooden door. Even though this\n"
    + "door is only an inch thick, it is very sturdy. \n";
  if (query_door_n()) s += "It's closed";
  else                s += "It's open";
  return s;
}

#define ID_D_E (d=="east door")||(d=="simple door")||(d=="simple wooden door")
#define NAME_D_E "simple wooden door"
#define ROOM_E (COTTAGE+"kitchen")
query_door_e() { return door_e; }
set_door_e(i) { door_e = i; }

long_e () {
  string s;
  s = "It's a simple wooden door.\n"
    + "It's something written on it in druidic letters.\n";
  if (query_door_e()) s += "It's closed";
  else                s += "It's open";
  return s;
}

#define ID_D_W (d=="west door")||(d=="reinforced door")||(d=="reinforced wooden door")
#define NAME_D_W "reinforced wooden door"
#define ROOM_W (COTTAGE+"office")

query_door_w() { return door_w; }
set_door_w(i) { door_w = i; }
long_w () {
  string s;
  s = "This wooden door is reinforced with heavy sheets of steel.\n"
    + "It's something written on it in druidic letters.\n";
  if (query_door_w()) s += "It's closed.\n";
  else                s += "It's open.\n";
  return s;
}

reset(arg) {
  if (!arg) {
    set_light(1);
    short_desc = "anteroom";
    no_castle_flag = 0;
    long_desc = 
        "It's a long drafty hallway with one flight of stairs and "
       +"several passages with doors. The old wooden floorboards creak "
       +"under your weight. Your creaking footsteps echo through the "
       +"emptiness of the huge hallway.\n";
    dest_dir = ({
      LAND    + "clearing",    "out",
      COTTAGE + "sittingroom", "north",
      COTTAGE + "kitchen",     "east",
      COTTAGE + "office",      "west" 
    });
    hidden_dir = ({
      LAND    + "clearing",    "south"
    });
    items = ({
      "north", "A crafted wooden door",
      "east",  "A simple wooden door",
      "south", "The front door",
      "out",   "The front door",
      "west",  "A reinforced wooden door",
      "door",  "Which door? There are four doors (north,west,east,south)",
      "doors", "Which door? There are four doors (north,west,east,south)",
      
      "hallway", "There are several passages with doors",
      "drafty hallway", "There are several passages with doors",
      
      "passages", "On each passage is a door",
      
      "out door",   "@@long_o@@",
      "south door", "@@long_o@@",
      "front door", "@@long_o@@",

      "north door",          "@@long_n@@",
      "crafted door",        "@@long_n@@",
      "crafted wooden door", "@@long_n@@",

      "east door",          "@@long_e@@",
      "simple door",        "@@long_e@@",
      "simple wooden door", "@@long_e@@",

      "west door",              "@@long_w@@",
      "reinforced door",        "@@long_w@@",
      "reinforced wooden door", "@@long_w@@"
    });
  }
  tell_room(COTTAGE+"anteroom","A magic storm closes all the doors.\n");
  set_door_o(2);
  set_door_n(2);
  set_door_e(1);
  set_door_w(1);
  while (key = present("key")) destruct(key);
  CASTLE->add_interior("rug",this_object());
  CASTLE->add_interior("interior",this_object(),"crest");
  CASTLE->add_sphinx_obj("map",this_object());
}

init () {
   ::init();
   add_action ("read","read");
   add_action ("open","open");
   add_action ("close","close");
   add_action ("lock","lock");
   add_action ("unlock","unlock");
}

rug_burn(){
   move_object(key=clone_object(OBJECTS+"key"),this_object());
   key->set_data(KEY_D_N,KEY_CODE_D_N);
   tell_room(this_object(),"There is a key under the rug.\n");
}

read(d) {
  if (d=="door") {
    write ("which door ?\n");
    return 1;
  }
  
  if (ID_D_E) {
    write((this_player()->query_wis() > 10) ? 
      "Kitchen\n" : "You are not wise enough to read druidic!\n");
    return 1;
  }
  
  if (ID_D_W) {
    write((this_player()->query_wis() > 10) ? 
      "Office\n" : "You are not wise enough to read druidic!\n");
    return 1;
  }
  return 0;
}

open _BEGIN
  _WHICH
  
  _OPEN(ID_D_O,NAME_D_O,query_door_o,set_door_o,ROOM_O)
  _OPEN(ID_D_N,NAME_D_N,query_door_n,set_door_n,ROOM_N)
  _OPEN(ID_D_E,NAME_D_E,query_door_e,set_door_e,ROOM_E)
  _OPEN(ID_D_W,NAME_D_W,query_door_w,set_door_w,ROOM_W)
  
_END

close _BEGIN
  _WHICH  
  
  _CLOSE(ID_D_O,NAME_D_O,query_door_o,set_door_o,ROOM_O)
  _CLOSE(ID_D_N,NAME_D_N,query_door_n,set_door_n,ROOM_N)
  _CLOSE(ID_D_E,NAME_D_E,query_door_e,set_door_e,ROOM_E)
  _CLOSE(ID_D_W,NAME_D_W,query_door_W,set_door_W,ROOM_W)
  
_END

lock _BEGIN
  _WHICH  
  
  _LOCK(ID_D_O,NAME_D_O,KEY_D_O,KEY_CODE_D_O,query_door_o,set_door_o,ROOM_O)
  _LOCK(ID_D_N,NAME_D_N,KEY_D_N,KEY_CODE_D_N,query_door_n,set_door_n,ROOM_N)
  _NO_LOCK(ID_D_E,NAME_D_E)
  _NO_LOCK(ID_D_W,NAME_D_W)

_END

unlock _BEGIN
  _WHICH  
  
  _UNLOCK(ID_D_O,NAME_D_O,KEY_D_O,KEY_CODE_D_O,query_door_o,set_door_o,ROOM_O)
  _UNLOCK(ID_D_N,NAME_D_N,KEY_D_N,KEY_CODE_D_N,query_door_n,set_door_n,ROOM_N)
  _NO_LOCK(ID_D_E,NAME_D_E)
  _NO_LOCK(ID_D_W,NAME_D_W)
  
_END

check_move(obj) {
  object ob,next;
  ob = first_inventory(obj);
  while(ob) {
    next = next_inventory(ob);
    if (ob->id(KEY_D_O+" key") && (ob->query_code() ==KEY_CODE_D_O)) {
       write("The "+KEY_D_O+" key crumbles to dust.\n");
       destruct(ob);
    } else if (ob->id(KEY_D_N+" key") && (ob->query_code() ==KEY_CODE_D_N)) {
       write("The "+KEY_D_N+" key crumbles to dust.\n");
       destruct(ob);
    } else if (ob->can_put_and_get())
       check_move(ob);
    ob = next;
  }
}

_MOVE_BEGIN
  if (present("rug",this_object()) && ((dir=="east")||(dir=="west")||(dir=="north"))){
    write("As you go "+dir+ " you stumble over a bulge in the rug.\n");
    say (capitalize(this_player()->query_name())+" stumble over a bulge in the rug.\n");
  }
  
  _MOVE("south", NAME_D_O,query_door_o)
  _MOVE("out",   NAME_D_O,query_door_o)
  _MOVE("north", NAME_D_N,query_door_n)
  _MOVE("east",  NAME_D_E,query_door_e)
  _MOVE("west",  NAME_D_W,query_door_w)
  
  if ((dir=="out")||(dir=="south")) {
    write ("As you leave the cottage, a invisible ghost hunts you \n"
          +"for properties of druid Lakmir.\n");
    check_move(this_player());
  }
     
_MOVE_END

