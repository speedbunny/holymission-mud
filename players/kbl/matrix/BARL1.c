/*
*/

inherit "/players/kbl/cpower/cry_node";

reset(arg)
{
  if(!arg)
   set_up();
}

set_up()
{
  set_light(1);
  set_name();
  set_long();
  node_dest=({
             });
  set_density(3);
  set_type(4);
  set_conn(3);
  set_access(4);
}

init()
{
  ::init();
}
