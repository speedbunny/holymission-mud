inherit "obj/thing";
 string crack_desc;
 string query_item()   { return item; }
 status has_started;
 object qst;
  reset(arg){
has_started = 0;
  crack_desc = "A crack in the tree, large enough to enter";
   set_name("tree");
 set_short("A tree");
  set_alias("tree");
  set_value(0);
 set_can_get(0);
  set_long("An old oak tree\n"+
           "It looks like it was planted here by accident\n");
  items = ({ "crack","A crack in the tree",
          });
  return 1;
}
init(){
 add_action("do_climb","climb"); add_action("do_enter","enter");
 }
