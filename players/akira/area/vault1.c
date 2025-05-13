inherit "room/room";
reset(tick){
if(tick)return;
set_light(1);
short_desc=("Inside a large Vault.\n");
long_desc=("This is a large vault used to store the weapons and objects\n"+
           "that were judged to powerful for the world. This vault does\n"+
           "not seem to hold a lot of stuff. However in the far wall is\n"+
           "embedded a large glowing sphere. The walls are covered with\n"+
           "some starnge writing.\n");
items=({"walls", "they are covered with some strange writing.",
        "vault", "It holds object of great power.",
        "sphere", "This is the Legendary Cronus Shpere. You can tell"
                  "that all you need to do is touch the sphere and"
                  "it will do the rest!" });
dest_dir=({"/players/akira/area/vault", "south"});
property=({"no_teleport"});
}
init(){
::init();
add_action("_touch", "touch"); }
_touch(str){
if(!str){
notify_fail("Touch what?\n");
return 0; }
if(str== "sphere" && this_player()->query_guild()== 10){
write("The Cronus Shpere pulls you back threw time!\n");
this_player()->move_player("up#players/akira/area/gap");
return 1;
}
}
