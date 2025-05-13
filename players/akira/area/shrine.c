inherit "room/room";
reset(tick){
::reset(tick);
if(tick) return;
set_light(1);

short_desc=("A Shrine to the Creator.");
long_desc=("This is a large shrine created to honor the god Illuvatar.\n"+
           "It was built so that those who follow him might pray for\n"+
           "those they had lost in the war. There is a altar with many\n"+
           "candles and flowers on it in the center of the room. The\n"+
           "walls of the shrine are coved with gold writing.\n");
items=({"shrine", "This is a shrine to Illuvatar",
        "altar", "It looks like you might be able to slide it",
        "flowers", "They are very bright colored and smell nice.",
        "candles", "They light up the room",
        "walls", "They have some strange gold writing on them",
        "writing", "You can't seem to make it out" });
dest_dir=({"/players/akira/area/h_hall1", "south",
           "/players/akira/area/a_shrine", "east",
           "/players/akira/area/c_shrine", "west",
           "/players/akira/area/t_shrine", "northeast" });
 clone_list=({ 1, 1, "guardian", "/players/akira/mobs/guardian", 0});
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
this_player()->move_player("up#players/akira/area/vault2");
return 1;
}
}
