inherit "/obj/monster";

#define PATH     ({"south",\
                   "west",\
                   "east",\
                   "south",\
                   "south",\
                   "east",\
                   "west",\
                   "south",\
                   "east",\
                   "west",\
                   "north",\
                   "north",\
                   "north",\
                   "north",})

int i;


reset(arg) {
  ::reset(arg);

  if (!arg) {
    set_name("goat");
    set_alias("animal");
    set_alt_name("mountain goat");
    set_short("A mountain goat");
    set_long("This is a hungry mountain Goat. On her head there are \n"+
             "dangerous horns.\n");
    set_race("goat");
    set_gender(2);
    set_smell("The goats smells like any other animal.");
    load_chat(10,({"BeeeeeeeeeeHHHHHHH!\n",
                   "The goat munches on some grass.\n",
                   "The goat looks hungry.\n",}));
    set_level(5);
    set_hp(200);
    set_ep(250);
    set_al(150);
    set_wc(5);
    set_ac(1);
    set_aggressive(0);
    set_whimpy(-1);
    call_out("reset",15,2);
  }
  if (arg == 2)
   { if (!environment(this_object())) return;
     do_move();
   }
}

init() {
  ::init();
  enable_commands();
}

do_move() {
string dirie;
 dirie=PATH[i];
 i++;
 if(i>13) i=0;
  command(dirie,this_object());
  call_out("reset",15,2);
  eat_any_obj();
 return;
}
 
eat_any_obj() {
    object ob;
    int weight;

    ob = first_inventory(environment(this_object()));
    while(ob) {
	if (call_other(ob, "get", 0) && call_other(ob, "short")) {
	    weight = call_other(ob, "query_weight", 0);
	    if (!add_weight(weight)) {
		say(cap_name + " tries to eat " + call_other(ob, "short", 0) +
		    " but fails.\n");
		return;
	    }
	    say(cap_name + " eats " + call_other(ob, "short", 0) + ".\n");
            call_out("hungry",1);
            add_weight(-weight);
            this_object()->heal_self(random(40));
            destruct(ob);
	    return;
	}
	ob = next_inventory(ob);
    }
}

hungry()
{ say("The goat still looks hungry.\n");
  return 1; }
