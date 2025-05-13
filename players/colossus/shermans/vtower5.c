#pragma strict_types

inherit "room/room";

void reset(int arg){
    int i;
    if (arg) return;
    set_light(1);
    short_desc="On the top of the vampire tower";
    long_desc=
    "At the top of the tower is a small room which is home or\n\
prison to someone. Glancing around you see curtains, decorations\n\
long since faded and a certain quality that you can only term\n\
feminine. Everything has started to decay and even the walls\n\
show signs of aging.\n";
    items=({ 
      "room", "The room has a quality that you can only call feminine",
      "curtains", "The curtains were once made of frilly lace",
      "walls", "The walls made of plaster are cracked and peeling",
    });
    dest_dir=({
      "/players/sherman/vtower4","down"
    });
    clone_list = ({ 1,3, "vampire lady", "/players/sherman/vampire6", 0});
    ::reset();
    replace_program("room/room");
}
