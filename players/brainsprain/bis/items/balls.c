inherit "obj/treasure";

do_juggle(string arg){
if (arg != "balls"){
write("Juggle what?\n");
return 1;
} 
else {
write("You juggle the balls.\n");
say(capitalize(this_player()->query_name())+" juggles his balls.\n");
return 1;
}
}

void reset(int arg){
set_id("balls");
set_alias("juggling balls");
set_short("Jester's Balls");
set_long(
"These balls are the court jesters favorite toys.  He is always juggling "+
"them as he amuses the king.  There are three balls in this set, one blue "+
"one green, and one yellow.  Maybe you can juggle them.\n");
set_value(40);
set_weight(5);
}
void init(){
  ::init();
  add_action("do_juggle","juggle");
  }
