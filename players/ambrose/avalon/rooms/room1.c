inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1);
 
    short_desc="A mountain path";

    long_desc="You climbing up a small windy path.  It's hard to follow as\n"
            +"it's horribly overgrown with undergrowth.  Beneath all "
             +"the plant life\n"
             +"you see what was once a paved road, now almost invisible.\n";
    
    dest_dir=({"players/ambrose/workroom","down",
               "players/ambrose/avalon/entrance/entran2","up"});

    items=({"path","A nearly invisible path",
            "road","Once mad up of many large smooth blocks of stone, but now"
          +" only rubble remains.",
            "plant life","Shrubbery gone wild",
            "undergrowth","It obscures most of the road"});
     }
