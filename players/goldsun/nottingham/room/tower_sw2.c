inherit "//players/goldsun/nottingham/room/genTower2";

reset(arg){
 if (!arg){
 short_desc=("Southwest guard tower");
 dest_dir=({ "/players/goldsun/nottingham/room/tower_sw","down"});
 }
 ::reset(arg);
 replace_program("room/room");
}

