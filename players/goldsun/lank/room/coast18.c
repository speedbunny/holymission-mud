inherit "/players/goldsun/lank/room/genCoast3";
#define PPATH "/players/goldsun/lank/room/"

reset(arg){
if (!arg){
 set_light(1);
 short_desc="At the coast";
 long_desc=
    "You are standing on the coast of the island of Lank. The ground\n"
    +"consists of sand. Huge waves are rolling towards the island and \n"
    +"you get a peacefull feeling. The coast continues to the north and\n"
    +"southwest. Far to the northwest you can see tall peak of Lankbourg\n"
    +"mountains.\n";

 dest_dir=({ PPATH + "coast17" , "north",
	     PPATH + "coast19" , "southwest"
         });
 }
 ::reset(arg);
}
