inherit "obj/food";

reset(arg) {
  if(arg) return;
  set_name("olive");
  set_short("a big green olive");
  set_long("It looks very big and tasty the farmers press \n"+
          "them to get some oil from it.\n");
  set_value(2);
  set_weight(1);
  set_eater_mess("Mhhhhh tastes a bit oily but fine.\n"); 
  set_strength(5);
}
init() {
 ::init();
 add_action("press","press");
 
 }
press(str) {
  if (str!="olive") { return; }
  write("As you press the olive, a drop of oil comes out from the fruit.\n");
  say(this_player()->query_name()+" presses the olive.\n");
  move_object(clone_object("/players/whisky/meadow/obj/olive2"),this_player());
  move_object(clone_object("/players/whisky/meadow/obj/drop"),this_player());
  destruct(this_object());
 return 1;
} 
query_quest_item() { return 1; }

