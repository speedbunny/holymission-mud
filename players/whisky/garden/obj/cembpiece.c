inherit "obj/thing";


reset(arg) 
{

    if ( arg==1 && !objectp(environment(environment()))) 
    {
         destruct(this_object());
         return;
    }
  
  if (!arg) 
  {
     set_name("piece");
     set_alias("piece of cembalo");
     set_short("Piece of a cembalo");
     set_long("This is the wretched remain of a former beautiful cembalo.\n"+
              "It looks like it has a high value.\n");
     set_value(80);
     set_can_get(1);
  }
}
