inherit "/players/goldsun/lank/room/genCoast3";
#define PPATH "/players/goldsun/lank/room/"

reset(arg){
if (!arg){
 set_light(1);
 short_desc="At the coast";
 long_desc=
    "You are standing on the coast of the island of Lank. The ground\n"
    +"consists of sand. Huge waves are rolling towards the island and \n"
    +"you get a peacefull feeling. The coast continues to the northeast.\n"
    +"To the southwest you can see dense forest. Far to the northwest\n"
    +"you can see tall peak of Lankbourg mountains.\n";

  dest_dir=({ PPATH + "coast18" , "northeast",
	     PPATH + "forest5" , "southwest"
            });
  }
 ::reset();
}

init(){
 ::init();
add_action("sw","southwest");
}

sw(){
 "/players/goldsun/lank/room/forest5"->add_exit("northeast");
 return ::move("southwest");
}
