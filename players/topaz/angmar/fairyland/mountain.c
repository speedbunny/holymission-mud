/* 12.13.93 Airborne: Changed to room/room */

#include "/players/topaz/angmar/door.h"

inherit "room/room";
object obj_1,obj_2;

reset(arg) {
  set_light(1);
  short_desc = "Misty Mountain";
  long_desc =
	"You are climbing misty mountain.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/mountain_top","up",
           "players/topaz/angmar/fairyland/mountain_foot","down",
           "players/topaz/angmar/fairyland/rock_ledge","east" });

  call_other("players/topaz/angmar/fairyland/inn","external_reset",0);
  if(arg) {
    call_other(obj_1,"set_closed",1);
    call_other(obj_1,"set_locked",1);
    call_other(obj_1,"set_both_status",0);
    return;
  }
      
  MAKE_DOORS("players/topaz/angmar/fairyland/mountain","north","players/topaz/angmar/fairyland/tunnel","south","big","auxd","A heavy door made of stone.\n",1,1,1)

}

opendoors() {
  call_other(obj_1,"set_locked",0);
  call_other(obj_1,"set_closed",0);
  call_other(obj_2,"set_locked",0);
  call_other(obj_2,"set_closed",0);
  call_other(obj_1,"set_both_status",0);
}

