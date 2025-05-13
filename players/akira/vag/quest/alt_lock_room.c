inherit "room/room";

object vortex;



void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Alternate Reality";
    long_desc =
    "You have entered a another part of the 4th, but you sense\n"+
    "something wrong here.  Like something is wrong with the\n"+
    "space/time continum and like you feel that your destined to\n"+
    "to correct it.\n"+
    "\n"+
    "\n";

    dest_dir = ({
      "/players/akira/vag/quest/q_connect",
      "east",
    });


        vortex = present("vortex",environment(this_player()));
        if(!vortex)
     {
	  move_object(
            clone_object("/players/akira/vag/quest/vortex.c"),
	    this_object());
      }
}




