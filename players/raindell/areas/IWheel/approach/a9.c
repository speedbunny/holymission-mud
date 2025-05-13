inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="Heading downstream"; 
  long_desc="\nThe river here flows smooth and gentle as it heads downstream. The\n"
            "water continues to hug your knees, but even the slight downhill sloping\n"
            "of the riverbed makes little difference to your progress. The occasional\n" 
            "cry of a bird breaks the natural silence, but only for moments. Nature is\n"
            "the ruler here, and none of the inhabitants dispute the fact.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a3","northwest",
		 "/players/raindell/areas/IWheel/approach/a10","southeast",      
           });

  items=({"river","The water is clear and gentle, flowing smoothly to the southeast", 
          "water","It's cool and crystal-clear",
          "riverbed","It slopes very gently here, made of earth and the occasional scattered flagstone",
	    "flagstone","Smooth-polished by the passage of time, they are scattered over the riverbed",
         });

clone_list=({1,1,"trout","/players/raindell/areas/IWheel/approach/critters/trout",0
              });

::reset(arg);

   replace_program("/room/room");

}

