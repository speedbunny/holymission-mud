inherit "/players/goldsun/lank/room/genCoast3";
#define PPATH "/players/goldsun/lank/room/"

reset(arg){
if (!arg){
 set_light(1);

 short_desc="At the coast";

 long_desc=
    "You are standing on the coast of the island of Lank. The ground\n"
    +"consists of sand. Huge waves are rolling towards the island from west\n"
    +"and east and you get a peacefull feeling. Far to the northwest\n"
    +"you can see tall peak of Lankbourg mountains.\n";

 dest_dir=({ PPATH + "coast16" , "north",
	     PPATH + "coast18" , "south"
         });
 }
 ::reset();
}

