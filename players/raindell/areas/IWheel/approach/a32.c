inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="At the gate"; 
  long_desc="\nA large wrought-iron gate can be seen here, its edges set deeply into the\n"
            "stone walls of the canyon. Beyond, you can hear the sounds of civilization\n"
            "wafting through the air, and a strange white glow is visible over the trees\n"
		"in the distance. To the north, a ruined pathway extends through the canyon\n\n";
		          	      
  dest_dir=({"/players/raindell/areas/IWheel/approach/a31","north",
		 });

  items=({"gate","The iron is quite thick, though weathered through time", 
          "walls","Solid jagged rock makes up the canyon walls",
          "edges","They are set firmly in the rock, and a weatherbeaten old sign leans to one side",
	    "glow","The white glowing auora is quite strange indeed",
	    "trees","The tops of the trees can be seen in the distance",
	    "pathway","Overgrown and ruined, the pathway extends to the north",
	    "canyon","The walls are high and narrow, extending into the distance",
	    "sign","This time-worn and battered sign appears to have something written upon it",
	     	});

::reset(arg);
}

init() {
	add_action("read","read"); 
  ::init();
}

read(str) {
	if (str=="sign") {
	    write("With effort, you can make out the word 'FELDSPAR' carved into the sign.\n");
      return 1;
      }
}





