inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="A bend in the river"; 
  long_desc="\nThe river takes a wide turning here, sweeping around a large\n"
            "slide of tumbled stone. Over the sounds of the river you can now\n"
            "hear something new, a faint roaring in the distance.  From here\n" 
            "though, you can't see what's making the noise.  There are fewer\n"
            "plants here and the water is quite cold.\n\n";
           
  dest_dir=({"/players/raindell/areas/IWheel/approach/a6","southwest",
		 "/players/raindell/areas/IWheel/approach/a4","southeast",      
           });

  items=({"river","The turning here chops the water a bit, but it settles as it flows to the southeast", 
          "slide","A great mass of broken stone, apparently severed from high on the cliff face long ago",
          "stone","It's a layered sort of black stone, and has shattered into large slabs",
	    "plants","The waterplants are fewer in number here"
	    "face","Looking closely, you can tell where the fallen stone was originally"                  
         });

clone_list=({1,1,"swallow","/players/raindell/areas/IWheel/approach/critters/swallow",0
              });

::reset(arg);

   replace_program("/room/room");

}

