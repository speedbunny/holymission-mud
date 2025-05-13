inherit "/players/padrone/obj/thing";

reset(arg){
 ::reset(arg);
 if (arg) return;
 set_name("sign pointing to the south");
 set_alias("sign");
 set_short("A wooden sign.\n");
 set_can_get(0);
 set_long("This is a wooden sign. There is something written on it.\n");
 set_read("Bank && Board are south from here.\n"+
	  "Fence school && Rutenos && Herp shop are east from here.\n"); 

}
  
