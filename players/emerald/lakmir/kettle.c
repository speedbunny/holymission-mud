#define TP this_player()
#define CLONE clone_object
#define MOVE move_object
#define TPN this_player()->query_name()
inherit "/obj/container";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("kettle");
  set_max_weight(12);
  set_short("A black kettle");
  set_long("A medium-sized black kettle, just big enough to make fish soup.\n");
  set_value(100);
  set_weight(2);
  set_can_get(0);
}

void init() {
    ::init();
    add_action("_stir", "stir");
    add_action("_scoop", "scoop");
}

_stir(str) {
  object kettle,stove,spoon,item1,item2,item3,item4,item5,item6,ob;
  kettle=this_object();
  stove=present("stove",environment(kettle));
  if(kettle) {
    item1 = present("cook water", kettle);
    item2 = present("cod filet", kettle);
    item3 = present("herring filet", kettle);
    item4 = present("perch filet", kettle);
    item5 = present("tuna filet", kettle);
    item6 = present("salmon filet", kettle);
  }
  else {
    write("Something is missing for the soup...\n");
    return 1;
  }
  switch(str) {
    case "kettle" :
    case "soup" :
    case "fish soup" :
      if (!stove->query_is_lighted()) {
        write ("First you shout heat the soup!\n");
        return 1;
      }
      ob=this_player()->query_wielded();
      if(!ob || (ob && !ob->id("spoon")) ) {
        write ("Ouch!!! You burn yourself with the hot soup.\n");
        this_player()->hit_player(random(10),7);
        return 1;
      }
      write("The soup is ready to serve.\n");
      say(TPN + " stirs the soup.\n");
      if(item1 && item2 && item3 && item4 && item5 && item6) {
        destruct(item1);
        destruct(item2);
        destruct(item3);
        destruct(item4);
        destruct(item5);
        destruct(item6);
        item1 = CLONE("/players/emerald/lakmir/fishsoup");
        MOVE(item1, kettle);
      }
      else
        write("Hm.. perhaps something is missing?\n");
      return 1;
    default :
      notify_fail("Stir what?\n");
      return 0;
  }
}

_scoop(str) {
  object bowl,soup;
  
  switch(str) {
    case "soup" :
    case "fish soup" :
      if (!soup=present("soup",this_object())) {
        write ("There is no fish soup in this kettle!\n");
        say(TPN+ " tries to scoop air!\n");
        return 1;
      }
      if (!bowl = present ("bowl",this_player())) {
        write ("You have no bowl for the fish soup!\n");
        say(TPN + " has no bowl for the soup!\n");
        return 1;
      }

      if (bowl) {
        write("The bowl is now full with fish soup.\n");
        say(TPN + " fills a bowl with fish soup.\n");

        destruct (soup);
        destruct (bowl);
        transfer(clone_object("/players/emerald/lakmir/soupbowl"),TP);
        return 1;
      }
  }
}
