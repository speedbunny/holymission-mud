inherit "//players/goldsun/nottingham/room/genTower2";

reset(arg){
 if (!arg){
 short_desc=("Northwest guard tower");
 dest_dir=({ "/players/goldsun/nottingham/room/tower_nw","down"});
 }
 ::reset(arg);
 replace_program("room/room");
}

