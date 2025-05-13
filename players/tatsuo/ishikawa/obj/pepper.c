
inherit "/obj/treasure";

  reset(arg)
{
	::reset(arg);
	if (arg) return;
	set_name("pepper shaker");
	set_alias("pepper");
	set_alt_name("shaker");
	set_short("A pepper shaker");
	set_long("A pepper shaker.  Perhaps finding its way here from\n"+
	         "an unfortunate shipwreck.\n");
	set_value(35);
	set_weight(2);

return 1;
}
init(){
  ::init();
  add_action("sniff","smell");
}
sniff(str){
  if(str=="pepper"){
  write("You sneeze.  AAAAAAAAAAAAAAAAACHO!\n");
  say(this_player()->query_name()+" sneezes.  You are covered in mucus!\n");
  return 1;
}
else return 0;
}
