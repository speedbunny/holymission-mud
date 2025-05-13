inherit "room/room";
reset(tick){
if(tick)return;
set_light(1);
short_desc= ("In a small hallway.\n");
long_desc= ("This is a small hallway that leads to a stone wall. The\n"+
            "wall seems to have no breaks in it and save for some writing\n"+
            "on it, there is nothing special about it. The floor is also\n"+
            "very plain except for a large white disk in the center. There\n"+
            "seems to be no way to go forward.\n");
items= ({"writing", "It reads 'When a man forgets the lessons of the "+
                              "past he is doomed to what them? "+
                              "     say (answer)",
         "disk", "It is a large white disk",
         "hall", "It seems to have come to a dead end." });
dest_dir= ({ "/players/akira/area/front", "south" });
clone_list=({1,1, "guardian", "/players/akira/mobs/guardian", 0});
::reset(tick);
}
init(){
::init();
add_action("_say", "say"); }
_say(str){
if(!str){
notify_fail("A voice in your head says 'wrong answer!' \n");
return 0; }
if(str== "repeat" ){
write("The white disk glows red and teleports you into the temple.\n");
this_player()->move_player("up#players/akira/area/g_hall");
return 1;
}
}
