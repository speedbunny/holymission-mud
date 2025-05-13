inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The offices of the Mos Eisley Observer.";
  long_desc="These are the offices of Mos Eisley's only newspaper, the Mos Eisley "+
            "Observer.  Three desks sit in a line and a printing press stands in the "+
            "corner of the room, ready to churn out the news as it comes to fruition. "+
            "There are no windows in this wooden hut, just holes in the walls, and "+
            "you realise this must be to provide enough air conditioning for the press "+
            "to work correctly.\n\n";

  dest_dir=({"/players/redsexy/jedi/areas/moseisley/17","north",
           });
  
  items=({"offices","The offices of the Mos Eisley Observer",
          "desks","Oaken desks, with papers scattered on them",
          "papers","Pieces of paper scribbled on in shorthand outlining stories",
          "press","A truly magnificent piece of machinery",
          "hut","Built of wood, this hut is actually very cool to sit in",
          "windows","There are no windows",
          "holes","Holes in the wall let the vague breeze drift in and cool the area",
          "newspaper","All the newspapers seem to have gone, maybe you should come again tomorrow?",
         });

  clone_list=({
    1,2,"journalist","obj/monster", ({
      "set_name","journalist",
      "set_long","An interfering journalist snooping for a story.\n",
      "set_race","human",
      "set_level",10,
      "set_gender",1,
      "add_money",200,
      "set_wc",8,
      "set_ac",6,
    }),
    -1,1,"paper","obj/thing", ({
      "set_name","paper",
      "set_short","A useless piece of paper",
      "set_value",0,
    }),
 });

  ::reset();
   replace_program("/room/room");

}


