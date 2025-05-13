inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="Downstream, at a bend in the river"; 
  long_desc="\nThe river looks clear and crisp here as it rounds the bend and flows to the\n"
            "southwest. Despite the relative quiet here, there is a strange sense of peace\n"
            "that flows through you, like nothing could possibly be wrong. The canyon walls\n"
            "are sprinkled with the living green of plants and the air is clean and cool.\n\n";
                       

  dest_dir=({"/players/raindell/areas/IWheel/approach/a25","southwest",
             "/players/raindell/areas/IWheel/approach/a23","southeast",
		});

  items=({"river","It flows calmly to the southwest", 
          "bend","The river rounds the corner here, flowing calmly to the southwest",
          "walls","Though high and rocky, they are freckled with plants",
	    "plants","They seem quite healthy, despite their rocky homes",
	   	     	});

::reset(arg);

   replace_program("/room/room");

}
