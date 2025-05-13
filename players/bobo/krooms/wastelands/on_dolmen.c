inherit "room/room";
 
object obj;
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="On a stone plate";
    long_desc="You're standing on the stone plate of the dolmen.\n"+
      "On the plate you see some runes engraved.\n";
    dest_dir=({
	"players/bobo/krooms/wastelands/dolmen1","down",
   });
 
   items=({
   "engravings","Ordinary runes, try to read them",
   "runes","Ordinary runes, try to read them",
   });
 
}
 
init() {
::init();
  add_action("read","read");
}
 
read(str) {
  if(str!="runes" && str!="engravings") return;
  write("Your rune-reading's not the best, but you decipher them:\n");
  write("They read:'R.I.P.'\n");
  return 1;
}
 
