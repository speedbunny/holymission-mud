#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(0);
    short_desc="A cave with large demons";
    long_desc=
    ("This cave is filled with demons, they hate you.\n");
    items=({ 
      "cave","A cave full of demons"
    });
    dest_dir=({
      "/players/sherman/hills/cave9","east",
      "/players/sherman/hills/cave12","west",
      "/players/sherman/hills/cave2","down"
    });
    clone_list = ({1,2,"large demon","/players/sherman/hills/demonb",0});
    ::reset();
    replace_program("room/room");
}
