inherit "obj/food";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("olive");
  set_short("A big green olive");
  set_long("It looks very big and tasty. The farmers press \n"+
          "them to extract their oil.\n");
  set_value(2);
  set_weight(1);
  set_eater_mess("Mhhhhh tastes a bit oily but fine.\n"); 
  set_strength(5);
}
init() {
 ::init();
 add_action("press","press");
 add_action("eat","eat");
 
 }
eat(str) {
  if (str!="olive") return;
  write("You eat an olive.\n");
  say(this_player()->query_name()+" eats an olive.\n");
  destruct(this_object());
 return 1;
 }
press(str) {
  if (str!="olive") { return; }
  write("As you press the olive a drop of oil comes out of it.\n");
  say(this_player()->query_name()+" presses the olive.\n");
  move_object(clone_object("/players/whisky/meadow/obj/olive2"),this_player());
  move_object(clone_object("/players/whisky/meadow/obj/drop"),this_player());
  destruct(this_object());
 return 1;
} 
query_quest_item() { return 1; }

drop() {
  write("You can't drop your olive, its too sticky !\n");
  return 1;
  }
