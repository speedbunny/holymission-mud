inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The western edge of the town square in Mos Eisley.";
  long_desc="The hut to your south has bright blue lettering on the wall reading "+
            "'The Mos Eisley Observer'.  Quite a basic hut, only built of wood and "+
            "with holes cut out in the walls instead of windows, its a wonder that "+
            "with holes cut out in the walls instead of windows, its a wonder that  "+
            "the place doesn't get broken into every night.\n\n  ";

  dest_dir=({"/players/redsexy/jedi/areas/moseisley/19","southeast",
             "/players/redsexy/jedi/areas/moseisley/18","south",
           });
  
  items=({"path","The path is now paved with redbricks, hot and slightly cracked from the sun, yet still easy to travel on",
          "square","The square is surrounded by cabins built from stone, and you stand on the eastern edge",
          "hut","This hut to the south is labelled 'The Mos Eisley Observer', it must be where they write the daily news!",
          "sun","The sun is fierce here, and the redbricks absorb a lot of the heat",
         });

  clone_list=({
    1,1,"gerrat","obj/monster", ({
      "set_name","gerrat",
      "set_long","A gerrat humanoid, weak and feeble.\n",
      "set_race","human",
      "set_level",1,
      "set_gender",1,
      "add_money",10,
      "set_wc",2,
      "set_ac",4,
    }),
    -1,1,"toothpick","obj/weapon", ({
      "set_name","toothpick",
      "set_short","A toothpick which once belonged to a little slimy gerrat",
      "set_wc",1,
      "set_value",5,
      "set_weight",1,
    }),
 });

  ::reset();
   replace_program("/room/room");

}


