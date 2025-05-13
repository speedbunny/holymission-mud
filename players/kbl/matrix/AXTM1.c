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
  set_name("Axtiom power layer");
  set_long("Red power flows rapidly chaotically here. Several vortexs of\n"+
            "energy streams can get seem, but hard to focus on.\n");
  node_dest=({
              "SURF","/players/kbl/matrix/SURF1",
              "BARL","/players/kbl/matrix/BARL1",
              "BRNHL","/players/kbl/matrix/AXTM2",
              "BRNHR","/players/kbl/matrix/AXTM12",
             });
  set_density(8);
  set_type(2);
  set_conn(4);
  set_access(9);
}

init()
{
  ::init();
}
