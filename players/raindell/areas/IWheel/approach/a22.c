inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="Far downstream"; 
  long_desc="\nThe river flows clear and calm to the southwest as the ground levels out\n"
            "again. Lush green plantlife lines the riverbed, adding the perfect accent of\n"
            "life to the harsh crags of rock on either side of the water. A bright chorus\n" 
            "of birdsong echoes off of the canyon walls, adding to the strange feeling of\n"
            "peace and tranquility here.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a23","southwest",
             "/players/raindell/areas/IWheel/approach/a21","northeast",
		});

  items=({"river","Levelling out, the river is about knee high and crystal clear", 
          "ground","It's that relatively flat bit under the water, though sometimes appears on its own",
          "plantlife","It grows green and strong here",
	    "riverbed","It's mostly earth and water-polished rock, with an occasional flagstone scattered here and there",
	    "crags","Nothing unusual, just high, jagged walls of rock",
	    "walls","Rocky and jagged, they are riddled with tiny holes",
	    "holes","By the look and sound, they appear to be the home of a small bird",
	    "water","It's cool, but clear enough to see through to the riverbed easily",
	    	});

clone_list=({1,1,"bluebird","/players/raindell/areas/IWheel/approach/critters/bluebird",0
              });

::reset(arg);

   replace_program("/room/room");

}

