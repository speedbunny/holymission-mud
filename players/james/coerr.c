object *ob,u;

int i, j, xxx;

id(str) { return str=="coerr" || str=="util" || str=="coerr util"; }

get() { return 1; }

short() { return "Coerr util"; }

long() { write(short()+".\nShows some internals of the world.\n" +

                       "Only gods will think it useful.\n" +

                       "Use with 'coerr'\n"); }

init() { add_action("coerr","coerr"); }

coerr() {

  if (environment(this_object())!=this_player()) {

     write("You must get it first, butthead.\n");

     return 1;

  }


  ob=call_out_info();

  xxx = -1;
  for(i=0; i<(sizeof(ob)-1); i++)
    for(j=i+1; j<sizeof(ob); j++) {
      if ((ob[i][0] == ob[j][0]) && (ob[i][1] == ob[j][1])) {
        if (xxx != i) {
          write("\n");
          write("Possible error, identical call_out's\n");
          write(file_name(ob[i][0])+"   "+ob[i][1]+"   "+ob[i][2]+"\n");
          xxx = i;
        }
        write(file_name(ob[j][0])+"   "+ob[j][1]+"   "+ob[j][2]+"\n");
        ob[j][0] = j;
      }
    }

  ob = call_out_info();
  xxx = -1;
  for(i=0; i<sizeof(ob); i++)
    if (!clonep(ob[i][0]))
      for(j=0; j<sizeof(ob); j++)
        if(clonep(ob[j][0])) {
          if(strstr(file_name(ob[j][0]),file_name(ob[i][0])) != -1) {
            if (xxx != i) {
              write("\n");
              write("Master object AND clone object using call_outs\n");
              write(file_name(ob[i][0])+"   "+ob[i][1]+"   "+ob[i][2]+"\n");
              xxx = i;
            }
            write(file_name(ob[j][0])+"   "+ob[j][1]+"   "+ob[j][2]+"\n");
          }
        }

  return 1;

}
