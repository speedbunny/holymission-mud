inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="In the green canyon"; 
  long_desc="\nThis far downstream the air practically sings with the sounds of life,\n"
            "and the river itself is clear and refreshingly brisk. The canyon walls,\n"
            "while narrowing here, are nearly covered with with plants and vines of\n"
            "many varieties. The water continues to flow towards the southwest, into\n"
		"a vibrant green aura\n\n";
	      
  dest_dir=({"/players/raindell/areas/IWheel/approach/a27","southwest",
             "/players/raindell/areas/IWheel/approach/a25","northeast",
		});

  items=({"river","It flows calmly to the southwest", 
          "walls","You can hardly even see them for all the plants",
          "plants","Green and healthy, they cover nearly everything",
	    "vines","They cling to the walls, climbing upwards",
	    "water","It's crystal clear",
	    "aura","It's hard to make anything out through it",
	     	});

clone_list=({1,1,"trout","/players/raindell/areas/IWheel/approach/critters/trout",0
              });

::reset(arg);

   replace_program("/room/room");

}
