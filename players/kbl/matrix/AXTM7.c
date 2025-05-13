/*
  Axtiom layer connection node to Surface or Starlite layer
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
  set_name("Axtiom layer on a remote standalone node");
  set_long("Highest density and access in the Axtiom layer. The walls\n"+
            "seems to flux with high intensity light and energy waves.\n");
  node_dest=({
                "SURF","/players/kbl/matrix/SURF5",
                "STAR","/players/kbl/matrix/STAR9",
             });
  set_density(8);
  set_type(3);
  set_conn(2);
  set_access(10);
}

init()
{
  ::init();
}
