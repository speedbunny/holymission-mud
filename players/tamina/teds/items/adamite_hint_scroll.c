inherit "obj/treasure";
	
void reset(int arg) 
{
  if(arg) return 0;

  set_id("Ornate Scroll");
  set_alias("scroll");
  set_short("An Ornate Scroll");
  set_long("This scroll seems to have something written on it.\n");
  set_read("Written in cramped script are the words:\n\n"+
           "What can be felt in the light of reason\n"+
           "will be no more in the dark of delusion.\n");
  set_weight(2);
  set_value(10);
}
