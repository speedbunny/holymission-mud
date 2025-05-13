inherit "room/room";
reset(tick){
::reset(tick);
if(tick) return;
set_light(1);

short_desc=("In front of a mountain");
long_desc=("You are standing if front of a large mountain face. From\n"+
           "here there looks to be no way around it or up it. As you\n"+
           "look at the mountain side, your toughts seem to drift. It\n"+
           "must be all the fresh air getting to your head.\n");
items=({"mountain", "Something just isnt right here!\n"});
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
this_player()->move_player("up#players/akira/psi/tower");
write("As you focus your thoughs, you notice that the side of the\n"+
      "mountain is not real. You step past the illusion, and now\n"+
      "stand defore a large tower.\n");
write(this_player()->query_name()+" staps into the mountain side!\n");
return 1;
}
}
