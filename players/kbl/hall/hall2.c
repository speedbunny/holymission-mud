inherit "/players/kbl/cpower/cry_node";

reset(arg)
{
  ::reset(arg);
  if(!arg)
   set_up();
}

set_up()
{
  set_light(1);
  set_name("Wizards private access hall");
  set_long("Alot of power swirls around you and it feels so wonderful.\n"+
           "Its very peaceful here. Only the low melodic hum of the energy\n"+
           "can be felt here.\n");
  node_dest = ({
                "SHOP","/players/kbl/deshop",
                "CHUR","/players/kbl/dechur",
                "CORE","/players/kbl/cpower/core",
                "HALL","/players/kbl/hall/hall1",
               });
  set_density(10);
  set_access(10);
  set_conn(2);
  set_type(4);
}

init()
{
  ::init();
}
