#define TP      this_player()
#define TPN     TP->query_name()
#define TPPOS   TP->query_possessive()
#define TPOBJ   TP->query_objective()

inherit "/obj/thing";
int counter,i;

static object pl;
reset(arg) {
counter=0;
i=0;

  ::reset(arg);
  if(arg) return;
  set_name("tree");
  set_short("An olive tree");
  set_long("A big olive tree.  Perhaps you could pick an olive from it?\n");
  set_can_get(0);
}

void init() {
  ::init();
  add_action("get_olive","pick");
  add_action("get_olive","get");
  add_action("get_olive","take");
  add_action("_shake","shake");
  add_action("_climb","climb");
}

get_olive(str) {
  object ob;
  if(!str) {
    notify_fail("Pick what?\n");
    return 0;
  }

  if (str=="olive") {
    if (present("olive",TP)) {
      write("You try to pick another olive, but none are reachable.\n");
      say(TPN+" tries to pick an olive but fails!\n");
     return 1;
    }
    ob=clone_object("/players/emerald/island/obj/olive");

    if (counter >= 10) {
       write("You can't, there are no olives left in the tree.\n");
       return 1;
    }
    if (chk()==1) return 1;
    write("You picked an olive from the tree.\n");
    say(TPN+" picked an olive.\n");
    if (transfer(ob,this_player())) move_object(ob,environment(this_player()));
    counter++;
    return 1;
  }
}

_shake (str) {
int i;

  if(!str) {
    notify_fail("Shake what?\n");
    return 0;
  }

  if (str=="tree") {
    if (present("olive",TP)) {
      write("You shake the tree, but nothing happens !\n");
      say(TPN+" shakes the tree, but nothing happens !\n");
    return 1;
    }
    if (counter >= 4 ) {
       write("You shake the tree.  Nothing happens.\n");
       return 1;
    }
    if (chk()==1) return 1;
    write("Some olives fell from the tree.\n");
    say(TPN+" shakes the tree, and some olives fall down.\n");
    for (i=0;i<2;i++)
      move_object(clone_object("/players/emerald/island/obj/olive"),
                   environment(this_object()));
    counter+=2;
    return 1;
  }
}

_climb(str) {
  if(!str) {
    notify_fail("Climb what?\n");
  }
  if (str=="tree") {
     write("You start climbing the tree ... but you fall down !\n" +
           "Ouch, that hurts !\n");
     say(TPN+" tries to climb up the tree, but falls down.\n"+
        capitalize(TPOBJ)+" looks a bit more damaged now...\n");
     TP->reduce_hit_point(10+random(10));
     return 1;
  }
}
chk(n) {
  object ob,ob2;
   ob=present("armonophis",environment());
   ob2=present(this_player(),environment());
   if (ob && living(ob) && interactive(ob2) && ob2->query_level()>15) {
     if (i < 1 || pl!=ob2) {
       tell_object(ob2,"Armonophis hinders you from stealing his olives.\n");
       pl = ob2;
       call_out("hinder",2,ob2);
       i=1;
     }
     else {
     tell_object(ob2,"Armonophis attacks you !\n");
     ob->attack_object(ob2);
     i=0;
     return 1;
     }
    return 1;
  }
  return 0;
}

hinder(ob2) {
   tell_object(ob2,"Something in your mind tells you: Don't try that again.\n");
   return 1;
}
