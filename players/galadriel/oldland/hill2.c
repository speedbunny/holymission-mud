inherit "room/room";

#include "/players/skeeve/area.h";

reset(arg) {
  if (!arg) {
    set_light(1);
    short_desc = "Hill";
    long_desc = "A high mountain. An eagle is living here.\n"; 
    dest_dir =  ({
        LAND + "hillside2", "down"
    });
  }
  create_eagle();
}

create_eagle()  {
  object eagle;
   if (!present("eagle")) {
     eagle=clone_object("obj/monster");
     eagle->set_name("eagle");
     eagle->set_short("An eagle");
     eagle->set_long("The eagle glares at you. She is sitting in her nest and is breeding.\n"
                   + "Maybe you should leave him alone.\n");
     eagle->set_race("bird");
     eagle->set_female();
     eagle->set_level(25);
     eagle->set_size(3);
     eagle->set_dex(40);
     eagle->set_al(200);
     eagle->set_sp(0);
     eagle->set_wc(18);
     eagle->set_ac(8);
     eagle->set_aggressive(0);
     eagle->set_no_steal();
     eagle->wimpy(-1);
     
     transfer(clone_object(OBJECTS+"egg"),eagle);
     
     transfer(eagle,this_object());
   }
}
