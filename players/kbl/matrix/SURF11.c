/* Blue White Sapphire Surface layer of Matrix Crystal
    SURF10
*/

inherit "/players/kbl/cpower/cry_node";

reset(arg)
{
  if(!arg)
   set_up();
}

set_up()
{
  set_long("Tub of bluewhite crystaline energy flows all around. There\n"+
           "is several powerlines of flux gathered around the down branch\n"+
           "of blue crystal.\n");
  set_light(1);
  set_name("Blue White Surface");
  node_dest=({
                "BRU","/players/kbl/matrix/SURF13",
                "BRD","/players/kbl/matrix/SURF5",
                "BRR","/players/kbl/matrix/SURF4",
                "BRL","/players/kbl/matrix/SURF6",
             });
  set_density(3);
  set_type(4);
  set_conn(3);
  set_access(3);
}

init()
{
  ::init();
}
