inherit "obj/treasure";
  
  reset(arg) {
    
  if (arg) return;
  
  set_id("_skull_key_");
  set_name( "skull key" );
  set_alias("key");
  set_short("A key");
  set_long("A key, formed in the shape of a skull.\n");
}
