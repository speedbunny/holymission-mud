inherit "room/room";

reset(arg) {
    int i;
    if (!present("marilith")) 
            move_object(clone_object("/players/jewel/quest/hills/marilith"),
                        this_object());
    if (!present("vrock")) 
            move_object(clone_object("/players/jewel/quest/hills/vrock"),
                        this_object());

    if (arg) return;
    set_light(0);
    short_desc="A cave with large demons";
    long_desc=
        ("This cave is filled with demons, they hate you.\n");
    items=({ 
        "cave","A cave full of demons"
          });
    dest_dir=({
        "/players/jewel/quest/hills/cave9","east",
        "/players/jewel/quest/hills/cave12","west",
        "/players/jewel/quest/hills/cave2","down"
             });
}


 

