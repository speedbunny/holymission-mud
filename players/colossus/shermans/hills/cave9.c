#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(0);
    short_desc="A cave with medium demons";
    long_desc=
    ("This cave is filled with demons, they hate you.\n");
    items=({ 
      "cave","A cave full of demons"
    });
    dest_dir=({
      "/players/sherman/hills/cave10","west",
      "/players/sherman/hills/cave8","up"
    });
    clone_list = ({1,4,"medium demon","/players/sherman/hills/demonm",0});
    ::reset();
    replace_program("room/room");
}
