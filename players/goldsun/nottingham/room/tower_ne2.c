inherit "//players/goldsun/nottingham/room/genTower2";

reset(arg){
 if (!arg){
 short_desc=("Northeast guard tower");
 dest_dir=({ "/players/goldsun/nottingham/room/tower_ne","down"});
 }
 ::reset(arg);
 replace_program("room/room");
}

