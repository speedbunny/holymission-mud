inherit "obj/treasure";
reset(arg){
 if (arg) return;
 set_id("moon");
 set_short("A moon");
 set_alias("orb");
   set_long("A amulet in the shape of a moon.\n"+
            "The light shining from it seems to change ever time.\n"+
     "Maybe you should touch it to find out how it works.\n");
 set_value(1000);
 set_light(2);
} 
init(){
 ::init();
 add_action("sun","sun");
 add_action("night","night");
 add_action("moon","moon");
 add_action("lok", "touch");

}
sun(){
 set_light(5);
 return 1;
}
night(){
 set_light(-10);
 return 1;
} 
moon(){
 set_light(2);
 return 1;
 }
lok(){
 write("You can set the light to: sun, moon, night \n");
 return 1;
 }
