inherit "room/room";

#include "/players/mangla/defs.h"

int _list() {
    say("The smith talks to " + TP->NAME + ".\n");
    write("The smith says:\n");
    write("A Faunen broadsword.....2500 coins\n");
    write("A Faunen dagger..........150 coins\n");
    write("A Faunen knife............20 coins\n");
    return 1;
}

int _ask(string str) {

    if(str!="smith for list") return 0;
    if(!present("faunsmith",this_object())) {
        write("There is no smith here to talk with\n");
        return 1;
    }
    _list();
    return 1;
}

int _buy(string str) {

    object obj;

    if(!present("faunsmith",TO)) {
        write("There is no smith present to buy anything from!\n");
        return 1;
    }
    if(str!="broadsword" && str!="dagger" && str!="knife") return 0;
    if(str=="broadsword" && TP->query_money() > 2499) {
	obj=clone_object("/players/bobo/kobh/broadsword");
        MOVE(obj,TP);
        TP->add_money(-2500);
        write("The smith says: Here you are, hope you'll be satisfied!\n");
        return 1;
   }
   if(str=="dagger" && TP->query_money()>149) {
	obj=clone_object("/players/bobo/kobj/dagger");
       MOVE(obj,TP);
       TP->add_money(-150);
       write("The smith says: Here you are, hope you'll be satisfied!\n");
       return 1;
  }
  if(str=="knife" && TP->query_money()>20) {
	obj=clone_object("/players/bobo/kobj/knife");
      MOVE(obj,TP);
      TP->add_money(-19);
      write("The smith says: Here you are, hope you'll be satisfied!\n");
      return 1;
  }
  write("The smith says: You don't have enough money, my friend!\n");
  return 1;
}

int _read(string str) {

    if(str!="sign") return 0;
    write("Unfortunatley the sign is written in Faunen letters you do not\n" +
          "understand, but you could possibly ask for a list.\n");
    return 1;
}

void reset(int arg) {

    if (arg) return;
    set_light(1);
    short_desc = "The Faun-smithy";
    long_desc = "You are in the Faun-smithy.\n"+
                "The smith stands at the forge and pound out some steel.\n"+
                "There is a sign attached to the wall.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/faun_shop","west",
		"players/bobo/krooms/mythwood/faun_mark2","southwest",
             });
    items=({
            "sign","It's written in Faunen letters, but you can ask for a list",
          });
    MOVE(clone_object("players/bobo/kmonster/faunsmith"),TO);
}

init() {
    ::init();
    if(present("faunsmith",this_object())) {
        add_action("_list","list");
        add_action("_buy","buy");
        add_action("_ask","ask");
    }
    add_action("_read","read");
}

