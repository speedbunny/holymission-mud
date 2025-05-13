inherit "room/room";

#include "/players/skeeve/area.h"

reset(arg) {
  object bodyguard;
  if (!arg) {
    set_light(1);
    short_desc = "Guardroom";
    long_desc = 
        "This is a large, rectangular room. The floor is stone inlay while the walls\n"
      + "are of cracked terra cotta. In front of you, you can see a table and some\n"
      + "chairs. Some weapons are hanging on the wall. Through a passage in the south\n"
      + "side of the room you can look into the office.\n";
    dest_dir = ({
        COTTAGE+"office", "south"
      });
    items = ({
      "passage","There is no door at this passage",
      "weapon", "You see a shield, a spear, a bow and a quiver hanging on the wall",
      "weapons","You see a shield, a spear, a bow and a quiver hanging on the wall",
      "wall",   "You see a shield, a spear, a bow and a quiver hanging on it",
      "shield", "It's a black and silver shield with the symbol of the undead upon it",
      "spear",  "This is a nasty looking spear, indeed!  The nicks and dents \n"
               +"upon it show the signs of battle",
      "bow",    "An ordinary hunter's bow hangs on the wall",
      "quiver", "It's a quiver of some seven arrows",
      });
  }
  bodyguard=CASTLE->add_monster("bodyguard",this_object());
  if (environment(bodyguard)!=this_object()) 
     move_object(bodyguard,this_object());

  CASTLE->add_interior ("interior",this_object(),"guardroom table");
  CASTLE->add_interior ("interior",this_object(),"guardroom chair");
}

init() {
   ::init();
   add_action ("get","get");
}

get (str) {
  object bodyguard;
  if (!str) {write ("What will you get?"); }

  if ((str=="shield")||(str=="spear")||(str=="bow")||(str=="quiver")) {
    if (bodyguard=CASTLE->query_monster("bodyguard")) {
      if (environment(bodyguard) != this_object()) {
        move_object(bodyguard,this_object());
        tell_room(this_object(),"The bodyguard arrives.\n");
      }
      write("As you try to take a weapon from the wall, the guard cries:\n"
           +"Go away. This weapons are mine.\n");
      say("As "+this_player()->query_name()+" tries to take a weapon from the wall, the guard cries:\n"
           +"Go away. This weapons are mine.\n");
      bodyguard->attack_object(this_player());;
    } else {
      write ("You cannot get the "+ str + ".\n"
            +"It seems that they are fixed on the wall.\n");
      say (capitalize(this_player()->query_name())+" fails to take the "
        + str + "from the wall.\nIt seems that they are fixed on the wall.\n");
    }
    return 1;
  }
  return 0;
}
