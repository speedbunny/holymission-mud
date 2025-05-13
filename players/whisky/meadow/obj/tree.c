/* apple tree (c) Whisky */

#define TP	this_player()
#define TPN	TP->query_name()
#define TPPOS	TP->query_possessive()
#define TPOBJ	TP->query_objective()

int counter;

reset(arg) { counter=0; }

id(str) { return str=="tree"; }
short() { return "An apple tree"; }
long() { write("A big apple tree.\n"); }

init() { 
  add_action("get_apple","pick");
  add_action("get_apple","get");
  add_action("get_apple","take");
  add_action("shake","shake");
  add_action("climb","climb");
}

get_apple(str) {
  object ob;
  if (str=="apple") {
    if (counter >= 4) {
       write("You can't, there are no apples left in the tree.\n");
       return 1;
    }
    write("You picked an apple from the tree.\n");
    say(TPN+" picked an apple.\n");
    ob=clone_object("players/whisky/garden/obj/apple");
    if (transfer(ob,TP)) 
       move_object(ob,environment(TP));
    counter++;
    return 1;
  }
}

shake (str) {
object ob;
int i;

  if (str=="tree") {
    if (counter >= 4 ) {
       write("You shake the tree. Nothing happens.\n");
       return 1;
    }
    write("Some apples fell from the tree.\n");
    say(TPN+" shakes the tree, and some apples fall down.\n");
    for (i=0;i<2;i++)
       move_object(clone_object("players/whisky/garden/obj/apple"),
		   environment(this_object()));
    counter+=2;
    return 1;
  }
}

climb(str) {
  if (str=="tree") {
     write("You start climbing the tree ... but you fall down !\n" +
	   "Ouch, that hurts !\n");
     say(TPN+" tries to climb up the tree, but falls down.\n"+
	capitalize(TPOBJ)+" looks a bit more damaged now ...\n");
     TP->reduce_hit_point(10+random(10));
     return 1;
  }
}
