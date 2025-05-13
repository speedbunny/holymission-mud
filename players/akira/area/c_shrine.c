inherit "room/room";
reset(tick){
::reset(tick);
if(tick) return;
set_light(1);

short_desc=("A Shrine to Crom.\n");
long_desc=("This is a shrine to the barbarian god Crom. There is a small\n"+
           "altar in the corner of the room that can best be described as\n"+
           "crude. There are no flowers or candles on the altar, just a\n"+
           "half eaten slab of meat. The walls of the room are covered in\n"+
           "what looks to be like writing, but scribble might be a better\n"+
           "word for it.\n");
items=({"shrine", "This is a shrine to the god Crom.",
        "altar", "It looks as if you might be able to slide it",
        "meat", "It looks like someone took a bite then left it.",
        "slab", "It is a half eaten slab of meat.",
        "walls", "They have crude writing on them.",
        "scribble", "You can't make out what it says"
        "writing", "You can not make out this scribble" });
dest_dir=({"/players/akira/area/shrine", "east" });
clone_list=({1, 1, "guardian", "/players/akira/mobs/guardian", 0});
::reset(tick);
property=({"no_teleport"});
}
init(){
::init();
add_action("_slide", "slide");
}
int _slide (string str){
if(!str){
notify_fail(
   "What would you like to slide?\n");
return 0;
}
if(str== "altar"){
write("You slide the altar and find a hidden room behind it!\n");
write(this_player()->query_name()+" steps behind the altar!\n");
this_player()->move_player("north#players/akira/area/vault3");
return 1;
}
}
