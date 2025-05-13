inherit "/obj/treasure";
 
reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("white rose");
     set_alias("rose");
     set_short("A soft white rose");
     set_long("A soft white rose grown in the royal gardens of Denmark.  They are a \n"+
                    "favorite of the fair Ophelia.\n");
     set_value(20);
     set_weight(1);
  }
}
