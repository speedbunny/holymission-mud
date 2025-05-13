/* Blue White Sapphire Surface layer of Matrix Crystal
    SURF6
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
  set_name("Blue White Surface");
  set_long("Blue energy flows past you in all forms and colour variations\n"+
           "of blue. Seems to be denser here than other surface places.\n");
  node_dest=({
               "BRRU","/players/kbl/matrix/SURF13",
               "BRR","/players/kbl/matrix/SURF11",
               "BRU","/players/kbl/matrix/SURF12",
             });
  set_density(4);
  set_type(4);
  set_conn(3);
  set_access(4);
}

init()
{
  ::init();
}
