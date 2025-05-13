#include "mroom.h"

void reset(int arg){
    if(arg) return;
    set_light(1);
    short_desc = "Frodo's bedroom";
    long_desc =
    "You have entered Frodo's bedroom. It is a tidy room with a small bed,\n"+
    "a chest, a desk, and a chair. This room, as most hobbit rooms are, is\n"+
    "small yet snug and cozy. You find this a place where you feel solace and\n"+
    "bliss.\n";
    dest_dir = ({
      SHIRE+"/frodo_house1", "south",
    });
    items = ({
      "bed", "A small bed. Looks comfy",
      "chest", "a chest where Frodo keeps his clothes and stuff",
      "desk", "This is Frodo's desk where he writes poetry",
      "chair", "A chair to sit in",
    });
    clone_list = ({ 1,1, "frodo", "/players/colossus/mearth/shire/frodo", 0});
    ::reset();
    replace_program("room/room");
}
