#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(0);
    short_desc="A cave with small demons";
    long_desc=
    ("This cave is filled with small demons, they dislike you.\n");
    items=({ 
      "cave","A cave full of small demons"
    });
    dest_dir=({
      "/players/sherman/hills/cave7","west",
      "/players/sherman/hills/cave9","down"
    });
    clone_list = ({1,6,"small demon","/players/sherman/hills/demons",0});
    ::reset();
    replace_program("room/room");
}




