/* Matrix Crystal Drow Pine tree */

inherit "/players/kbl/cpower/cry_node";

reset(arg)
{
  if(!arg)
   set_up();
}

set_up()
{
  set_light(1);
  set_name("Drow Elf Giant Pine");
  set_long("Brown swirling energy flows all around. It seems as if time\n"+
           "and space have stood still here.\n");
  node_dest=({"MATR","/players/kbl/matrix/MAIN",
              "LIBR","/players/kbl/lib/LIB1",
              "LOCK","/players/kbl/pine/lower_lock",
             });
  set_density(5);
  set_type(4);
  set_conn(3);
  set_access(3);
}

init()
{
  ::init();
}
