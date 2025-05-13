/* Kbl's Home Matrix node */

inherit "/players/kbl/cpower/cry_node";

reset(arg)
{
  if(!arg)
   set_up();
}

set_up()
{
  set_light(1);
  set_name("Kbl's Home Node");
  node_dest=({"SURF","/players/kbl/matrix/SURF1",
              "LIBR","/players/kbl/lib/LIB1",
              "DROW","/players/kbl/pine/DROW",
              "CORE","/players/kbl/cpower/core",
             });
  set_density(5);
  set_type(2);
  set_conn(3);
  set_access(3);
  set_long("\tThis @@place@@ is entirely saturated with swirling energy.\n"+
           "\tYou seem to float in a ocean of rainbowing energies that\n"+
           "\tflow with dancing images of things you cannot comprehend.\n"+
           "\tYou wonder how your eyes can \"see\" these things!\n");
}

init()
{
  ::init();
}

place()
{
  return "drain area";
}
