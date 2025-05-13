inherit "room/room";
reset(tick){
::reset(tick);
if(tick) return;
set_light(1);

short_desc=("In front of a mountain");
long_desc=("You are standing if front of a large mountain face. From\n"+
           "here there looks to be no way around it or up it. As you\n"+
           "look at the mountain side, your thoughts seem to drift. It\n"+
           "must be all the fresh air getting to your head.\n");
items=({"mountain", "Something just isn't right here!",
        "face", "You just can't seem to foucus your thoughts" });
dest_dir=({"/players/darastor/guild/rooms/open3", "west"});
clone_list=({ 1, 1, "rod", "/players/akira/weapons/rod", 0});
::reset(tick);
}
init(){
::init();
add_action("_focus", "focus");
}
int _focus (string str){
if(!str){
notify_fail(
"What would you like to try to focus?\n");
return 0;
}
if(str== "thoughts"){
write("As you focus your thoughts, you notice that the side of the\n"+
      "mountain is not real. You step past the illusion, and now\n"+
      "stand before a large Temple.\n");
write(this_player()->query_name()+" steps into the mountain side!\n");
this_player()->move_player("up#players/akira/area/front");
return 1;
}
}
