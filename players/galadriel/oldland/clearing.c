#include "/players/skeeve/area.h";
#include "/players/skeeve/door.h";

#define DN "front door"
#define ID_D (d=="door")||(d==DN)
#define ROOM_ (COTTAGE+"anteroom")
#define DOOR_ ROOM_->query_door_o
#define DOOR_SET ROOM_->set_door_o
#define KEY_TYPE "skeleton"
#define KEY_CODE "skeeve1"

inherit "room/room";

object skeleton;
status skull, made_skeleton;         /* 1 = open,made; 0= closed, not made  */

reset(arg) {
  if (!arg) {
    set_light(1);
    short_desc = "Clearing";
    no_castle_flag = 0;
    long_desc = 
        "You are standing on a clearing at the center of a forest.\n"
      + "In the middle of the clearing is a small cottage.\n"
      + "In the front of the cottage is a wooden door.\n"
      + "Above the door is a skull.\n";
   dest_dir = ({
        LAND +"forest6", "north",
        LAND +"path2", "east",
        LAND +"forest5", "south",
        LAND +"forest9", "west"
      });
    hidden_dir = ({
        COTTAGE +"anteroom","cot",
        COTTAGE +"anteroom","cottage"
      });
   items = ({
     "cottage", "Its a small wooden cottage with a door in its front",
     "skull",   "It's the skull of some creature. Whatever it is,\n"
               + "its meaning is quite clear: Death lurks inside",
     "north",   "North from the clearing begins the forest",
     "south",   "North from the clearing begins the forest",
     "west",    "West from the clearing begins the forest",
     "east",    "East from the cottage begins the path to the gate",
     "forest",  "Its a really living forest",
     "door",    "@@long_d@@",
     DN,        "@@long_d@@"
   });
  }
  skull = 0;
  made_skeleton=0;
  if (skeleton) destruct (skeleton);
}

enter (str) {
  if ( (str == "cottage") || (str == "cot") ) return move (str);
}

long_d() {
  return ROOM_->long_o();
}

init() {
    ::init();
    add_action("enter","enter");
    add_action("open", "open");
    add_action("close", "close");
    add_action("lock", "lock");
    add_action("unlock", "unlock");
}

open _BEGIN
  if (d == "skull") {
    if (skull) {
      write ("The skull is already open.\n");
    } else {
      write ("As if by magic, the skull opens.\n");
      say(this_player()->query_name() + " opens the skull.\n");
      skull = 1;
      create_skeleton();
    }
    return 1;
  }  
  _OPEN(ID_D,DN,DOOR_,DOOR_SET,ROOM_)  
_END

close _BEGIN
  if (d == "skull") {
    if (skull) {
      write ("The skull is now closed.\n");
      say(this_player()->query_name() + "closes the skull.\n");
      skull = 0;
    } else
      write ("The skull is already closed.\n");
    return 1;
  }
  _CLOSE(ID_D,DN,DOOR_,DOOR_SET,ROOM_)
_END

lock _BEGIN
  _LOCK(ID_D,DN,KEY_TYPE,KEY_CODE,DOOR_,DOOR_SET,ROOM_)
_END

unlock _BEGIN
  _UNLOCK(ID_D,DN,KEY_TYPE,KEY_CODE,DOOR_,DOOR_SET,ROOM_)
_END


create_skeleton() {
  object armour,hammer,key;
  if (!skeleton && !made_skeleton) {
    made_skeleton=1;
    skeleton = clone_object("obj/monster");
    skeleton->set_name("skeleton");
    skeleton->set_alias("warrior");
    skeleton->set_short("A skeleton Warrior");
    skeleton->set_long("Long time ago the Skeleton Warrior was a notorious killer.\n");
    skeleton->set_race("Skeleton");
    skeleton->set_level(12);
    skeleton->set_size(3);
    skeleton->set_al(200);
    skeleton->set_hp(500);
    skeleton->set_sp(300);
    skeleton->set_wc(3);
    skeleton->set_ac(2);
    skeleton->set_random_pick(1);
    skeleton->set_aggressive(1);
    skeleton->set_wimpy(-1); 
    skeleton->set_no_steal();
  
    move_object(skeleton,this_object());

    transfer(armour=clone_object("obj/armour"),skeleton);
    armour->set_name("chainmail");
    armour->set_alias("mail");
    armour->set_type("armour");
    armour->set_ac(4);
    armour->set_short("Chainmail");
    armour->set_long("Is a heavy, expensive full body armour.\n");
    armour->set_value(800);
    armour->set_size(3);
    armour->set_weight(3);
    
    transfer(clone_object(WEAPONS+"skeleton_hammer"),skeleton);

    /* Skeleton Key */
    key = clone_object(OBJECTS+"key");
    key->set_data(KEY_TYPE,KEY_CODE);
    transfer (key,skeleton);
    
    command("wear chainmail",skeleton);
    command("wield hammer",skeleton);

    say ("A skeleton jumps out of the skull.\n");
    write ("A skeleton jumps out of the skull.\n");
} }

_MOVE_BEGIN
  _MOVE("cot",DN,DOOR_)  
  _MOVE("cottage",DN,DOOR_)  
  if ((this_player()->query_stay_garden()) && (dir=="cottage"))
    return 1;
_MOVE_END
