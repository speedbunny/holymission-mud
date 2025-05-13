inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The eastern edge of the town square in Mos Eisley.";
  long_desc="The redbrick path that runs around the square is a little cracked here "+
            "and you have to watch your step to make sure you do not fall over.  To "+
            "the north is a grand stone hut with a sign outside labelled 'The House of "+
            "Linkage'.\n\n  ";

  dest_dir=({"/players/redsexy/jedi/areas/moseisley/3","northwest",
             "/players/redsexy/jedi/areas/moseisley/4","north",
           });
  
  items=({"path","The path is now paved with redbricks, hot and slightly cracked from the sun, yet still easy to travel on",
          "square","The square is surrounded by cabins built from stone, and you stand on the eastern edge",
          "hut","This hut looks grander and more special than the others.",
          "sun","The sun is fierce here, and the redbricks absorb a lot of the heat",
         });

  clone_list=({
    1,1,"farmer","obj/monster", ({
      "set_name","farmer",
      "set_long","A sand farmer from Mos Eisley, proabably here to do some trade.\n",
      "set_race","human",
      "set_level",20,
      "set_gender",1,
      "add_money",1000,
      "set_wc",15,
      "set_ac",12,
    }),
    -1,1,"rake","obj/weapon", ({
      "set_name","rake",
      "set_short","The rake of a desert farmer, it looks as if it could be used as a weapon",
      "set_wc",3,
      "set_value",500,
      "set_weight",1,
    }),
    1,1,"farmhand","obj/monster", ({
      "set_name","farmhand",
      "set_race", "human",
      "set_long","A young boy, who helps the farmer.\n",
      "set_level",4,
      "set_ac",5,
      "set_wc",2,
      "set_gender",1,
    }),
 });

  ::reset();
   replace_program("/room/room");

}


