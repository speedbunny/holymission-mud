inherit "room/room";
 
void reset(int arg) {
// Note that the items that get cloned to an object in clone_list
// have the negative id as the object. This indicates that those
// items get cloned to the monster object and not the room object.
// Also, all weapons and armour cloned to a monster in this fashion
// are automatically wielded or worn, if the monster can. Notes on
// new things: notice you can set the hps of the monster, but it
// should be reasonable based on the monster. Same goes for set_wc
// and set_ac. See the monster docs for more information. Also note
// that any efun random calls in the clone_list will take place
// before the cloning. Therefore, if you have multiple monsters
// being cloned and there is a random for an attribute setting, then
// all the cloned monsters will have that same setting, as opposed
// to all of them having a different random setting.
  clone_list = ({
    1, 1, "king", "obj/monster", ({
      "set_name", "Thrakkas, the giant king",
      "set_race", "giant",
      "set_level", 22,
      "set_alias_list", ({"king","thrakkas","Thrakkas","giant king"}),
      "set_short", "The evil Giant King",
      "set_long", "This is the evil giant king, Thrakkas, a truly "+
        "horrible opponent. You probably better run away before "+
        "he decides to slaughter your measly existence.\n",
      "set_gender", 1,
      "set_hp", 1800,
      "set_wc", 10,
      "set_ac", 10,
      "set_chance", 50,
      "set_spell_dam", 60,
      "set_spell_mess1", "The Giant King lashes out at his attacker.",
      "set_spell_mess2", "Giant king pummels you to the ground.",
      "add_money", 250+random(251),
    }),
    -1, 1, "longsword", "obj/weapon", ({
      "set_name", "longsword",
      "set_alt_name", "sword",
      "set_class", 18,
      "set_value", 2000,
      "set_weight", 3,
      "set_short", "A fine longsword",
      "set_long", "This is a very fine blade which looks like it has "+
        "seen many battles.\n",
    }),
    -1, 1, "ruby", "obj/treasure", ({
      "set_name", "ruby",
      "set_weight", 1,
      "set_value", 250+random(251),
      "set_short", "A beautiful glowing ruby",
    }),
    -1, 1, "platemail", "obj/armour", ({
      "set_name", "white platemail",
      "set_short", "White platemail",
      "set_alt_name", "platemail",
      "set_value", 500,
      "set_ac", 4,
      "set_weight", 5,
      "set_long", "This armour provides good protection against enemies.\n",
      "set_type", "armour",
    }),
  });
 
  set_light(1);
  short_desc = "The Giant King's Lair";
  long_desc =
    "This is the lair of the evil Giant King. There are trophies on "+
    "the walls and a large throne stands in the middle of the room. "+
    "You feel in awe.\n";
 
  dest_dir = ({
    "/doc/examples/exa04", "west",
    "/doc/examples/exa01", "south",
  });
 
  items = ({
    "trophies", "Lots of trophies - clearly the king has done well "+
      "for himself",
    "walls", "There's nothing really unusual about them",
    "throne", "A beautiful bejewelled throne",
  });
 
  ::reset(arg);
  replace_program("room/room");
}
