inherit "/players/goldsun/nottingham/room/genTower1";

reset(arg){

 if (!arg){
 set_light(1);
 short_desc=("Southwest guard tower");
 dest_dir=({ "/players/goldsun/nottingham/room/tower_sw2","up"});
 }

 ::reset(arg);
 replace_program("room/room");
}

