inherit "room/room";
reset(tick){
if(tick)return;
set_light(1);
short_desc=("The Well of Souls.\n");
long_desc= ("The only thing in this room is a small pool of water in\n"+
            "the center of the room. This pool has been called the Well\n"+
            "of Souls. The reason for this has been lost over the ages.\n"+
            "The walls for the room are covered in some strange writing.\n");
items=({"pool", "You can see your refection in it.",
        "well", "It is a small pool of water.",
        "walls", "They have some strange writing on them",
        "writing", "You can not make out what it says" });
dest_dir= ({"/players/akira/area/down", "up" });
}
init(){
::init();
add_action("_enter", "enter"); }
_enter(str){
if(!str){
notify_fail("Enter what?\n");
return 0; }
if(str== "pool" ){
this_player()->move_player("down#players/akira/area/vault");
return 1;
}
}
