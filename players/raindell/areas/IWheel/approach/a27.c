inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="The end of the river"; 
  long_desc="\nThe river ends here in a large pool of clear water, almost regal in its\n"
            "appointments. The narrow canyon walls are literally blanketed with life, and\n"
            "the air thrums with the sound of birds and insects. Even trees have taken root\n"
            "here among the rocks, their branches forming a thick canopy which shades the\n"
		"rear portion of the pool.\n\n";
	      
  dest_dir=({"/players/raindell/areas/IWheel/approach/a26","northeast",
             });

  items=({"river","It flows into the pool from the northeast", 
          "water","It's crystal clear, but seems quite deep towards the rear of the pool",
          "walls","The rock is invisible for all of the plantlife growing there",
	    "trees","Their roots in the water and rock, they grow strong and tall",
	    "branches","Spread wide over the rear of the pool, the cast a noteable amount of shade",
	    "pool","It looks quite deep, you can't even see the bottom through the clear water",
	    "plantlife","It grows on every free surface, lush and verdant",
	    "roots","They are sunk into the rock and loose in the water",
	     	});

clone_list=({1,1,"kestral","/players/raindell/areas/IWheel/approach/critters/kestral",0
              });

::reset(arg);

   replace_program("/room/room");

}
