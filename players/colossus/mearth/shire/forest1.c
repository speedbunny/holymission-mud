inherit "/room/room";


void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "In the Hobbit forest";
    long_desc =
    "You are near the entrance of the forest which is directly north.\n"+
    "You hear the sounds of birds singing and other wildlife sounds.\n"+
    "It seems very comforting but it still might be best to be on your\n"+
    "guard. Tall trees stretch out with their tree limbs overhead and\n"+
    "the light here doesn't appear to be too good. If you go on further\n"+
    "you might like to consider bringing a light source with you.\n";

    dest_dir =
    ({
      "/players/colossus/mearth/shire/main3", "north",
      "/players/colossus/mearth/shire/forest2", "west",
      "/players/colossus/mearth/shire/forest3", "east",
      "/players/colossus/mearth/shire/forest4", "south",
    });
}
