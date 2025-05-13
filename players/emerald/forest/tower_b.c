inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);

  short_desc="Basement";
  long_desc="You are in the basement of the tower.  There are pipes " +
            "everywhere, you can hear the water running through them.  " +
            "Usually, there is a dragon here used to heat the water in " +
            "the tower.\n";

  dest_dir=({"/players/emerald/forest/tower_g", "up",
           });

  items=({"pipes", "They're covered in black ash",
          "tower","It's a big tower, and you're in the basement of it",
          "basement","The normal basement, replete with spiders, " +
                     "dust bunnies, rats, and a dragon",
        });

  clone_list=({
    1,1,"dragon","obj/monster", ({
      "set_name","dragon",
      "set level",80,
      "set_hp",3200,
      "set_long","A huge dragon.\n",
      "set_chance",10,
      "set_spell_dam",150,
      "set_spell_mess1","The dragon breathes fire!",
      "set_spell_mess2","The dragon breathes fire at you",
    }),
  });

  ::reset();
  replace_program("/room/room");

}
