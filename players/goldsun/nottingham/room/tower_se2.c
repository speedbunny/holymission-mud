inherit "//players/goldsun/nottingham/room/genTower2";

reset(arg){
 if (!arg){
 short_desc=("Southeast guard tower");
 dest_dir=({ "/players/goldsun/nottingham/room/tower_se","down"});
 }
 ::reset(arg);
 replace_program("room/room");
}

