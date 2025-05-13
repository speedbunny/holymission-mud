inherit "obj/weapon";

reset(arg){
 ::reset(arg);
 if (arg) return;
 set_name("bat");
 set_short("Cal Ripken's Baseball Bat");
 set_long("This is the most perfectly made baseball bat ever.  The end \n"+
          "has ben blackened, and there are dents in it from smashing \n"+
          "baseballs for home runs.  The handle has been autographed by \n"+
          "Cal Ripken, Jr. \n");
 set_value(20000);
 set_weight(5);
 set_type(1);
 set_class(20);
}

