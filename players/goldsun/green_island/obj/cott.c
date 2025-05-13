inherit "/players/padrone/obj/thing";
 reset(arg){
  ::reset(arg);
 if (arg) return;
 set_name("stilt house");
 set_alias("house");
 set_short("A wooden stilt house");
 set_long("A stilt house.\n");
 set_can_get(0);
 }

init(){
 ::init();
add_action("enter","enter");
}

int enter(string str){
 if (str=="cottage" || str=="house" || str=="stilt house"){
  this_player()->move_player("into the cottage#players/goldsun/green_island/room/cottage_hm");
  return 1;
 }
 notify_fail("Enter what?\n");
}
