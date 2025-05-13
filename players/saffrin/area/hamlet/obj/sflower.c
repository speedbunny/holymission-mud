inherit "/obj/treasure";
 
reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("safflower");
     set_alias("safflower");
     set_short("A golden yellow safflower");
     set_long("A golden yellow safflower grown in the royal gardens of Denmark.  They are a \n"+
                    "favorite of Queen Gertrude.\n");
     set_value(20);
     set_weight(1);
  }
}
