inherit "/obj/treasure";
reset(arg){
  if (arg)return;
  set_id("bone");
  set_short("A shattered bone");
  set_long("A shattered bone shard.  It looks fairly worthless.\n");
  set_value(2);
  set_weight(1);
}
