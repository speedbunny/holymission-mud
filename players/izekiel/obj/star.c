
inherit "obj/armour";
#include "/players/izekiel/defs.h"

reset(arg){
  ::reset(arg);
  if(arg) return;
    set_name("star");
    set_alias("star of the iron fist champion");
    set_short("Star of the Iron Fist champion");
    set_long(
    "This star is a memento of your victory in the Ruler of the Iron Fist\n"+
    "Tournament.  To show everybody your prize, just type 'show star'.\n");
    set_type("star");
    set_weight(0);
}

init(){
  ::init();
  AA("_show","show");
}

query_auto_load() { return "players/izekiel/obj/star:"; }

_show(str){
  if(!str){
    write("Show what?\n");
    return 1;
  }
  if(str == "star"){
    write("You show everybody that you're a champion of the Iron Fist!\n");
    say(TPN+" shows you "+TP->QP+" Star of the Iron Fist, proving that "+
       TP->QPRO+" is \ntruly a champion of the tournament.\n");
    return 1;
  }
}

remove(){
  write("You feel that you should not humble yourself like that, and decide\n"+
     "to leave it on your person.\n");
  return 1;
}

dest(){ destruct(TO); }

drop(){
  if(query_verb()=="sell"){
    write("You can't sell that! It's priceless!\n");
  return 1;
  }

  if(query_verb()=="give"){
    write("Let them get their own damn star!\n");
    return 1;
  }

  write("You can't drop that! It's priceless!\n");
  return 1;
}
