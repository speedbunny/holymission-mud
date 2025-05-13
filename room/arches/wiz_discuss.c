inherit "room/room";

object proboard,conboard,lvlboard;

void reset(int arg){
    object board;

    if(arg) return;
    set_light(1);
    dest_dir=({ "room/arches/general","north" });
    short_desc="Archwizzards guild";
    long_desc=
    "This is the archwizzards private room to discuss about wizards.\n"+
    "There is a proboard, a contraboard and a levelboard.\n"+
    "Instead of the normal commands you have to enter:\n"+
    "  proread, contranote or levelremove ....\n";
}

void init(){
    ::init();
    if(!this_player()->query_archwiz()) transfer(this_player(),"room/void");
}
