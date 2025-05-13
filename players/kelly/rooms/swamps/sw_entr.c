inherit "room/room";
 
object obj;
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The entrace to the swamps";
  long_desc="You're at the entrance to the magic swamps.\n"+
  "A little brook makes its way through the grassy ground with\n"+
  "some murmur.\n";
  dest_dir=({
    "players/kelly/rooms/swamps/grass1","east",
    "players/kelly/rooms/swamps/swamp6","west",
  });
  items =({ "brook","A little brook that makes its way through the grassy ground", });  
}
 
init() {
::init();
  add_action("info","listen");
}
 
info(str) {
  if (str!="to murmur" && str!="to brook") return 0;
    write("Beware of the swamps, beware, beware...\n");
    write("Don't stay to long in the swamps, think \n");
    write("of this when you're there !\n");
    return 1;
}
