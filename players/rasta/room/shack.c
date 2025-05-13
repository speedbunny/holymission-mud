inherit "room/room";

reset(arg) {
    if (arg)
	return;
dest_dir = ({ "players/rasta/room/alley","northwest"});
            
   short_desc = "Shack";

    no_castle_flag = 1;
long_desc=
"This is a one-room shack, built up over a ditch that drains the sewage\n"
+"of the neighborhood. The air is thick with the smoke of cooking fires and\n"
+"the stink of urine.\n";
    set_light(1);
}

