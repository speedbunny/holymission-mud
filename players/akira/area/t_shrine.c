inherit "room/room";
reset(tick){
::reset(tick);
if(tick) return;
set_light(1);

short_desc=("A Shrine to the gid Mask.\n");
long_desc=("This is a small Shrine built in honor of the thief god Mask.\n"+
           "There is a small altar in the corner of the room that has a\n"+
           "few candles and flowers on it. The walls are covered with some\n"+
           "strange writings. Other than the altar this room seems to be\n"+
           "very empty.\n");
items=({"shrine", "This is a shrine to the god Mask.",
        "walls", "They are covered with a strange writing",
        "writing", "You can not make out what it says",
        "altar", "It looks as if you could slide it.",
        "flowers", "they look very cheap.",
        "candles", "They look like they were stole from another shrine." });
dest_dir=({"/players/akira/area/shrine", "southwest"});
property=({"no_teleport"});
clone_list=({1, 1, "guardian", "/players/akira/mobs/guardian", 0});
::reset(tick);
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
this_player()->move_player("north#players/akira/area/vault5");
return 1;
}
}
