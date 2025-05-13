inherit "room/room";

void reset(int arg) {
  if(arg) return;
         set_light(1);
       short_desc="The catalyst.";     
       long_desc="\
You are inside a catalyst room.  You can barely see through the rainbow \
colored light.\n\n";

  dest_dir=({"/players/redsexy/dimensions/inner/1","north",
             "/players/redsexy/dimensions/inner/2","northeast",
             "/players/redsexy/dimensions/inner/3","east",
             "/players/redsexy/dimensions/inner/4","southeast",
             "/players/redsexy/dimensions/inner/5","south",
             "/players/redsexy/dimensions/inner/6","southwest",
             "/players/redsexy/dimensions/inner/7","west",
             "/players/redsexy/dimensions/inner/8","northwest",

          });


  items=({"light","You examine the light and notice it is focused upon an incubator!",
          "catalyst","A place of change",
         });
 clone_list=({
    1,1,"incubator","/players/redsexy/dimensions/quest/incubator",0,
  });


   smell="The ripe smell of change. \n";
    
  ::reset();
  replace_program("/room/room");
}

