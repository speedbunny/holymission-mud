

inherit "/obj/thing";

 reset(arg)
 {
     ::reset(arg);
     if (!arg)
     {
      set_name("finder");
      set_short("finder");
      set_long("usage: findo objectname or filename.\n");
     }
  }



init()
{
  add_action("get_object","findo");
 ::init();
}

static nomask int 
get_object(string arg)
{
 object *u, *inv;
 int i,j,k,l;
 string path, *plode;

  u = users();
  k =sizeof(u);
  
  if (!stringp(arg)) return 0; 

  for (i=0;i< k; i++)
  {
    inv = all_inventory(u[i]);
    l = sizeof(inv);

        for (j=0;j<l;j++)
        {
          plode = explode(file_name(inv[j]),"#");
          path = to_string(plode[0]);

          if (path == arg || inv[j]->query_name()==arg )  /* bug in present */
          {
              write(file_name(inv[j]) +
                   " found in: "+u[i]->capitalize(query_real_name())+"\n");
           }
             
        } /* endfor */
    } /* endfor */
  return 1;
}
    
    
 
