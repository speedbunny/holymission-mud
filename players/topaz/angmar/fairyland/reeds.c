/* 12.14.93 Airborne: Changed to room/room */

inherit "room/room";
 int boxhere;
 int fishhere;

reset(arg){
  boxhere=1; fishhere=1;
  
  set_light(1);
  short_desc = "In a clump of reeds";
  long_desc = 
	"You are standing in knee-deep water in a clump of reeds.\n";
  dest_dir = ({"players/topaz/angmar/fairyland/by_lake","west" });

if(!present("elfboy")) {
    object elfboy,rod;
    string chat_str;
    string a_chat_str;
    elfboy=clone_object("obj/monster");
    call_other(elfboy,"set_name","elfboy");
    call_other(elfboy,"set_level",1);
    call_other(elfboy,"set_hp",40);
    call_other(elfboy,"set_wc",3);
    call_other(elfboy,"set_ac",0);
    call_other(elfboy,"set_short","A fishing elfboy");
    call_other(elfboy,"set_alias","boy");
    call_other(elfboy,"set_alt_name","elf");
    call_other(elfboy,"set_al",300);
    call_other(elfboy,"set_long",
      "The elfboy doesn't seem to notice you. He is concentrating\n"+
      "hard on his fishing.\n");

    if(!a_chat_str) {

      a_chat_str=allocate(4);
      a_chat_str[0]=
	"Noo! Please, don't kill me!\n";
      a_chat_str[1]=
	"Mummy! mummy! Help! Help!\n";
      a_chat_str[2]=
        "The boy is beating you furiously with his hands.\n";
      a_chat_str[3]=
        "Waaaaahhh!\n";
      elfboy->load_a_chat(70,a_chat_str);
    }
    rod=clone_object("players/topaz/angmar/fishing_rod");
    move_object(rod,elfboy);

    move_object(elfboy,this_object());
  }
}

fish() {
  object box;
  if(boxhere) {
    box=clone_object("players/topaz/angmar/box");
    move_object(box,this_object());
    write("You got something!\n");
    boxhere=0;
    return 1;
  }

  if(fishhere) {
    object fish;
    fish=clone_object("obj/food");
    fish->set_id("fish");
    fish->set_short("A dead fish");
    fish->set_long("Fresh fish should be good to eat.\n");
    fish->set_alias("fish");
    fish->set_alt_name("dead fish");
    fish->set_value(1);
    fish->set_strength(5);
    fish->set_eater_mess("The fish is delicious!\n");
    fish->set_weight(1);
    move_object(fish,this_object());
    write("You got something!\n");
    fishhere=0;
    return 1;
  }

  write("No luck today.\n");
  return 1;
}
