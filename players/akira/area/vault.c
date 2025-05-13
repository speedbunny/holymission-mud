inherit "room/room";
reset(tick){
::reset(tick);
if(tick) return;
set_light(1);

short_desc=("Standing before a Vault Door.\n");
long_desc=("You stand before a huge set of doors. The doors seem to\n"+
           "have something writen on them. The walls of this room are\n"+
           "covered with some strange writing.\n");
items=({"walls", "They are covered with strange writings",
        "writing", "You can not tell what it says",
        "door", "The Beginning of Eternity. "+
                "The End of Time and Space. "+
                "The Beginning of Every End. "+
                "And the end of Every Place? "+
                "   say (answer) ",
         });
dest_dir=({"/players/akira/area/well", "up" });
property=({"no_teleport"});
clone_list=({1, 1, "guardian", "/players/akira/mobs/guardian", 0});
::reset(tick);
}
init(){
::init();
add_action("_say", "say");
}
int _say (string str){
if(!str){
notify_fail(
   "You do not think that was it\n");
return 0;
}
if(str== "e"){
write("You say the answer and the doors open for you.\n");
write(this_player()->query_name()+" steps into the vault!\n");
this_player()->move_player("north#players/akira/area/vault1");
return 1;
}
}
