#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(0);
    short_desc="A dead end of the cave";
    long_desc=
    "This is a dead end of the cave, a huge demon is lurking here.\n";
    items=({ 
      "cave","A dry and dark cave"
    });
    dest_dir=({
      "/players/sherman/hills/cave10","east"
    });
    clone_list = ({1,1,"archdemon","/players/sherman/hills/archdemon",0});
    ::reset();
    replace_program("room/room");
}
