inherit "/room/room";

reset(arg) {

  if(arg) return;

  set_light(1);

  short_desc="Entrance to a wonderful garden";
  long_desc="You are at the entrance to a wonderful garden.  You can smell " +
            "the sweet fragrances of a hundred different flowers in " +
            "the air.  Around you, the many different animals can be heard "+
            "rustling among the plants.  In the distance you hear the song "+
            "of a nightingale.  You feel like you could stay here " +
            "forever.  A huge golden hedge blocks your way north and " +
            "east.  There are many footprints in the dirt, it looks like " +
            "the towns citizens come here alot.  There is a sign here, " +
            "perhaps you should look at it!!!\n";

  dest_dir=({"/players/emerald/garden/gar_cor1","west",
             "/players/kelly/rooms/violens", "south",
           });

  items=({"sign","You could read the sign",
          "hedge", "The hedge acts as a fence to keep out the wild animals",
          "garden","It is in full bloom",
          "footprints","They are in all different sizes",
          "plants","They are exceptionally healthy",
        });

  clone_list=({
    1,1,"gardener","/players/emerald/garden/gardener",0,
    -1,1,"apron","obj/armour", ({
      "set_name","apron",
      "set_short","A gardener apron",
      "set_long","This apron is worn by the gardener in the royal garden.\n",
      "set_value",700,
      "set_weight",1,
      "set_ac",4,
    }),
    -1,1,"hat","obj/armour", ({
      "set_name","hat",
      "set_short","The gardener's hat",
      "set_type","helmet",
      "set_long","This hat is worn by the gardener in the royal garden.\n",
      "set_value",300,
      "set_weight",1,
      "set_ac",2,
    }),
    -1,1,"rake","obj/weapon", ({
      "set_name","rake",
      "set_class",15,
      "set_short","A gardening rake",
      "set_long","This rake is used by the gardener in the royal garden.\n",
      "set_value",1500,
      "set_weight",2,
    }),
  });

  ::reset();
}

void init() {
  ::init();
  add_action("exit_garden", "exit");
  add_action("_read","read");
}
exit_garden() {
  object shears;
  shears = present("shears", this_player());
  if(shears) {
    destruct(shears);
    write("\nThe shears can only be used in the royal garden.\n"
          "So they go back to the gardener !!!\n\n");
  return 1;
  }
}
_read(str) {
  if(!str) {
    notify_fail("Read what?\n");
    return 0;
  }

  if(str=="sign") {
    write("This is the royal garden.\n"+
          "Here NEWBIES can look around for some experience and other\n"+
          "useful things.  But please do not kill the nightingale, she is\n"+
          "the only good monster in here.\n\n"+
          "HINT: Ask the gardener for a weapon.  Maybe he has something \n"+
          "for you!\n");
    say(this_player()->query_name()+" reads the sign.\n");
    return 1;
  }
}
