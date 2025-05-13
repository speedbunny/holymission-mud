/* POOL.C - Programmed by Jake */
/* 280693: Ethereal Cashimor: Alignment too high, modified */

inherit "room/room";

#include "/obj/lw.h"

object smurf,bikini;

reset (arg) {
  if(!smurf) {
    smurf=clone_object("obj/monster");
    smurf->set_name("smurfette");
    smurf->set_short("smurfette");
    smurf->set_alias("smurf");
    smurf->set_gender(2);
    smurf->set_size(1);
    smurf->set_long(lw("This is smurfette. She is a beautiful blue female "
                  + "smurf.\n"));
    smurf->set_level(5);
    smurf->set_align(1000);
    smurf->set_aggressive(0);
    smurf->add_money(100);
    bikini=clone_object("obj/armour");
    bikini->set_id("bikini");
    bikini->set_size(1);
    bikini->set_short("bikini");
    bikini->set_long("Smurfettes skimpy white bikini.\n");
    bikini->set_value(100);
    bikini->set_weight(1);
    move_object(bikini,smurf);
    smurf->init_command("wear bikini"); 
    move_object(smurf,this_object());
  }
  if(arg) return;
  set_light(3);
  short_desc="pool";
  long_desc="You have entered the area of the village pool. It appears "
          + "unoccupied@@smurfette@@.\n";
  items=({"pool","The village swimming pool"});
  dest_dir=({"players/jake/newbie/smurf2","north"});
  smell="A soft fresh breeze blows here.";
}

smurfette() {
  if(present("smurfette",this_object())) return ", except for the smurfette "
                                              + "who is sunning";
  return "";
}
