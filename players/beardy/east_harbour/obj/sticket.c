inherit "obj/treasure";

reset(arg)
{ ::reset(arg);
  if(!arg)
  {
    set_name("single ticket");
    set_alt_name("ticket");

    
    set_short("single ticket");
    set_long("It's a port ticket.\n"+
             "Now you only have to find a boat at the piers\n" +
             "and can 'rent' a boat to an 'destination'.\n"+
             "The right syntax is :\n\n"+
             "rent boat to 'dest'\n\n"+
             "Destinations are : castle Walhalla (walhalla)\n"+
             "                   sea shore       (shore)\n"+
             "                   dragon island   (island)\n"+
             "                   central town    (town)\n"+
             "            NEW :  isle of Magi    (magi)\n"+
             "            NEW :  ezo island      (ezo)\n");

    set_value(100);
    set_weight(1);   
  }
}
