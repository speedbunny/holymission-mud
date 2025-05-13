inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="Upstream and to the east"; 
  long_desc="\nThe river here is calm and quiet as the water flows slowly on its way.\n"
            "In fact, the silence here is almost disturbing, as if nature itself were\n"
            "frightened.  The canyon walls rise high on both sides, and to the southwest\n" 
            "one of them is alabaster white mottled with an unusual pattern of markings.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a13","southwest",
		 "/players/raindell/areas/IWheel/approach/a15","northeast",
           });

  items=({"river","It flows calmly towards the southwest", 
          "water","Pleasantly cool and clear, the water is quite enjoyable on its own",
          "walls","They tower overhead, their surfaces marked and scored by time",
	    "markings","It's too far to make anything out beyond a vague pattern of dark streaks",
         });

::reset(arg);

   replace_program("/room/room");

}

