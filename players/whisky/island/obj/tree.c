/* apple tree (c) Whisky */

#define TP	this_player()
#define TPN	TP->query_name()
#define TPPOS	TP->query_possessive()
#define TPOBJ	TP->query_objective()

int counter;

reset(arg) { counter=0; }

id(str) { return str=="tree"; }
short() { return "A big palm tree"; }
long() { write("A big palm tree, there are some bananas hanging down.\n"); }

init() { 
  add_action("get_banana","pick");
  add_action("get_banana","get");
  add_action("get_banana","take");
  add_action("shake","shake");
  add_action("climb","climb");
}

get_banana(str) {
  object ob;
  if (str=="banana") {
    if (counter >= 30) {
       write("You can't, there are no more bananas left in the palm-tree.\n");
       return 1;
    }
    write("You picked a banana from the palm-tree.\n");
    say(TPN+" picked a banana from the tree.\n");
    ob=clone_object("players/whisky/island/obj/banana");
    if (transfer(ob,TP)) move_object(ob,environment(TP));
    counter++;
    return 1;
  }
}

shake (str) {
int i;

  if (str=="tree") {
    if (counter >= 10 ) {
       write("You shake the palm-tree. Nothing happens.\n");
       return 1;
    }
    write("Some bananas fell from the palm-tree.\n");
    say(TPN+" shakes the palm-tree, and some bananas fall down.\n");
    for (i=0;i<3;i++)
       move_object(clone_object("players/whisky/island/obj/banana"),
		   environment(this_object()));
    counter+=2;
    return 1;
  }
}

climb(str) {
  if (str=="tree") {
     write("You start climbing the palm-tree ... but you fall down !\n" +
	   "Ouch, that hurts !\n");
     say(TPN+" tries to climb up the palm-tree, but falls down.\n"+
	capitalize(TPOBJ)+" looks a bit more damaged now ...\n");
     TP->reduce_hit_point(10+random(10));
     return 1;
  }
}
query_property()
{
  return "no_clean_up";
}
