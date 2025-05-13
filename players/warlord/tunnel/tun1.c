#define DOOR "/players/warlord/dracdun1"
inherit"room/room";
reset(arg) {
if (arg) return;
set_light(-5);
short_desc="A gloomy tunnel.\n";
long_desc="This tunnel is very damp with sewage all around. You can't \n see anything around you. You see a grate above you.\n\n";
items=({
"sewage","Its very black and smells terrible. Its probably from the castle above",
"grate","You see a @@query_grate@@",
});
dest_dir=({
/*
"players/warlord/tunnel/tun2","west",
"players/warlord/tunnel/tun3","east",
*/
});
}
init () {
::init();
 add_action("open","open");
 add_action("close","close");
 add_action("lock","lock");
 add_action("unlock","unlock");
 add_action("move","up");
 return 1;
 }
 open(str){DOOR->open(str);return 1;}
 close(str){DOOR->close9(str);return 1;}
 lock(str){DOOR->lock(str);return 1;}
 unlock(str){DOOR->unlock(str);return 1;}
 move() {
   if(DOOR->query_open()==1) {
     this_player()->move_player("up#players/warlord/dracdun1");
     }
     else{
     write("You bng your head on the grate.\n");
     return 1;
     }
   return 1;
}
query_grate(str) {
if (DOOR->query_open()==0 ) {
  return str="grate it is made of iron and is closed";
}
else {
  return str= "grate it is made of iron and is opened";
  }
}
