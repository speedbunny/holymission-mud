inherit "/players/whisky/obj/std_shadow";

int catch_tell(string str) {

  string blah, blah1;
  object prevobj;

  if(  sscanf(str,"%s shouts: %s",blah,blah1)  ==2 ||
       sscanf(str,"%s tells %s",blah,blah1)    ==2 ||
       sscanf(str,"%s bellows %s",blah,blah1)  ==2 ||
       sscanf(str,"%s bellowing %s",blah,blah1)==2 ||
       sscanf(str,"%s bawls: %s",blah,blah1)   ==2) {
    prevobj = this_interactive();
    if(!prevobj) prevobj = previous_object();
    write("***The previous object was ");
    write(prevobj);
    if(prevobj)
      write(" with real name " + prevobj->query_real_name() + "\n");
//    write("***Also the short is " + prevobj->query_short() + "\n");
    write(str);
    return 1;
  }
  write(str);
  return 1;
}

int catch_shad()
{
    return 1;
}

object catch_object()
{
     return this_object();
}

