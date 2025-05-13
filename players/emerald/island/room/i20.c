inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="It seems like this is the place where the natives gather to "+
            "hear words of wisdom from their wiseman.  Strange objects, "+
            "which could probably be classified as religious or magical "+
            "paraphernalia, are neatly stacked in an arrangement of "+
            "ostensible significance.  What that significance is, only "+
            "the wiseman knows.  You might ask him, next time you see him.\n";

  items=({"place","Yes, this is a place.  A holy place, most likely",
          "natives","The monkey furs and drums bely the natives usage of "+
                    "this place",
          "objects","Shrunken heads, skulls, macabre rattles, occult "+
                    "crystals, dragon's teeth, the usual stuff",
          "paraphernalia","Nifty things like stonefish fangs and stingray "+
                          "spines for sacrificing victims to the volcano",
          "arrangement","It's amazing how you can balance stuff so well "+
                        "on top of an ordinary human skull",
          "significance","It probably means something to them, do don't "+
                         "wreck it",
        });
  dest_dir=({"/players/emerald/island/room/i25", "southeast",
           });

  clone_list=({
    1,1,"wiseman","obj/monster",({
      "set_name","wiseman",
      "set_short","The wiseman",
      "set_long","The wiseman of the natives is ferocious to behold.  An "+
                 "old, scrawny man dressed in a loin cloth, a necklace of "+
                 "copper dragon scales, and carrying a staff with a "+
                 "shrunken head attached to it, this guy probably knows "+
                 "some pretty potent spells.  And he looks a bit perturbed.\n",
      "set_gender",1,
      "set_level",26,
      "set_spell_dam",55,
      "set_chance",25,
      "set_spell_mess1","The wiseman casts a foul curse upon his victim!\n",
      "set_spell_mess2","A curse is cast upon you!\n",
      "set_aggressive",1,
      "set_wc",20,
      "set_ac",14,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
