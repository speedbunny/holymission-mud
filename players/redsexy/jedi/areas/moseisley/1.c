inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The enterance to a town in the Mos Eisley desert.";
  long_desc="A huge arch looms above you, built from white marble and spotted "+
            "with sand from the desert.  This seems to be the enterance to the "+
            "town of Mos Eisley, famous for its villains and lowlife.  The area "+
            "around here is paved with cobblestones and the town seems to continue " +
            "to the east. \n\n";

  dest_dir=({"/players/redsexy/jedi/areas/moseisley/2","east",
            "/players/redsexy/jedi/areas/desert/d72", "northwest",
           });
  
  items=({"arch","This is the archway into the town of Mos Eisley",
          "marble","The marble is white, and cold to the touch",
          "sand","Although paved in this area, the sand has splattered the archway",
          "town","The cobblestone pavings seem to indicate this is some kind of town",
          "desert","The desert lies to the west",
          "villains","Notorious villains such as Jabba the Hut live around this area",
          "lowlife","Yes, they even let people like you in here",
          "cobblestones","Uneven cobblestones pave the area",
          "area","It seems like a desert town, paved with cobblestones",
         });


clone_list=({
    1,1,"farmer","obj/monster", ({
      "set_name","farmer",
      "set_long","A sand farmer from Mos Eisley, proabably here to do some trade.\n",
      "set_race","human",
      "set_level",20,
      "set_gender",1,
      "add_money",1000,
      "set_wc",30,
      "set_ac",12,
    }),
    -1,1,"rake","obj/weapon", ({
      "set_name","rake",
      "set_short","The rake of a desert farmer",
      "set_wc",3,
      "set_value",500,
      "set_weight",1,
    }),
    2,1,"farmhand","obj/monster", ({
      "set_name","farmhand",
      "set_race", "human",
      "set_long","A young boy, who helps the farmer.\n",
      "set_level",4,
      "set_ac",1,
      "set_wc",7,
      "set_gender",1,
    }),

  });
  ::reset();
   replace_program("/room/room");

}


