#define me this_player()
#define name this_player()->query_name()
 
id(str) { return "box_clone"; }
 
reset()
{
 object box;
 if(!present("black box",me)) {
 box = clone_object("players/animal/closed/box");
 move_object(box,me);
 }
  call_out("end",1);
}
 
end() {
      destruct(this_object());
}
