#include "room.h"

object frog;
string function, type, match, function2, type2, match2;

#undef EXTRA_RESET
#define EXTRA_RESET\
  extra_reset();

extra_reset() {
  if(!present("frog king")) {
    frog=clone_object("obj/monster");
    frog->set_name("frog king");
    frog->set_alias("king");
    frog->set_race("frog");
    frog->set_short("The Frog King");
    frog->set_long("This is the Frog King. He's a bit upset though,\n"
	+ "because someone stole his iron crown.\n");
    frog->load_chat(30,({ "Frog King sulks in the corner.\n",
	"Frog King says: Why did he steal my crown.\n",
	"Frog King says: How can I be King without my crown.\n",
	"Frog King sighs deeply.\n", }));
    frog->set_level(5);
    frog->set_frog(1);
    function=allocate(1);
    type=allocate(1);
    match=allocate(1);
    frog->set_match(this_object(),function,type,match);
    move_object(frog, this_object());
    function[0]="gives";
    type[0]="gives";
  }
}

ONE_EXIT("players/moonchild/trollslayer/river1", "out",
	"In the lake",
	"You are swimming in a beautiful lake. There are lily-pads everywhere. Swimming\n"
	+ "in the cool water refreshes you and you feel relaxed and happy swimming here.\n", 1)

init() {
  ::init();
  add_action("drink", "drink");
  add_action("dive", "dive");
}

id(str) { return str=="lilypads" || str=="lily-pads"; }

drink() {
  write("You drink some water. It has a rather thin taste to it.\n");
  say(this_player()->query_name() + " drinks some water.\n");
  return 1;
}

dive() { return !this_player()->move_player(", diving into the lake#players/moonchild/puzzle/lake_bottom"); }

long(str) {
  if(id(str)) {
    write("There are lily-pads everywhere on the lake.\n");
    return 1;
  }
  ::long();
}

gives(str) {
  object crown,jewel,friend;
  string who,what,whom;
  if(sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3) return;
  if(whom!="frog" && whom!="frog king" && whom!="king" && whom!="Frog"
	&& whom!="Frog king" && whom!="King") return;
  if(what!="crown" && what!="iron crown") return;
  crown=present("iron crown",frog);
  if(!crown) return;
  friend=present(lower_case(who),this_object());
  if(!friend) return;
  tell_room(this_object(),"Frog king says: Thank you, " + who + ", for returning my crown.\n");
  tell_object(friend,"Frog king tells you: I am not rich, but I can give you a little present.\n");
  tell_room(this_object(),"Frog king gives jewel to " + who + ".\n");
  jewel=clone_object("obj/treasure");
  jewel->set_id("jewel");
  jewel->set_short("A small green jewel");
  jewel->set_weight(1);
  jewel->set_value(50+random(51));
  move_object(jewel,friend);
  command("give jewel to " + lower_case(who),frog);
  tell_object(friend,"Frog king waves and dives underwater.\n");
  destruct(frog);
  destruct(crown);
}
