inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1);
 
    short_desc="A mountain path";

    long_desc=
 "You are climbing up a small winding path.  Its hard to follow as it\n"
+"is horribly overgrown with a dense undergrowth.  Beneath all of the\n"
+"plant life you see what once a paved road, now almost invisible.  Up\n"
+"ahead you can see a dark opening into the mountain.\n";
    
    dest_dir=({"players/ambrose/workroom","down",
               "players/ambrose/avalon/entrance/entran2","up"});

    items=({"path","A nearly invisible path",
            "road","Once mad up of many large smooth blocks of stone, but now"
          +" only rubble remains.",
            "plant life","Shrubbery gone wild",
            "undergrowth","It obscures most of the road"});
     }
