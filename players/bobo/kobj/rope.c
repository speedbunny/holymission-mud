inherit "/obj/treasure";
 
object obj;
int i;
 
reset(arg) {
if (arg) return;
 set_alias("rope");
 set_short("A rope");
 set_long("This rope is hanging down from the cloister.\n");
}
 
get() { return ; }
 
init() {
  add_action("climb","climb");
}
 
climb(str) {
  if(str!="rope") return;
if (this_player()->query_str()<10 ){
    write("You are too weak for such a long climb.\n");
    return 1; }
  else {
    write("It's hard, but finally you reach the top of the rope.\n");
   this_player()->move_player("up#players/kelly/rooms/mythwood/top_rope");
    return 1;
  }
}
 
destru() {
  write("The rope is pulled back again.\n");
  destruct(this_object());
}
