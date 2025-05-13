inherit "obj/treasure";
reset(arg) {
if(arg) return;
set_id("cereal");
set_alias("box");
set_short("A box of Cap'n'Crunch cereal");
set_long("A large box of cap'n'crunch with berries \n"+
"cereal!  Maybe you can 'have cereal'. \n");
set_value(1);
  }
init() {
add_action("have", "have");
::init();
}

have(str) {
if(str!="cereal")
write("And what is it you want? \n");
if(str=="cereal")
write("You whip out a bowl, some milk, and a spoon and \n"+
"chow down!\n\n");
say(this_player()->query_name() + " whips out a bowl, a spoon, and some milk, \n"+
"pours some Cap'n'Crunch, and chows down!\n"+
"   Don't you wish YOU had some!\n\n");
return 1;
  }
