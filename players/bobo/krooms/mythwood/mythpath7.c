inherit "room/room";
 
int picked;
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    picked=0;
    short_desc="A path in Mythwood";
    long_desc="You are walking on a path in Mythwood.\n"+
      "To the east there is a faun village.\n"+
      "A tree stands besides the path. "+
      "A wooden sign stands here.\n";
 
    dest_dir=({
	"players/bobo/krooms/mythwood/fuan_vill1","east",
	"players/bobo/krooms/mythwood/clear6","west",
   });
    items=({
    "sign","Its a wooden sign",
    "tree","There are many berries hanging on the tree.\nMaybe you"+
      " can pick them",
    });
}
 
init() {
  ::init();
  add_action("read","read");
  add_action("pick","pick");
}
 
read(str) {
 if(str!="sign") return;
   write("It reads:You are standing in front of the Faun village.\n");
   return 1;
}
 
pick(str) {
  int ran,i;
  object berry;
  if(str!="berry" && str!="berries") return;
    if (!picked) {
      ran=2+random(5);
      write("You pick some berries from the tree.\n");
      while (i<ran) {
	berry=clone_object("players/bobo/kobj/berry");
        transfer(berry,this_player());
        i+=1;
      }
      picked=1; }
    else {
      write("It's a pity,they are hanging to high.\n");
    }
    return 1;
}
 
