inherit "room/room";

reset(arg) 
{
    object greyooze;
    int i;

    if (!arg)
    {
       set_light(0);
       short_desc = "Crystal Cavern";
       no_castle_flag = 0;
       long_desc = "The walls here are dark and glistening with grey ooze.\n";
       dest_dir = 
           ({"players/jewel/room/hard3", "west",
             "players/jewel/room/hard2_1", "north", 
             "players/jewel/room/hard1","east"
           });
    }
    i = 0;
    if (!present("Grey Ooze")) 
    {
         while(i<3)
        {
            i += 1;
            greyooze = clone_object("obj/monster");
            call_other(greyooze, "set_name", "Grey Ooze");
            call_other(greyooze, "set_race", "ooze");
            call_other(greyooze, "set_level", 14);
            call_other(greyooze, "set_aggressive", 0);
/*            call_other(greyooze, "set_hp", 30);
            call_other(greyooze, "set_ep", 1014);*/
            call_other(greyooze, "set_al", -60);
            call_other(greyooze, "set_short", "Grey ooze");
            call_other(greyooze, "set_long", "A slimy horror that looks like wet stone and oozes along the cavern floor.\n");
/*            call_other(greyooze, "set_ac", 0);
            call_other(greyooze, "set_wc",0)*/
            move_object(greyooze, this_object());
        }
    }

}


query_light() {
    return 1;
}



