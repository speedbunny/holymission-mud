inherit "room/room";
reset(tick){
::reset(tick);
if(tick) return;
set_light(1);

short_desc=("A Shrine to Amaterasu.\n");
long_desc=("This is a large shrine dedicated to the ninja god Amaterasu.\n"+
           "There is an altar at the far side of the room that is covered\n"+
           "with candles and flowers. The walls fo the shrine seem to be\n"+
           "covered with some strange red writing. A small pillow sits in\n"+
           "front of the altar.\n");
items=({"shrine", "This is a shrine to Amaerasu, the ninja god.",
        "altar", "It looks as if you might be able to slide it.",
        "flowers", "They look very strange, but never the less, very nice",
        "candles", "They light up the room",
        "pillow", "It is a small prayer pillow",
        "walls", "They have some red writing on them.",
        "writing" ,"You do not understand what it says" });
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
this_player()->move_player("east#players/akira/area/vault4");
return 1;
}
}
