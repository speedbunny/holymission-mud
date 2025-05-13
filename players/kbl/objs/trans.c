/* Object sender */

inherit "/players/kbl/objs/thing";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    name = "objsender";
    short_desc = "Kbl's object sender";
    long_desc = "Syntax: WSend <object> to <wizard>\n";
    weight = 0;
    value = 5000;
    alt_name = "sender";
    alias_name = "objsender";
  }
}

init()
{
  ::init();
  add_action("send_it","WSend");
}

send_it(str)
{
  string in1,in2;
  object wiz,ob;

  if(this_player()->query_level() < 30)
   return 1;
  if(sscanf(str,"%s to %s",in1,in2) == 2)
  {
    if(wiz = find_living(in2))
      if(ob = clone_object(in1))
      {
        tell_object(wiz,"Kbl sends you a "+ob->short()+".\n");
        transfer(ob,wiz);
        return 1;
      }
  }
}
