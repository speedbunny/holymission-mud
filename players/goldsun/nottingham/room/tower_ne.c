inherit "/players/goldsun/nottingham/room/genTower1";

reset(arg){

 if (!arg){
 set_light(1);
 short_desc=("Northeast guard tower");
 dest_dir=({ "/players/goldsun/nottingham/room/tower_ne2","up"});
 }

 ::reset(arg);
 replace_program("room/room");
}

