inherit "obj/thing";
 reset(arg){
  ::reset(arg);
 if (arg) return;
 set_name("small hut");
 set_alias("hut");
 set_short("A small hut");
 set_long("A small hut. Who can live in it?\n");
 }

get(){
 return 1;
}

init(){
 ::init();
add_action("enter","enter");
}

int enter(string str){
 if (str=="hut"){
  this_player()->move_player("into the hut#players/goldsun/white_tower/room/hut_room");
  return 1;
 }
 notify_fail("Enter what?\n");
}
