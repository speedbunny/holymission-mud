inherit "obj/treasure";

reset(arg) {
  set_id("find");
}
init() {
 ::init();
 add_action("find"); add_verb("find");
}

find(arg) {
  object ob, ob2;
  ob = find_living(arg);
  if(arg)
    tell_object(find_player(arg),"Find_player\n");
  if(arg)
    tell_object(find_living(arg),"Find_living arg\n");
  if(ob)
    tell_object(ob,"Find_living ob\n");
  ob2 = find_living(ob);
  if(ob2)
    tell_object(ob2,"Find_living ob2  ob2\n");
  return 1;
}
