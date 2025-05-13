#define TP this_player()
#define TPN TP->query_name()
inherit "obj/treasure";
 
reset(arg) {
  if (!arg) {
     set_id("paper");
     set_alias("toilet-paper");
     set_short("A sheet of toilet-paper");
     set_long("A pink pleasant sheet of toilet-paper.\n");
     set_value(1);
  }
}
 
init() {
  ::init();
  add_action("clean","clean");
  add_action("clean","polish");
  add_action("put","put");
  }
put(str) {
  object ob;
  if (ob=present("drop",this_player())) {
     if (str=="oil on paper" || str=="drop on paper") {
       write("You put some oil on the paper.\n");
       say(TPN+" puts some oil on the paper.\n");
       move_object(clone_object("players/whisky/garden/obj/paper2"),TP);
       destruct(ob);
       destruct(this_object());
      return 1; 
     }
     else {
     return;
    }
   return 1;
  }
  else {
  return;
 }
}
 clean(str) {
  object ob;
  if (str!="key" && str!="iron key" && str!="rusty iron key") {
     notify_fail("Well you clean the "+(str)+".\n");
  return 0;
  }
  if (ob=present("drop",this_player())) { return; }
   write("Well, but you will need some liquid to clean the "+(str)+"\n");
   say(TPN+" tries to clean a "+(str)+" but fails.\n");
  return 1; 
 }
query_quest_item() { return 1; }

