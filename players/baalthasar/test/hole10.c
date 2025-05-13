inherit "room/room";
object sword, lich;
string name;

reset(arg) {
  if(!lich) {
  lich=clone_object("obj/monster");
  call_other(lich, "set_name", "evil lich");
  call_other(lich, "set_alias", "lich");
  call_other(lich, "set_short", "Evil lich");
  call_other(lich, "set_long", "This is the evil lich, which was imprisoned\n"+
                               "in this hole centuries ago by the high priest.\n"+
                               "It is said that noone who sees this evil creature\n"+
                               "lives to tell about it.\n\n");
  call_other(lich, "set_level", 50);
  call_other(lich, "set_ac", 10);
  call_other(lich, "set_wc", 25);
  call_other(lich, "set_al", -1000);
   call_other(lich, "set_hp", 1900);
  call_other(lich, "set_aggressive", 1);
  call_other(lich, "set_chance", 40);
  call_other(lich, "set_spell_damage", 150);
  call_other(lich, "set_spell_mess1", "The lich slices his opponant with ease.");
  call_other(lich, "set_spell_mess2", "The lich slices you like butter!!!");
  call_other(lich, "set_spell_mess2", "The lich slices through your flesh like butter..\n");
  transfer(lich, this_object());
  sword=clone_object("obj/weapon");
  call_other(sword, "set_name", "sword of the lich");
  call_other(sword, "set_alias", "sword");
  call_other(sword, "set_short", "Sword of the Lich");
  call_other(sword, "set_long", "This is the Sword of the Lich, which has\n"+
                                "been used by the evil lichs for ages to\n"+
                                "kill all good beings.\n\n");
  call_other(sword, "set_class", 19);
  call_other(sword, "set_weight", 4);
  call_other(sword, "set_value", 2500);
  transfer(sword, lich);
  lich->init_command("wield sword");
  }
  if(arg) return;
  short_desc = "Dead end of passage";
  long_desc = "You have come to the dead end of the passage. \n"+
              "There is blood covering the entire floor and \n"+
              "most of the walls.\n";
  set_light(-1);
  items = ({"blood", "This appears to be the blood of unfortunate\n"+
                   "adventurers who wandered into the room with \n"+
                   "the evil lich. The blood seems to have poared \n"+
                   "through a hole in the corner",
          "dead end", "This is the end of the passage..",
          "passage", "This is one of the passages that lead through the hole",
           "hole", "This a deep, dark hole, which emits much evil..",
           "corner", "This is an ordinary corner of a room, but there is a hole in it",
          "floor", "You cannot see the floor, because there is much blood over it",
          "hole", "There is a hole in the corner of the room. Maybe\n"+
                  "you can fit through it", });
  dest_dir = ({"players/alian/hole9", "south", });
}

init() {
::init();
add_action("search"); add_verb("search");
add_action("enter"); add_verb("enter");
}

search() {
  write("You find a hole in the corner!\n");
  return 1;
}

enter(str) {
  name==this_player();
  if(str !="hole") return;
  if(present("lich")) {
      write("Lich steps in front of the hole!\n");
      return 1;
      }
  write("You squeeze through the hole...\n");
  say(name + " squeezes through a hole in the corner.\n");
  call_other(this_player(), "move_player", "enter hole#players/alian/hole16");
  return 1;
}
